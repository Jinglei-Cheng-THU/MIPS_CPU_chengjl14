module HOMEWORK2(A,CLZ_A);

	input [31:0]A;
	output [31:0]CLZ_A;
	wire [4:0]result;
	wire [15:0]val16;
	wire [7:0]val8;
	wire [3:0]val4;
	assign result[4]=(A[31:16]==16'b0);
	assign val16=result[4]?A[15:0]:A[31:16];
	assign result[3]=(val16[15:8]==8'b0);
	assign val8=result[3]?val16[7:0]:val16[15:8];
	assign result[2]=(val8[7:4]==4'b0);
	assign val4=result[2]?val8[3:0]:val8[7:4];
	assign result[1]=(val4[3:2]==2'b0);
	assign result[0]=result[1]?~val4[1]:~val4[3];
	assign CLZ_A=(A==0)?(32'd32):({27'b0,result});


endmodule

`timescale 1ns/1ps
module HOMEWORK2_TEST;
	reg [31:0]A;
	
	wire [31:0]C;
	initial begin
		A<=32'b0;
		#500 A<={$random};
		
		#500 A<={$random};
		
		#500 A<={$random};
		
	end
	HOMEWORK2 random(.A(A),.CLZ_A(C));
endmodule
