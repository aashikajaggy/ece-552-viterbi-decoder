`timescale 1ns/1ps
`default_nettype none
module hamming2(input wire [1:0] a, b, output wire [1:0] distance);
    wire [1:0] difference = a ^ b;
    assign distance = {1'b0, difference[0]} + {1'b0, difference[1]};
endmodule
`default_nettype wire
