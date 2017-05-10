

module EX(EX_Shamt, EX_ALUSrc1, EX_ALUSrc2, 
			EX_RsVal, EX_RtVal, EX_Immediate, EX_ALUFn, 
			ALUOut, Cond);
	input wire[ 4:0]	EX_Shamt;
	input wire	EX_ALUSrc1, EX_ALUSrc2;
	input wire[31:0]	EX_RsVal, EX_RtVal, EX_Immediate;
	input wire[ 3:0]	EX_ALUFn;

	output wire[31:0]	ALUOut;
	output wire[5:0]	Cond;

	wire Gz, Ez, Lz, Eq;

	wire[31:0] ALUIn1 = EX_ALUSrc1 ? EX_Shamt : EX_RsVal;
	wire[31:0] ALUIn2 = EX_ALUSrc2 ? EX_Immediate : EX_RtVal;
	ALU alu(ALUIn1, ALUIn2, ALUOut, Cond, EX_ALUFn);
endmodule
