


module PC(Rst, Clk, PCReg, PCRegP4, PCIn);
	input wire	Rst;
	input wire	Clk;	
	input wire[31:0]	PCIn;

	output reg[31:0]	PCReg;
	output wire[31:0]	PCRegP4;

	assign PCRegP4 = PCIn + 32'h4;

	always @(negedge Rst or posedge Clk) begin
		if (Rst == 0) begin
			PCReg[31:0] <= 32'hBFC00000;
		end else begin
			PCReg[31:0] <= PCRegP4[31:0];
		end
	end
endmodule
