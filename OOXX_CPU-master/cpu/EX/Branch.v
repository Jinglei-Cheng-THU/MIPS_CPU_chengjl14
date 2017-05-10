

module Branch(PCVal, NewPCVal, NextPC, BCond, Cond);
	input wire[31:0]	PCVal, NewPCVal;
	input wire[ 5:0]	BCond, Cond;
	output wire[31:0]	NextPC;

	assign NextPC = (BCond & Cond) == 6'b0 ? PCVal : NewPCVal;
endmodule
