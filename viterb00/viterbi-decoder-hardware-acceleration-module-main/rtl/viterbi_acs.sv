`timescale 1ns/1ps
`default_nettype none
// W >= 2. All-ones is infinity. Ties select predecessor A.
module viterbi_acs #(parameter integer W = 16)(
    input wire [W-1:0] metric_a, metric_b,
    input wire [1:0] expected_a, expected_b, received,
    output wire [W-1:0] new_metric,
    output wire survivor, overflow
);
    localparam [W-1:0] INF = {W{1'b1}};
    wire [1:0] da, db;
    wire [W:0] sum_a, sum_b, ca, cb, chosen;
    hamming2 hd_a(expected_a, received, da);
    hamming2 hd_b(expected_b, received, db);
    assign sum_a = {1'b0, metric_a} + {{(W-1){1'b0}}, da};
    assign sum_b = {1'b0, metric_b} + {{(W-1){1'b0}}, db};
    // Infinity sorts above every finite extended sum, even overflowing ones.
    assign ca = (metric_a == INF) ? {(W+1){1'b1}} : sum_a;
    assign cb = (metric_b == INF) ? {(W+1){1'b1}} : sum_b;
    assign survivor = (cb < ca);
    assign chosen = survivor ? cb : ca;
    assign overflow = (chosen != {(W+1){1'b1}}) && (chosen >= {1'b0, INF});
    assign new_metric = (chosen >= {1'b0, INF}) ? INF : chosen[W-1:0];
endmodule
`default_nettype wire
