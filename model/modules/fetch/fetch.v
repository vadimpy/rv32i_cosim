// fetch.v

module fetch (
    input wire         clk,
    input wire  [31:0] pc_ex_off,
    input wire  [31:0] pc_ex_base,
    input wire         pc_ex_valid,
    input wire  [31:0] mem_data,
    input wire         ex_stall,
    output wire [29:0] mem_addr,
    output wire [31:0] insn,
    output wire [31:0] pc_de
);

reg [31:0] pc;
reg [31:0] pc_prev;
reg [31:0] prev_insn;

assign mem_addr = pc[31:2];
assign insn = mem_data;
assign pc_de = pc;

always @(posedge clk) begin
    /*
    $display("stall %b", ex_stall);
    $display("insn %h", insn);
    $display("mem_data %h", mem_data);
    $display("pc_prev %h", pc_prev);
    $display("pc_de %h", pc_de);
    $display("\n");
    */
    // pc_de <= pc;
    if (ex_stall === 1'b0) begin
        // forced_fetch <= 0;
        // $display("fetch insn: %h", mem_data);
        
        // prev_insn <= insn;
        // pc_prev <= pc;
        //pc_de <= pc_prev;
        // insn <= mem_data;
        // pc_de <= pc;

        if (pc_ex_valid === 1'b1) begin
            pc <= pc_ex_base + pc_ex_off;
        end
        else begin
            // $display("next");
//            if (~forced_fetch)
            pc <= pc + 4;
        end
    end
    // else begin
    //     forced_fetch <= 1;
    //     //pc <= pc - 4;
    // end
end

endmodule
