`timescale 1ns/1ps
module tb_acs;
    reg [2:0] metric_a,metric_b;
    reg [1:0] expected_a,expected_b,received;
    wire [2:0] new_metric;
    wire survivor,overflow;
    integer a,b,ea,eb,r,ca,cb,chosen,dist_a,dist_b,count=0;
    viterbi_acs #(.W(3)) dut(.*);
    initial begin
        for(a=0;a<8;a=a+1) for(b=0;b<8;b=b+1)
        for(ea=0;ea<4;ea=ea+1) for(eb=0;eb<4;eb=eb+1)
        for(r=0;r<4;r=r+1) begin
            metric_a=3'(a); metric_b=3'(b);
            expected_a=2'(ea); expected_b=2'(eb); received=2'(r);
            dist_a=((ea&1)!=(r&1))+(((ea>>1)&1)!=((r>>1)&1));
            dist_b=((eb&1)!=(r&1))+(((eb>>1)&1)!=((r>>1)&1));
            ca=(a==7)?100:a+dist_a; cb=(b==7)?100:b+dist_b;
            chosen=(cb<ca)?cb:ca;
            #1;
            if(new_metric!==3'((chosen>=7)?7:chosen) || survivor!==(cb<ca)
               || overflow!==((chosen!=100)&&(chosen>=7))) $fatal(1,"ACS mismatch");
            count=count+1;
        end
        $display("PASS ACS: %0d exhaustive cases",count); $finish;
    end
endmodule
