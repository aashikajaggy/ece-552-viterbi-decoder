`timescale 1ns/1ps
module tb_viterbi;
    parameter integer W=16;
    localparam integer INF=(1<<W)-1;
    reg clk=0;
    always #5 clk=~clk;
    reg rst=1, init=0, start=0;
    reg [4:0] initial_state=0;
    reg [1:0] received=0;
    reg [127:0] output_table=0;
    wire busy,done,metric_overflow;
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
    task automatic check_initial(input integer s);
        integer j;
        begin
            if(busy || done || metric_overflow || survivors!==0) $fatal(1,"initial control");
            for(j=0;j<32;j=j+1)
                if(metrics[j*W +: W] !== W'((j==s)?0:INF)) $fatal(1,"initial metric");
            reset_model(s);
        end
    endtask
    task automatic initialize_frame(input integer s);
        begin
            @(negedge clk); init=1; start=1; initial_state=5'(s);
            @(posedge clk); #1; check_initial(s); // init wins over start
            @(negedge clk); init=0; start=0;
        end
    endtask
    task automatic step(input reg [1:0] symbol, input reg [127:0] tab);
        integer j,k,src,bit_in,dst,encoded,distance_value,cost;
        reg [32*W-1:0] previous_metrics;
        reg [31:0] previous_survivors;
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
            previous_metrics=metrics; previous_survivors=survivors;
            @(negedge clk); received=symbol; output_table=tab; start=1;
            @(posedge clk); #1;
            if(!busy || done) $fatal(1,"request acceptance");
            for(k=1;k<=9;k=k+1) begin
                @(negedge clk);
                // Busy requests/init ignored, input bus changes must not alter latched request.
                start=(k==3); init=(k==4); received=~symbol; output_table=~tab;
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
                    if(metric_overflow!==expected_overflow) $fatal(1,"overflow mismatch");
                end
            end
            steps=steps+1;
        end
    endtask
    initial begin
        repeat(2) @(posedge clk);
        #1; check_initial(0);
        @(negedge clk); rst=0;
        // Example polynomials only: register vector {input,state}, masks octal 53,75.
        for(u=0;u<2;u=u+1) for(p=0;p<32;p=p+1) begin
            test_table[2*(u*32+p)]   = ^(6'((u<<5)|p) & 6'o53);
            test_table[2*(u*32+p)+1] = ^(6'((u<<5)|p) & 6'o75);
        end
        for(n=0;n<128;n=n+1) step(2'(random_word()),test_table);
        initialize_frame(17);
        for(n=0;n<100;n=n+1) begin
            test_table={random_word(),random_word(),random_word(),random_word()};
            step(2'(random_word()),test_table);
        end
        // All branches equal: ties and a guaranteed saturation stress sequence.
        initialize_frame(0);
        for(n=0;n<40;n=n+1) step(2'b11,128'b0);
        if(W==3 && !metric_overflow) $fatal(1,"overflow test did not reach saturation");
        // Reset during compute aborts the in-flight symbol.
        @(negedge clk); start=1;
        @(negedge clk); start=0;
        repeat(3) @(negedge clk);
        rst=1;
        @(posedge clk); #1; check_initial(0);
        @(negedge clk); rst=0;
        step(0,0);
        @(posedge clk); #1;
        if(done || busy) $fatal(1,"done must pulse for one cycle");
        $display("PASS accelerator W=%0d: %0d columns, all metrics/survivors and timing",W,steps);
        $finish;
    end
    initial begin #100000; $fatal(1,"timeout"); end
endmodule
