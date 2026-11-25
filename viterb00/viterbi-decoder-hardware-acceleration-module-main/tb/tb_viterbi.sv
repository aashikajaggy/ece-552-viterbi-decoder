`timescale 1ns/1ps
module tb_viterbi;
    parameter integer W=16;
    localparam integer INF=(1<<W)-1;
    reg clk=0;
    always #5 clk=~clk;
    reg rst=1, load_context=0, start=0;
    reg [32*W-1:0] initial_metrics=0;
    reg [1:0] received=0;
    reg [127:0] output_table=0;
    wire busy,done,metric_overflow,configured;
    wire [32*W-1:0] metrics;
    wire [31:0] survivors;
    integer model[0:31], best[0:31];
    reg [31:0] expected_survivors;
    reg expected_overflow;
    integer steps=0;
    reg [31:0] rng=32'h01234567;
    reg [127:0] test_table;
    integer n,p,u,x;
    viterbi_accelerator #(.METRIC_WIDTH(W)) dut(.*);

    // Optional observation only: +TRACE=N records the first N requests.
    // Sample ACS inputs/results before the active edge updates pending storage.
    integer trace_limit=0, trace_request=0, trace_fd=0, commit_fd=0;
    integer tl, ts, ta, tbp, tea, teb, tma, tmb, tda, tdb, tc;
    initial begin
        if ($value$plusargs("TRACE=%d",trace_limit) && trace_limit>0) begin
            trace_fd=$fopen("build/acs_trace.csv","w");
            commit_fd=$fopen("build/commits.csv","w");
            if(!trace_fd || !commit_fd) $fatal(1,"Cannot open trace files; create build/ first");
            $fdisplay(trace_fd,"request,cycle,lane,state,received,pred_a,pred_b,expected_a,expected_b,metric_a,metric_b,distance_a,distance_b,new_metric,survivor,infinity");
            $fdisplay(commit_fd,"request,state,metric,survivor");
        end
        if ($test$plusargs("WAVES")) begin
            $dumpfile("build/viterbi.vcd");
            $dumpvars(0,tb_viterbi);
        end
    end
    always @(posedge clk) begin
        if(!rst) begin
            if(dut.accept) trace_request=trace_request+1;
            if(trace_fd && trace_request>0 && trace_request<=trace_limit) begin
                if(dut.compute) begin
                    $display("TRACE request %0d compute %0d: states %0d-%0d",trace_request,
                             int'(dut.group_index)+1,4*int'(dut.group_index),4*int'(dut.group_index)+3);
                    for(tl=0;tl<4;tl=tl+1) begin
                        ts=4*int'(dut.group_index)+tl;
                        ta=(ts&15)*2; tbp=ta+1;
                        tea=int'(dut.table_q[2*(32*(ts>>4)+ta) +: 2]);
                        teb=int'(dut.table_q[2*(32*(ts>>4)+tbp) +: 2]);
                        tma=int'(metrics[ta*W +: W]); tmb=int'(metrics[tbp*W +: W]);
                        tc=tea ^ int'(dut.symbol_q); tda=(tc&1)+((tc>>1)&1);
                        tc=teb ^ int'(dut.symbol_q); tdb=(tc&1)+((tc>>1)&1);
                        $fdisplay(trace_fd,"%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d",
                            trace_request,int'(dut.group_index)+1,tl,ts,dut.symbol_q,ta,tbp,tea,teb,
                            tma,tmb,tda,tdb,dut.next_metrics[tl*W +: W],dut.decisions[tl],INF);
                    end
                end
                if(dut.commit) begin
                    // Wait for nonblocking assignments: these are published DUT results.
                    #2;
                    for(ts=0;ts<32;ts=ts+1)
                        $fdisplay(commit_fd,"%0d,%0d,%0d,%0d",trace_request,ts,metrics[ts*W +: W],survivors[ts]);
                    $display("TRACE request %0d COMMIT: all 32 metrics published; done=%b",trace_request,done);
                end
            end
        end
    end

    function automatic [31:0] random_word();
        begin
            rng=rng ^ (rng<<13); rng=rng ^ (rng>>17); rng=rng ^ (rng<<5);
            random_word=rng;
        end
    endfunction
    task automatic reset_model(input integer s);
        integer j;
        begin
            for(j=0;j<32;j=j+1) model[j]=(j==s)?0:INF;
            expected_overflow=0;
        end
    endtask
    task automatic check_reset();
        integer j;
        begin
            if(busy || done || configured || metric_overflow || survivors!==0)
                $fatal(1,"reset control");
            for(j=0;j<32;j=j+1)
                if(metrics[j*W +: W] !== W'(INF)) $fatal(1,"reset metric");
        end
    endtask
    // Software/driver presents a packed column and table; hardware copies both.
    task automatic load_model(input reg [127:0] tab);
        integer j;
        begin
            @(negedge clk);
            for(j=0;j<32;j=j+1) initial_metrics[j*W +: W]=W'(model[j]);
            output_table=tab; load_context=1; start=1;
            @(posedge clk); #1;
            if(busy || done || !configured || metric_overflow || survivors!==0)
                $fatal(1,"context load priority/control");
            for(j=0;j<32;j=j+1)
                if(metrics[j*W +: W] !== W'(model[j])) $fatal(1,"loaded metric %0d",j);
            if(dut.table_q !== tab) $fatal(1,"loaded table");
            expected_overflow=0;
            @(negedge clk); load_context=0; start=0;
            initial_metrics='1; output_table=~tab;
        end
    endtask
    task automatic reference_step(input reg [1:0] symbol, input reg [127:0] tab);
        integer j,src,bit_in,dst,encoded,distance_value,cost;
        begin
            // Independent forward traversal of all 64 edges (RTL uses predecessors).
            for(j=0;j<32;j=j+1) best[j]=1000000000;
            expected_survivors=0;
            for(src=0;src<32;src=src+1) begin
                for(bit_in=0;bit_in<2;bit_in=bit_in+1) begin
                    dst=(src>>1) | (bit_in<<4);
                    encoded=(tab >> (2*(32*bit_in+src))) & 3;
                    x=encoded ^ int'(symbol);
                    distance_value=(x&1)+((x>>1)&1);
                    cost=(model[src]==INF)?1000000000:model[src]+distance_value;
                    if(cost<best[dst]) begin
                        best[dst]=cost;
                        expected_survivors[dst]=1'(src&1);
                    end
                end
            end
            for(j=0;j<32;j=j+1) begin
                if(best[j]>=INF && best[j]!=1000000000) expected_overflow=1;
                model[j]=(best[j]>=INF)?INF:best[j];
            end
        end
    endtask
    task automatic step(input reg [1:0] symbol, input reg [127:0] tab);
        integer j,k;
        reg [32*W-1:0] previous_metrics;
        reg [31:0] previous_survivors;
        begin
            reference_step(symbol,tab);
            previous_metrics=metrics; previous_survivors=survivors;
            @(negedge clk); received=symbol; output_table=~tab; start=1;
            @(posedge clk); #1;
            if(!busy || done) $fatal(1,"request acceptance");
            for(k=1;k<=9;k=k+1) begin
                @(negedge clk);
                // Busy requests/loads ignored; context and symbol are already latched.
                start=(k==3); load_context=(k==4); received=~symbol; output_table=~tab;
                initial_metrics=0;
                @(posedge clk); #1;
                if(k<9) begin
                    if(!busy || done) $fatal(1,"early completion at %0d",k);
                    if(metrics!==previous_metrics || survivors!==previous_survivors)
                        $fatal(1,"partial results exposed");
                end else begin
                    if(busy || !done) $fatal(1,"expected completion at cycle 9");
                    for(j=0;j<32;j=j+1)
                        if(metrics[j*W +: W] !== W'(model[j]))
                            $fatal(1,"step %0d state %0d got %0d expected %0d",steps,j,metrics[j*W +: W],model[j]);
                    if(survivors!==expected_survivors) $fatal(1,"survivor mismatch");
                    if(!configured || dut.table_q !== tab) $fatal(1,"context corrupted");
                    if(metric_overflow!==expected_overflow) $fatal(1,"overflow mismatch");
                end
            end
            steps=steps+1;
        end
    endtask
    initial begin
        repeat(2) @(posedge clk);
        #1; check_reset();
        @(negedge clk); rst=0; start=1;
        repeat(2) begin @(posedge clk); #1; check_reset(); end
        @(negedge clk); start=0;
        // Example polynomials only: register vector {input,state}, masks octal 53,75.
        for(u=0;u<2;u=u+1) for(p=0;p<32;p=p+1) begin
            test_table[2*(u*32+p)]   = ^(6'((u<<5)|p) & 6'o53);
            test_table[2*(u*32+p)+1] = ^(6'((u<<5)|p) & 6'o75);
        end
        // Software warm-up: only the reference processes the first K-1 symbols.
        reset_model(0);
        if(W>=4) begin
            for(n=0;n<5;n=n+1) reference_step(2'(n*3+1),test_table);
            if(expected_overflow) $fatal(1,"software warm-up overflow");
        end
        load_model(test_table);
        for(n=0;n<128;n=n+1) step(2'(random_word()),test_table);
        // Arbitrary imported columns exercise packing, INF, and near-overflow values.
        for(n=0;n<100;n=n+1) begin
            test_table={random_word(),random_word(),random_word(),random_word()};
            for(p=0;p<32;p=p+1) model[p]=int'(random_word() & 32'(INF));
            load_model(test_table);
            step(2'(random_word()),test_table);
        end
        // All branches equal: ties and a guaranteed saturation stress sequence.
        reset_model(0);
        load_model(0);
        for(n=0;n<40;n=n+1) step(2'b11,128'b0);
        if(W==3 && !metric_overflow) $fatal(1,"overflow test did not reach saturation");
        // Reset during compute aborts the in-flight symbol.
        @(negedge clk); start=1;
        @(negedge clk); start=0;
        repeat(3) @(negedge clk);
        rst=1;
        @(posedge clk); #1; check_reset();
        @(negedge clk); rst=0;
        reset_model(0);
        load_model(0);
        step(0,0);
        @(posedge clk); #1;
        if(done || busy) $fatal(1,"done must pulse for one cycle");
        $display("PASS accelerator W=%0d: %0d columns, all metrics/survivors and timing",W,steps);
        $finish;
    end
    initial begin #100000; $fatal(1,"timeout"); end
endmodule
