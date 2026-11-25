`timescale 1ns/1ps
`default_nettype none
module viterbi_controller(
    input wire clk, rst, load_context, configured, start,
    output wire busy, accept, initialize, compute, commit,
    output reg done,
    output reg [2:0] group_index
);
    localparam [1:0] IDLE=0, COMPUTE=1, COMMIT=2;
    reg [1:0] state;
    assign busy = (state != IDLE);
    assign initialize = !rst && !busy && load_context;
    assign accept = !rst && !busy && configured && !load_context && start;
    assign compute = (state == COMPUTE);
    assign commit = (state == COMMIT);
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            group_index <= 0;
            done <= 0;
        end else begin
            done <= 0;
            case (state)
                IDLE: if (accept) begin
                    group_index <= 0;
                    state <= COMPUTE;
                end
                COMPUTE: if (group_index == 7) state <= COMMIT;
                         else group_index <= group_index + 1'b1;
                COMMIT: begin state <= IDLE; done <= 1; end
                default: state <= IDLE;
            endcase
        end
    end
endmodule
`default_nettype wire
