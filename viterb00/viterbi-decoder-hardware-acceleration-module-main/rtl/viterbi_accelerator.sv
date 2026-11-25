`timescale 1ns/1ps
`default_nettype none
// K=6, rate 1/2, hard-decision metric-update accelerator; see README.
module viterbi_accelerator #(parameter integer METRIC_WIDTH=16)(
    input wire clk, rst,
    // Atomic context load from processor-side staging registers, while idle.
    input wire load_context,
    input wire [32*METRIC_WIDTH-1:0] initial_metrics,
    input wire start,
    input wire [1:0] received,
    input wire [127:0] output_table,
    output wire busy, done,
    output reg configured,
    output wire [32*METRIC_WIDTH-1:0] metrics,
    output wire [31:0] survivors,
    output reg metric_overflow
);
    wire accept, initialize, compute, commit;
    wire [2:0] group_index;
    reg [1:0] symbol_q;
    reg [127:0] table_q;
    wire [4*METRIC_WIDTH-1:0] next_metrics;
    wire [3:0] decisions, overflows;
    viterbi_controller ctrl(
        .clk(clk), .rst(rst), .load_context(load_context), .configured(configured), .start(start), .busy(busy),
        .accept(accept), .initialize(initialize), .compute(compute),
        .commit(commit), .done(done), .group_index(group_index));
    viterbi_metric_store #(.W(METRIC_WIDTH)) storage(
        .clk(clk), .rst(rst), .initialize(initialize), .compute(compute),
        .commit(commit), .initial_metrics(initial_metrics), .group_index(group_index),
        .next_metrics(next_metrics), .next_survivors(decisions),
        .metrics(metrics), .survivors(survivors));
    always @(posedge clk) begin
        if (rst) begin
            symbol_q <= 0;
            table_q <= 0;
            metric_overflow <= 0;
            configured <= 0;
        end else begin
            if (initialize) begin
                table_q <= output_table;
                metric_overflow <= 0;
                configured <= 1;
            end
            else if (compute && (|overflows)) metric_overflow <= 1;
            if (accept) symbol_q <= received;
        end
    end
    genvar lane;
    generate for(lane=0;lane<4;lane=lane+1) begin: acs_lanes
        localparam [1:0] LANE = lane;
        wire [4:0] destination = {group_index, LANE};
        wire [4:0] predecessor_a = {destination[3:0], 1'b0};
        wire [4:0] predecessor_b = {destination[3:0], 1'b1};
        wire [5:0] entry_a = {destination[4], predecessor_a};
        wire [5:0] entry_b = {destination[4], predecessor_b};
        viterbi_acs #(.W(METRIC_WIDTH)) acs(
            .metric_a(metrics[predecessor_a*METRIC_WIDTH +: METRIC_WIDTH]),
            .metric_b(metrics[predecessor_b*METRIC_WIDTH +: METRIC_WIDTH]),
            .expected_a(table_q[entry_a*2 +: 2]),
            .expected_b(table_q[entry_b*2 +: 2]), .received(symbol_q),
            .new_metric(next_metrics[lane*METRIC_WIDTH +: METRIC_WIDTH]),
            .survivor(decisions[lane]), .overflow(overflows[lane]));
    end endgenerate
endmodule
`default_nettype wire
