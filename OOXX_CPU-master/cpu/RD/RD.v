
module RD(Rst, Clk, Instruction, PCValP4, 
				WB_Rd, WB_RegWr, WB_RegWVal, 
				Rs, Rt, Rd, RsVal, RtVal, RegWr, MemWr,
				ALUSrc1, ALUSrc2, ALUFn, 
				Shamt, Immediate, RegWSrc,
				NewPCVal, BCond);

	input wire[31:0]	Instruction, PCValP4, WB_RegWVal;
	input wire	Rst, Clk, WB_RegWr;
	input wire[ 4:0]	WB_Rd;

	output wire[ 4:0]	Rs, Rt, Rd, Shamt;
	output wire	RegWr, MemWr, ALUSrc1, ALUSrc2, RegWSrc;
	output wire[31:0]	RsVal, RtVal, Immediate, NewPCVal;
	output wire[ 3:0]	ALUFn;
	output wire[ 5:0]	BCond;

	wire RegWDst, SignExtend;

	assign Rs = Instruction[25:21];
	assign Rt = Instruction[20:16];
	assign Rd = RegWDst ? Instruction[20:16] : Instruction[15:11];
	assign Immediate = {{16{SignExtend & Instruction[15]}}, Instruction[15:0]};
	assign NewPCVal = PCValP4 + {Immediate[29:0], 2'b0};

	GReg register(Rst, Clk, Rs, Rt, WB_Rd, 
					WB_RegWVal,	WB_RegWr, RsVal, RtVal);

	IDecoder decoder(Instruction, RegWr, RegWSrc, RegWDst,
					ALUSrc1, ALUSrc2, ALUFn, MemWr, SignExtend, Shamt, BCond);

endmodule
