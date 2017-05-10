

module Forward(Rs, Rt, RsVal, RtVal, _RsVal, _RtVal, 
				MM_Rd, MM_ALUOut, MM_RegWr,
				WB_Rd, WB_RegWVal, WB_RegWr);
	input wire[ 4:0]	Rs, Rt, MM_Rd, WB_Rd;
	input wire[31:0]	RsVal, RtVal, MM_ALUOut, WB_RegWVal;
	input wire	MM_RegWr, WB_RegWr;

	output reg[31:0]	_RsVal, _RtVal;

	always @(Rs or RsVal or MM_Rd or MM_ALUOut or MM_RegWr 
				or WB_Rd or WB_RegWVal or WB_RegWr) begin
		_RsVal = RsVal;
		if (Rs != 5'b0 && Rs == WB_Rd && WB_RegWr) begin
			_RsVal = WB_RegWVal;
		end
		if (Rs != 5'b0 && Rs == MM_Rd && MM_RegWr) begin
			_RsVal = MM_ALUOut;
		end
	end

	always @(Rt or RtVal or MM_Rd or MM_ALUOut or MM_RegWr 
				or WB_Rd or WB_RegWVal or WB_RegWr) begin
		_RtVal = RtVal;
		if (Rt != 5'b0 && Rt == WB_Rd && WB_RegWr) begin
			_RtVal = WB_RegWVal;
		end
		if (Rt != 5'b0 && Rt == MM_Rd && MM_RegWr) begin
			_RtVal = MM_ALUOut;
		end
	end

endmodule
