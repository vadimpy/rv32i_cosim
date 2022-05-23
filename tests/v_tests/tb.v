`timescale 1ns/1ns

module testbench;

reg clk;
reg rst_n;
wire [7:0] count;

top top(clk, rst_n, count);

initial begin
    clk <= 1'b0;
    rst_n <= 1'b0;
end

always #5 begin
    clk <= ~clk;
    $display(count);
    if (clk == 7'hA) begin
        $finish;
    end
end

endmodule
