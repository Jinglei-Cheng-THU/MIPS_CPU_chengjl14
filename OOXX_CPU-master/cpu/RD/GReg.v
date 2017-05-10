/**
 * 寄存器堆
 *	2读端口，1写端口
 * 	时钟下降沿写，WEn高电平有效
 */
module GReg(Rst, Clk, RAddr1, RAddr2, WAddr, WVal, WEn, RVal1, RVal2);
	input wire	Rst;
	input wire	Clk;
	input wire[4:0]	RAddr1;
	input wire[4:0]	RAddr2;
	input wire[4:0]	WAddr;
	input wire[31:0]	WVal;
	input wire	WEn;
	
	output reg[31:0]	RVal1;
	output reg[31:0]	RVal2;
	
	reg[31:0]	Regs[31:1];
	
	always @(negedge Clk or negedge Rst) begin
		if (Rst == 1'b0) begin
			Regs[ 1] <= 32'b0;
			Regs[ 2] <= 32'b0;
			Regs[ 3] <= 32'b0;
			Regs[ 4] <= 32'b0;
			Regs[ 5] <= 32'b0;
			Regs[ 6] <= 32'b0;
			Regs[ 7] <= 32'b0;
			Regs[ 8] <= 32'b0;
			Regs[ 9] <= 32'b0;
			Regs[10] <= 32'b0;
			Regs[11] <= 32'b0;
			Regs[12] <= 32'b0;
			Regs[13] <= 32'b0;
			Regs[14] <= 32'b0;
			Regs[15] <= 32'b0;
			Regs[16] <= 32'b0;
			Regs[17] <= 32'b0;
			Regs[18] <= 32'b0;
			Regs[19] <= 32'b0;
			Regs[20] <= 32'b0;
			Regs[21] <= 32'b0;
			Regs[22] <= 32'b0;
			Regs[23] <= 32'b0;
			Regs[24] <= 32'b0;
			Regs[25] <= 32'b0;
			Regs[26] <= 32'b0;
			Regs[27] <= 32'b0;
			Regs[28] <= 32'b0;
			Regs[29] <= 32'b0;
			Regs[30] <= 32'b0;
			Regs[31] <= 32'b0;
		end else if (WEn == 1'b1 && WAddr != 5'b0) begin
			Regs[WAddr] <= WVal;
		end
	end
	
	always @(Regs[RAddr1] or RAddr1) begin
		if (RAddr1 == 5'b0) begin
			RVal1 = 32'b0;
		end else begin
			RVal1 = Regs[RAddr1];
		end
	end

	always @(Regs[RAddr2] or RAddr2) begin
		if (RAddr2 == 5'b0) begin
			RVal2 = 32'b0;
		end else begin
			RVal2 = Regs[RAddr2];
		end
	end
	
endmodule
