`include "Define.v"

module TLB(Rst, Clk, VAddr, PAddr, Hit, NewVal, WEn, ASID_Hi);
	input wire	Rst;
	input wire	Clk;
	input wire[31:0]	VAddr;
	input wire	WEn;
	input wire[7:0]	ASID_Hi;
	input wire[64:0]	NewVal;
	
	output reg[31:0]	PAddr;
	output reg	Hit;
	
	reg[18: 0]	VPN2[`TLB_LENGTH-1:0];
	reg[ 7: 0]	ASID[`TLB_LENGTH-1:0];
	reg[15: 0]	PageMask[`TLB_LENGTH-1:0];
	reg[ 0: 0]	G[`TLB_LENGTH-1:0];
	reg[25: 0]	PFN1[`TLB_LENGTH-1:0];
	reg[ 5: 0]	Flags1[`TLB_LENGTH-1:0];
	reg[25: 0]	PFN2[`TLB_LENGTH-1:0];
	reg[ 5: 0]	Flags2[`TLB_LENGTH-1:0];

endmodule
