`timescale 1ns/1ps
`default_nettype none
// Two register banks. Committed column remains stable throughout computation.
module viterbi_metric_store #(parameter integer W=16)(
    input wire clk, rst, initialize, compute, commit,
    input wire [32*W-1:0] initial_metrics,
    input wire [2:0] group_index,
    input wire [4*W-1:0] next_metrics,
    input wire [3:0] next_survivors,
    output wire [32*W-1:0] metrics,
    output reg [31:0] survivors
);
    localparam [W-1:0] INF = {W{1'b1}};
    reg [W-1:0] current [0:31];
    reg [W-1:0] pending [0:31];
    reg [31:0] pending_survivors;
    integer i;
    genvar s;
    generate for(s=0;s<32;s=s+1) begin: pack
        assign metrics[s*W +: W] = current[s];
    end endgenerate
    always @(posedge clk) begin
        if (rst || initialize) begin
            for (i=0;i<32;i=i+1) begin
                // Reset does not assume a starting encoder state.
                current[i] <= rst ? INF : initial_metrics[i*W +: W];
                pending[i] <= INF;
            end
            survivors <= 0;
            pending_survivors <= 0;
        end else begin
            if (compute) begin
                for(i=0;i<4;i=i+1) begin
                    pending[4*group_index+i] <= next_metrics[i*W +: W];
                    pending_survivors[4*group_index+i] <= next_survivors[i];
                end
            end
            if (commit) begin
                for(i=0;i<32;i=i+1) current[i] <= pending[i];
                survivors <= pending_survivors;
            end
        end
    end
endmodule
`default_nettype wire
