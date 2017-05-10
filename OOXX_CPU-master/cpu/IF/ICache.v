`include "Define.v"

/**
 *	指令cache
 *	四路组关联
 *	每行4字（16字节）
 */
module ICache(Rst, Clk, PAddr, Val, Hit, NewVal, WEn);
	input wire	Rst;
	input wire	Clk;
	input wire[31:0]	PAddr;
	input wire[`CACHE_LINE_LEN - 1 : 0]	NewVal;
	input wire	WEn;
	output wire	Hit;
	output reg[31:0]	Val;

	//{TAG1|TAG2|TAG3|TAG4|VAL1|VAL2|VAL3|VAL4}
	reg[`CACHE_GROUPS-1 : 0]	Valid0;
	reg[`CACHE_GROUPS-1 : 0]	Valid1;
	reg[`CACHE_GROUPS-1 : 0]	Valid2;
	reg[`CACHE_GROUPS-1 : 0]	Valid3;
	reg[`CACHE_TAG_LEN-1 : 0]	Tags0[`CACHE_GROUPS - 1 : 0];
	reg[`CACHE_TAG_LEN-1 : 0]	Tags1[`CACHE_GROUPS - 1 : 0];
	reg[`CACHE_TAG_LEN-1 : 0]	Tags2[`CACHE_GROUPS - 1 : 0];
	reg[`CACHE_TAG_LEN-1 : 0]	Tags3[`CACHE_GROUPS - 1 : 0];
	reg[`CACHE_LINE_LEN-1 : 0]	Caches0[`CACHE_GROUPS - 1 : 0];
	reg[`CACHE_LINE_LEN-1 : 0]	Caches1[`CACHE_GROUPS - 1 : 0];
	reg[`CACHE_LINE_LEN-1 : 0]	Caches2[`CACHE_GROUPS - 1 : 0];
	reg[`CACHE_LINE_LEN-1 : 0]	Caches3[`CACHE_GROUPS - 1 : 0];
	
	wire[`CACHE_GROUP_IDX-1:0]	GroupSel = PAddr[`CACHE_GROUP_IDX + `CACHE_LINE_OFF - 1: `CACHE_LINE_OFF];
	wire[`CACHE_TAG_LEN-1 : 0]	CurrentTags = PAddr[31 : 32 - `CACHE_TAG_LEN];
	
	wire Hit0 = Tags0[GroupSel] == CurrentTags && Valid0[GroupSel];
	wire Hit1 = Tags1[GroupSel] == CurrentTags && Valid1[GroupSel];
	wire Hit2 = Tags2[GroupSel] == CurrentTags && Valid2[GroupSel];
	wire Hit3 = Tags3[GroupSel] == CurrentTags && Valid3[GroupSel];
	
	assign Hit = Hit0 || Hit1 || Hit2 || Hit3;
	
	always @(Caches3[GroupSel] or PAddr) begin
		case (PAddr[`CACHE_LINE_OFF-1 : 2])
			2'b00:	Val = Caches3[GroupSel][31: 0];
			2'b01:	Val = Caches3[GroupSel][63:32];
			2'b10:	Val = Caches3[GroupSel][95:64];
			2'b11:	Val = Caches3[GroupSel][127:96];
		endcase
	end
	
	always @(negedge Rst or negedge Clk) begin
		if (Rst == 0) begin
			Valid0 <= `CACHE_GROUPS'b0;
			Valid1 <= `CACHE_GROUPS'b0;
			Valid2 <= `CACHE_GROUPS'b0;
			Valid3 <= `CACHE_GROUPS'b0;
		end else begin
			if (WEn == 1'b1 && Hit == 1'b0) begin
				{Tags0[GroupSel], Tags1[GroupSel], Tags2[GroupSel], Tags3[GroupSel]}
					<= {Tags1[GroupSel], Tags2[GroupSel], Tags3[GroupSel], CurrentTags};
				{Caches0[GroupSel], Caches1[GroupSel], Caches2[GroupSel], Caches3[GroupSel]}
					<= {Caches1[GroupSel], Caches2[GroupSel], Caches3[GroupSel], NewVal};
				{Valid0[GroupSel], Valid1[GroupSel], Valid2[GroupSel], Valid3[GroupSel]}
					<= {Valid1[GroupSel], Valid2[GroupSel], Valid3[GroupSel], 1'b1};
			end else if (Hit == 1'b1) begin
				case ({Hit0, Hit1, Hit2, Hit3})
				4'b1000: begin
					{Tags0[GroupSel], Tags1[GroupSel], Tags2[GroupSel], Tags3[GroupSel]}
						<= {Tags1[GroupSel], Tags2[GroupSel], Tags3[GroupSel], Tags0[GroupSel]};
					{Caches0[GroupSel], Caches1[GroupSel], Caches2[GroupSel], Caches3[GroupSel]}
						<= {Caches1[GroupSel], Caches2[GroupSel], Caches3[GroupSel], Caches0[GroupSel]};
					{Valid0[GroupSel], Valid1[GroupSel], Valid2[GroupSel], Valid3[GroupSel]}
						<= {Valid1[GroupSel], Valid2[GroupSel], Valid3[GroupSel], Valid0[GroupSel]};
				end
				4'b0100: begin
					{Tags1[GroupSel], Tags2[GroupSel], Tags3[GroupSel]}
						<= {Tags2[GroupSel], Tags3[GroupSel], Tags1[GroupSel]};
					{Caches1[GroupSel], Caches2[GroupSel], Caches3[GroupSel]}
						<= {Caches2[GroupSel], Caches3[GroupSel], Caches1[GroupSel]};
					{Valid1[GroupSel], Valid2[GroupSel], Valid3[GroupSel]}
						<= {Valid2[GroupSel], Valid3[GroupSel], Valid1[GroupSel]};
				end
				4'b0010: begin
					{Tags2[GroupSel], Tags3[GroupSel]}
						<= {Tags3[GroupSel], Tags2[GroupSel]};
					{Caches2[GroupSel], Caches3[GroupSel]}
						<= {Caches3[GroupSel], Caches2[GroupSel]};
					{Valid2[GroupSel], Valid3[GroupSel]}
						<= {Valid3[GroupSel], Valid2[GroupSel]};
				end
				4'b0001: ;
				default: ;
				endcase
			end
		end
	end
	
	
endmodule
