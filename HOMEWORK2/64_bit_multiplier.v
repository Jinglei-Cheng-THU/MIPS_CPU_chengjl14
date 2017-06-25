module encode(in,x,y);
	input [2:0] in;
	input[63:0] x;
	output reg[65:0] y;
	always@(in)
		begin
			case(in)
			3'b000: y<=66'd0;
			3'b111:y<=0;
			3'b001:y<={{2{x[63]}},x};
			3'b010:y<={x[63],x[63],x};
			3'b011:y<={x[63],x,1'b0};
			3'b101:y<=~{x[63],x[63],x}+1;
			3'b110:y<=~{x[63],x[63],x}+1;
			3'b100:y<=~{x[63],x,1'b0}+1;
			endcase
		end
endmodule

module mul_64(in1,in2,out);
	input [63:0] in1,in2;
	output[127:0] out;
	wire[66:0] r_in2;
	wire[65:0]
	A_1,A_2,A_3,A_4,A_5,A_6,A_7,A_8,A_9,A_10,A_11,A_12,A_13,A_14,A_15,A_16,A_17,A_18,A_19,A_20,A_21,A_22,A_23,A_24,A_25,A_26,A_27,A_28,A_29,A_30,A_31,A_32;

	wire[127:0]
	Ex_Num1,Ex_Num2,Ex_Num3,Ex_Num4,Ex_Num5,Ex_Num6,Ex_Num7,Ex_Num8,Ex_Num9,Ex_Num10,Ex_Num11,Ex_Num12,Ex_Num13,Ex_Num14,Ex_Num15,Ex_Num16,Ex_Num17,Ex_Num18,Ex_Num19,Ex_Num20,Ex_Num21,Ex_Num22,Ex_Num23,Ex_Num24,Ex_Num25,Ex_Num26,Ex_Num27,Ex_Num28,Ex_Num29,Ex_Num30,Ex_Num31,Ex_Num32;

	wire [127:0] middle[29:0];

	assign r_in2={{2{in2[63]}},in2,1'b0};
	encode m_1(.in(r_in2[2:0]),.x(in1),.y(A_1));
	assign Ex_Num1={{62{A_1[65]}},A_1};
	encode m_2(.in(r_in2[4:2]),.x(in1),.y(A_2));
	assign Ex_Num2={{60{A_2[65]}},A_2,2'b00};
	encode m_3(.in(r_in2[6:4]),.x(in1),.y(A_3));
	assign Ex_Num3={{58{A_3[65]}},A_3,4'b0000};
	encode m_4(.in(r_in2[8:6]),.x(in1),.y(A_4));
	assign Ex_Num4={{56{A_4[65]}},A_4,6'b000000};
	encode m_5(.in(r_in2[10:8]),.x(in1),.y(A_5));
	assign Ex_Num5={{54{A_5[65]}},A_5,8'b00000000};
	encode m_6(.in(r_in2[12:10]),.x(in1),.y(A_6));
	assign Ex_Num6={{52{A_6[65]}},A_6,10'b0000000000};
	encode m_7(.in(r_in2[14:12]),.x(in1),.y(A_7));
	assign Ex_Num7={{50{A_7[65]}},A_7,12'b000000000000};
	encode m_8(.in(r_in2[16:14]),.x(in1),.y(A_8));
	assign Ex_Num8={{48{A_8[65]}},A_8,14'b00000000000000};
	encode m_9(.in(r_in2[18:16]),.x(in1),.y(A_9));
	assign Ex_Num9={{46{A_9[65]}},A_9,16'b0000000000000000};
	encode m_10(.in(r_in2[20:18]),.x(in1),.y(A_10));
	assign Ex_Num10={{44{A_10[65]}},A_10,18'b000000000000000000};
	encode m_11(.in(r_in2[22:20]),.x(in1),.y(A_11));
	assign Ex_Num11={{42{A_11[65]}},A_11,20'd0};
	encode m_12(.in(r_in2[24:22]),.x(in1),.y(A_12));
	assign Ex_Num12={{40{A_12[65]}},A_12,22'd0};
	encode m_13(.in(r_in2[26:24]),.x(in1),.y(A_13));
	assign Ex_Num13={{38{A_13[65]}},A_13,24'd0};
	encode m_14(.in(r_in2[28:26]),.x(in1),.y(A_14));
	assign Ex_Num14={{36{A_14[65]}},A_14,26'd0};
	encode m_15(.in(r_in2[30:28]),.x(in1),.y(A_15));
	assign Ex_Num15={{34{A_15[65]}},A_15,28'd0};
	encode m_16(.in(r_in2[32:30]),.x(in1),.y(A_16));
	assign Ex_Num16={{32{A_16[65]}},A_16,30'd0};
	encode m_17(.in(r_in2[34:32]),.x(in1),.y(A_17));
	assign Ex_Num17={{30{A_17[65]}},A_17,32'd0};
	encode m_18(.in(r_in2[36:34]),.x(in1),.y(A_18));
	assign Ex_Num18={{28{A_18[65]}},A_18,34'd0};
	encode m_19(.in(r_in2[38:36]),.x(in1),.y(A_19));
	assign Ex_Num19={{26{A_19[65]}},A_19,36'd0};
	encode m_20(.in(r_in2[40:38]),.x(in1),.y(A_20));
	assign Ex_Num20={{24{A_20[65]}},A_20,38'd0};
	encode m_21(.in(r_in2[42:40]),.x(in1),.y(A_21));
	assign Ex_Num21={{22{A_21[65]}},A_21,40'd0};
	encode m_22(.in(r_in2[44:42]),.x(in1),.y(A_22));
	assign Ex_Num22={{20{A_22[65]}},A_22,42'd0};
	encode m_23(.in(r_in2[46:44]),.x(in1),.y(A_23));
	assign Ex_Num23={{18{A_23[65]}},A_23,44'd0};
	encode m_24(.in(r_in2[48:46]),.x(in1),.y(A_24));
	assign Ex_Num24={{16{A_24[65]}},A_24,46'd0};
	encode m_25(.in(r_in2[50:48]),.x(in1),.y(A_25));
	assign Ex_Num25={{14{A_17[65]}},A_25,48'd0};
	encode m_26(.in(r_in2[52:50]),.x(in1),.y(A_26));
	assign Ex_Num26={{12{A_26[65]}},A_26,50'd0};
	encode m_27(.in(r_in2[54:52]),.x(in1),.y(A_27));
	assign Ex_Num27={{10{A_27[65]}},A_27,52'd0};
	encode m_28(.in(r_in2[56:54]),.x(in1),.y(A_28));
	assign Ex_Num28={{8{A_28[65]}},A_28,54'd0};
	encode m_29(.in(r_in2[58:56]),.x(in1),.y(A_29));
	assign Ex_Num29={{6{A_29[65]}},A_29,56'd0};
	encode m_30(.in(r_in2[60:58]),.x(in1),.y(A_30));
	assign Ex_Num30={{4{A_30[65]}},A_30,58'd0};
	encode m_31(.in(r_in2[62:60]),.x(in1),.y(A_31));
	assign Ex_Num31={{2{A_31[65]}},A_31,60'd0};
	encode m_32(.in(r_in2[64:62]),.x(in1),.y(A_32));
	assign Ex_Num32={A_32,62'd0};

	assign middle[0]=Ex_Num1+Ex_Num2;
	assign middle[1]=Ex_Num3+Ex_Num4;
	assign middle[2]=Ex_Num5+Ex_Num6;
	assign middle[3]=Ex_Num7+Ex_Num8;
	assign middle[4]=Ex_Num9+Ex_Num10;
	assign middle[5]=Ex_Num11+Ex_Num12;
	assign middle[6]=Ex_Num13+Ex_Num14;
	assign middle[7]=Ex_Num15+Ex_Num16;
	assign middle[8]=Ex_Num17+Ex_Num18;
	assign middle[9]=Ex_Num19+Ex_Num20;
	assign middle[10]=Ex_Num21+Ex_Num22;
	assign middle[11]=Ex_Num23+Ex_Num24;
	assign middle[12]=Ex_Num25+Ex_Num26;
	assign middle[13]=Ex_Num27+Ex_Num28;
	assign middle[14]=Ex_Num29+Ex_Num30;
	assign middle[15]=Ex_Num31+Ex_Num32;

	assign middle[16]=middle[0]+middle[1];
	assign middle[17]=middle[2]+middle[3];
	assign middle[18]=middle[4]+middle[5];
	assign middle[19]=middle[6]+middle[7];
	assign middle[20]=middle[8]+middle[9];
	assign middle[21]=middle[10]+middle[11];
	assign middle[22]=middle[12]+middle[13];
	assign middle[23]=middle[14]+middle[15];

	assign middle[24]=middle[16]+middle[17];
	assign middle[25]=middle[18]+middle[19];
	assign middle[26]=middle[20]+middle[21];
	assign middle[27]=middle[22]+middle[23];

	assign middle[28]=middle[24]+middle[25];
	assign middle[29]=middle[26]+middle[27];

	assign out=middle[29]+middle[28];

endmodule

/*
`timescale 1ns/1ps
module chengfaqi_test;
	reg [63:0]B;
	reg [63:0]A;
	wire [127:0]C;
	initial begin
		A<=64'b0;
		B<=64'b0;
		#500 A<=12;
		 B<=13;
		#500 A<=5;
		 B<=6;
		#500 A<=200;
		 B<=300;
	end
	mul_64 mul(.in1(B),.in2(A),.out(C));
endmodule

*/