

module MM(Rst, Clk, MM_ALUOut, MM_RtVal, MM_MemWr, MemOut);
	input wire	Rst, Clk;
	input wire[31:0]	MM_ALUOut, MM_RtVal;
	input wire	MM_MemWr;
	output wire[31:0]	MemOut;

	TempCache DCache(Rst, Clk, MM_ALUOut, MM_RtVal, MemOut, MM_MemWr);
	
endmodule
