

module TempCache(Rst, Clk, Addr, In, Out, WEn);
	input wire	Rst;
	input wire	Clk;
	input wire[31:0]	Addr;
	input wire[31:0]	In;
	input wire	WEn;
	output reg[31:0]	Out;

	reg[31:0]	Mem[255:0];

	initial $readmemb("test/mem.txt", Mem);

	always @(negedge Rst or posedge Clk) begin
		if (Rst == 1'b0) begin
			Out <= 32'b0;
		end else begin
			Out <= Mem[Addr[9:2]];
		end
	end
endmodule
