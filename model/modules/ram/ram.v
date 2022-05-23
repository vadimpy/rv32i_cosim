// ram.v

module ram(
    // clk
    input wire clk,

    // read 1
    input wire [29:0] r1_addr_e,
    output reg [31:0] r1_val,

    // read 2
    input wire [29:0] r2_addr_e,
    output reg [31:0] r2_val,

    // write
    input wire w_enable,
    input wire [29:0] w_addr_e,
    input wire [31:0] w_val,
    input wire [3:0] byte_en
);

reg [31:0] data [0 : 20'h10000];

wire [16:0] r1_addr;
wire [16:0] r2_addr;
wire [16:0] w_addr;

reg [16:0] last_w_addr;

initial last_w_addr = 17'b0;

assign r1_addr = r1_addr_e[16:0];
assign r2_addr = r2_addr_e[16:0];
assign w_addr  =  w_addr_e[16:0];

integer i;

// initial begin
//     $display("Loading ELF...");
//     $readmemh("/Users/vadimpy/dev/hard/rv32i_cpu/c_test/stuck.hex", data);
//     $display("ELF was loaded");
// end

// debug
// always @(posedge clk) begin
//     $display("print: %d", data[0]);
// end

// read
always @* begin
    r1_val = data[r1_addr];
    r2_val = data[r2_addr];
    // $display("read %d from %h", r1_val, r1_addr << 2);
end

// write
always @(posedge clk) begin
    if (w_enable) begin
        $display("STORE: ram[%h]=%d", w_addr, w_val);
        last_w_addr <= w_addr;
        if (byte_en[0])
            data[w_addr][7:0] <= w_val[7:0];
        if (byte_en[1])
            data[w_addr][15:8] <= w_val[15:8];
        if (byte_en[2])
            data[w_addr][23:16] <= w_val[23:16];
        if (byte_en[3])
            data[w_addr][31:24] <= w_val[31:24];
    end
end

endmodule