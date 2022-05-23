module top(
  input            clk,  
  input            rst_n,
  output reg [7:0] count
);

initial begin
  count = 8'b0;
end

always @(posedge clk) begin
  count <= count + 1'b1;
end
endmodule
