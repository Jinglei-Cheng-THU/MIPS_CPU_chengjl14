


module CPU(Rst, Clk);
	input wire	Rst;
	input wire	Clk;

	reg[31:0]	RD_PCValP4;

	wire[31:0] PCVal;
	wire[31:0] PCValP4;
	wire[31:0]	_PCVal;
	
	PC pc(Rst, Clk, PCVal, PCValP4, _PCVal);

	reg[31:0]	ICacheReg1;
	reg[31:0]	ICacheReg2;
	wire[31:0] Instruction;
	TempCache icache(Rst, Clk, ICacheReg1[31:0], 32'b0, Instruction, 1'b0);

	always @(negedge Clk) begin
		ICacheReg1 <= _PCVal;
		ICacheReg2 <= Instruction;
	end

	always @(negedge Rst or posedge Clk) begin
		if (Rst == 1'b0) begin
			RD_PCValP4 <= 32'b0;
		end else begin
			RD_PCValP4 <= PCValP4; 
		end
	end

	RD rd(Rst, Clk, ICacheReg2, RD_PCValP4,
				WB_Rd, WB_RegWr, WB_RegWVal,
				Rs, Rt, Rd, RsVal, RtVal, RegWr, MemWr, 
				ALUSrc1, ALUSrc2, ALUFn, 
				Shamt, Immediate, RegWSrc,
				NewPCVal, BCond);

	wire[ 4:0]	Rs, Rt, Rd, Shamt;
	wire	RegWr, MemWr, ALUSrc1, ALUSrc2, RegWSrc;
	wire[31:0]	RsVal, RtVal, Immediate, NewPCVal;
	wire[ 3:0]	ALUFn;
	wire[ 5:0]	BCond;

	reg[ 4:0]	EX_Rs, EX_Rt, EX_Rd, EX_Shamt;
	reg	EX_RegWr, EX_MemWr, EX_ALUSrc1, EX_ALUSrc2, EX_RegWSrc;
	reg[31:0]	EX_RsVal, EX_RtVal, EX_Immediate, EX_NewPCVal;
	reg[ 3:0]	EX_ALUFn;
	reg[ 5:0]	EX_BCond;

	always @(negedge Rst or posedge Clk) begin
		if (Rst == 1'b0) begin
			{EX_Rs, EX_Rt, EX_Rd, EX_Shamt, 
				EX_RegWr, EX_MemWr, EX_ALUSrc1, EX_ALUSrc2, EX_RegWSrc, 
				EX_RsVal, EX_RtVal, EX_Immediate, EX_NewPCVal, 
				EX_ALUFn, EX_BCond} <= 158'b0;
		end else begin
			{EX_Rs, EX_Rt, EX_Rd, EX_Shamt, 
				EX_RegWr, EX_MemWr, EX_ALUSrc1, EX_ALUSrc2, EX_RegWSrc, 
				EX_RsVal, EX_RtVal, EX_Immediate, EX_NewPCVal, 
				EX_ALUFn, EX_BCond} <= {Rs, Rt, Rd, Shamt, 
					RegWr, MemWr, ALUSrc1, ALUSrc2, RegWSrc, 
					RsVal, RtVal, Immediate, NewPCVal, 
					ALUFn, BCond};
		end
	end

	wire[31:0]	_EX_RsVal, _EX_RtVal;

	Forward forward(EX_Rs, EX_Rt, EX_RsVal, EX_RtVal,
		_EX_RsVal, _EX_RtVal, MM_Rd, MM_ALUOut, MM_RegWr,
		WB_Rd, WB_RegWVal, WB_RegWr);

	EX ex(EX_Shamt, EX_ALUSrc1, EX_ALUSrc2, _EX_RsVal, _EX_RtVal, 
				EX_Immediate, EX_ALUFn, ALUOut, Cond);

	Branch branch(PCVal, EX_NewPCVal, _PCVal, EX_BCond, Cond);

	wire[31:0]	ALUOut;
	wire[5:0]	Cond;

	reg[ 4:0]	MM_Rd;
	reg	MM_RegWr, MM_MemWr, MM_RegWSrc;
	reg[31:0]	MM_RtVal, MM_ALUOut;

	always @(negedge Rst or posedge Clk) begin
		if (Rst == 1'b0) begin
			{MM_Rd, MM_RegWr, MM_MemWr, MM_RegWSrc, MM_RtVal, MM_ALUOut}
				<= 72'b0;
		end else begin
			{MM_Rd, MM_RegWr, MM_MemWr, MM_RegWSrc, MM_RtVal, MM_ALUOut}
				<= {EX_Rd, EX_RegWr, EX_MemWr, EX_RegWSrc, EX_RtVal, ALUOut};	
		end
	end

	MM mm(Rst, Clk, MM_ALUOut, MM_RtVal, MM_MemWr, MemOut);

	wire[31:0] MemOut;

	reg[ 4:0]	WB_Rd;
	reg	WB_RegWr, WB_RegWSrc;
	reg[31:0]	WB_ALUOut, WB_MemOut;
	wire[31:0]	WB_RegWVal = WB_RegWSrc ? WB_MemOut : WB_ALUOut; 

	always @(negedge Rst or posedge Clk) begin
		if (Rst == 1'b0) begin
			{WB_Rd, WB_RegWr, WB_RegWSrc, WB_ALUOut, WB_MemOut}	<= 71'b0;
		end else begin
			{WB_Rd, WB_RegWr, WB_RegWSrc, WB_ALUOut, WB_MemOut}	
				<= {MM_Rd, MM_RegWr, MM_RegWSrc, MM_ALUOut, MemOut};
		end
	end

endmodule
