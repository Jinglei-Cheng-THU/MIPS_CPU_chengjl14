`include "Define.v"

/**
 *	存储器-cache接口
 */
module Memory(Rst, Clk, PAddr, Val, En);
	input wire	Rst;
	input wire	Clk;
	input wire[31:0]	PAddr;
	output reg[`CACHE_LINE_LEN - 1 : 0]	Val;
	output wire	En;
	
	reg[`CACHE_LINE_LEN - 1 : 0]	Mem[15:0];
	reg[31:0]	_PAddr;
	reg[2:0]	Delay_Counter;
	
	assign En = Delay_Counter == 2'b11;

	always @(negedge Rst or posedge Clk) begin
		if (Rst == 0) begin
			Delay_Counter = 2'b0;
		end else begin
			if (_PAddr == PAddr) begin
				Delay_Counter <= Delay_Counter + 2'b1;
			end else begin
				Delay_Counter <= 2'b0;
			end
			_PAddr <= PAddr;
		end
		
		Val <= Mem[PAddr[7:4]];
	end
endmodule
