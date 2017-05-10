/*΢��ԭ������ҵ ֮ ���������

	����:	win7 enterprise,x64��VS2008	
	���ߣ�	��ǿ
	���ڣ�	2012.01

*/
/*-------------------------------------------------------------
ʹ��Ҫ��

  1 �����䵥������
  2 һ��ֻдһ�����
  3 ֻ֧�֡�#����ʽ��ע�ͣ�ע���ܳ�������βҲ�ܵ�������
  4 �����֧�ֿո���Ʊ���������ʽ
  5 ��֧��α��
  6 ��֧��ʮ�����Ʊ�ʾ������
  7 ����֤�ܹ���������﷨����
  8 ������̣���1�� mycode.txt��Analyze��ir_txt  //Ԥ����׶Σ�ȥ��tab�ַ���ע��
              ��2�� ir_txt��Main.cpp��assembler��instruct.txt,��MIPS����ļ��ö����ƴ����ļ�
              ��3�� instruct.txt��manual.txt��Check.cpp�Ƚ��жϻ�����Ƿ���ȷ������manual.txtΪ�˹�������ļ�,
			        ����Ҫ���д˲���ȥ��Main.cpp��main������check()��ע�ͼ���,��ʱ���ṩmanual.txt�ļ���
----------------------------------------------------------------*/
#include<iostream> 
#include<fstream>
#include<string> 
#include<cmath> 
#include<iomanip>
#include<cctype>
#include<algorithm>
#define IR_QUANTITY 120
#define LABEL_NUM 100
using namespace std; 

#include"check.h"
#include"label.h"
#include"ir.h"
#include"Get_reg_value.h"



void assembler(string ir_set[],string label_value[],int label_locate[],int label_num){
	ifstream fin("ir.txt");
	ofstream fout("instruct.txt");//��out��ʽ�򿪣�����ļ�����
	fout.close();//�ָ��ļ�ָ��
	fout.open("instruct.txt",ios::app);//������app��ʽ��
	//ofstream fout("instruct.txt");
	string str = "";
	int pc_count = 0;     //ָ���������,����Ϊ4
	int ir_type;         //ָ��ir��ָ��е����
	char pc_trans[25];    //��ʽת��
	string upper ="";
	string ir_name = "";
	while(!fin.eof()){
		getline(fin,str);
		if( str == "") { continue; }  //����Ԥ�������ļ������һ��������
		if((0 <= str.rfind(':')) && (str.rfind(':') <= str.length())) { continue; }  //���˵������
		upper = itoa(pc_count,pc_trans,16);   //��pc_count��ֵת��Ϊʮ��������
		transform(upper.begin(),upper.end(),upper.begin(),towupper);   //��upper��ֵת��Ϊ��д��ʽ
		ir_name = Get_ir_name(str);
		transform(ir_name.begin(),ir_name.end(),ir_name.begin(),towupper);
		ir_type = Get_ir_serial(ir_name,ir_set,IR_QUANTITY);
		switch(ir_type){
		case 0 :  //add
	    case 3 :  //addu
	    case 4 :  //and
	    case 48 : //nor
	    case 49 : //or
     	case 55 : //sllv
    	case 56 : //slt
    	case 59 : //sltu
    	case 61 : //srav
	    case 63 : //srlv
	    case 64 : //sub
	    case 65 : //subu
		case 87 : //xor
		case 90 : //ADD.S
		case 91 : //SUB.S
					{ R_type(str,ir_type); break; }
        case 8 :  //bgez
    	case 9 :  //bgezal
	    case 10:  //bgezall
    	case 11:  //bgezl
	    case 12:  //bgtz
    	case 13:  //bgtzl
        case 14:  //blez
    	case 15:  //blezl
        case 16:  //bltz
    	case 17:  //bltzal
    	case 18:  //bltzall
    	case 19: //bltzl
					{ B_type_1reg(str,label_value,label_locate,label_num,pc_count,ir_type); break; } 
        case 6 :  //beq
    	case 7 :  //beql
     	case 20 : //bne
    	case 21 ://bnel
					{ B_type_2reg(str,label_value,label_locate,label_num,pc_count,ir_type); break; } 
    	case 1 :  //addi
	    case 2 :  //addiu
    	case 5 :  //andi
    	case 50 : //ori
		case 54 : //sll
    	case 57 : //slti
    	case 58 : //sltiu
		case 60 : //sra
	    case 62 : //srl
		case 88 : //xori
					{ I_type_2reg(str,ir_type); break; }
	    case 31 : //lb
	    case 32 : //lbu
        case 33 : //lh
     	case 34 : //lhu
    	case 35 : //ll
    	case 37 : //lw
    	case 38 : //lwl
    	case 39 : //lwr
    	case 51 : //sb
    	case 52 : //sc
    	case 53 : //sh
     	case 66 : //sw
    	case 67 : //swl
		case 68 : //swr
		case 89 : //LWC1
					{ Offset_type(str,ir_type); break; } 
		case 36 :  //lui
	    case 72 :  //teqi
    	case 74 :  //tgei
    	case 75 :  //tgeiu
    	case 82 :  //tlti
    	case 83 :  //tltiu
		case 86 : //tnei
					{ I_type_1reg(str,ir_type); break; } 
		case 24 :  //div
    	case 25 :  //divu
		case 29 :  //jalr
    	case 40 :  //mfc0
    	case 43 :  //mtc0
    	case 46 :  //mult
    	case 47 :  //multu
		case 71 :  //teq
	    case 73 :  //tge
    	case 76 :  //tgeu
     	case 81 :  //tlt
    	case 84 :  //tltu
		case 85 : //tne
					{ R_type_2reg(str,ir_type); break; }
    	case 30 :  //jr
    	case 41 :  //mfhi
    	case 42 :  //mflo
    	case 44 :  //mthi
    	case 45 : //mtlo
					{ R_type_1reg(str,ir_type);  break;}
        case 27 :  //j
       	case 28 : /*jal*/	{ J_type(str,label_value,label_locate,label_num,ir_type); break; } 
		case 26 : /*eret*/	{ fout<<"01000010000000000000000000011000"<<endl;cout<<"01000010000000000000000000011000"<<endl;break; }
		case 22 : /*break*/	{ fout<<"00000000000000000000000000001101"<<endl;cout<<"00000000000000000000000000001101"<<endl; break; }  
		case 69 : /*sync*/	{ fout<<"00000000000000000000000000001111"<<endl;cout<<"00000000000000000000000000001111"<<endl; break; }  
		case 70 : /*syscall*/{ fout<<"00000000000000000000000000001100"<<endl;cout<<"00000000000000000000000000001100"<<endl; break; }  
		case 77 : /*tlbp*/	{ fout<<"01000010000000000000000000001000"<<endl;cout<<"01000010000000000000000000001000"<<endl; break; }  
		case 78 : /*tlbr*/	{ fout<<"01000010000000000000000000000001"<<endl;cout<<"01000010000000000000000000000001"<<endl; break; }  
		case 79 : /*tlbwi*/	{ fout<<"01000010000000000000000000000010"<<endl;cout<<"01000010000000000000000000000010"<<endl; break; }  
		case 80 : /*tlbwr*/	{ fout<<"01000010000000000000000000000110"<<endl;cout<<"01000010000000000000000000000110"<<endl; break; }  
		case 92 : /*nop*/	{ fout<<"00000000000000000000000000000000"<<endl;cout<<"00000000000000000000000000000000"<<endl;break; }
		default: { fout<<"In main.cpp cannot find instruction ir_name = "<<ir_name<<endl;
		           cout<<"In main.cpp cannot find instruction ir_name = "<<ir_name<<"pc_count = "<<pc_count/4<<endl; break;}
		}
		pc_count +=4;
	}
	fin.close();
}
int main(){ 

#ifndef _DEBUGING
	#define _DEGUBING  "debug"
	string ir_set[IR_QUANTITY] = {"ADD", "ADDI", "ADDIU", "ADDU", "AND", "ANDI", "BEQ", "BEQL", "BGEZ", "BGEZAL", "BGEZALL",
	                      "BGEZL", "BGTZ", "BGTZL", "BLEZ", "BLEZL", "BLTZ", "BLTZAL", "BLTZALL", "BLTZL", "BNE",
						  "BNEL", "BREAK", "CACHE", "DIV", "DIVU", "ERET", "J", "JAL", "JALR", "JR", "LB", "LBU",
						  "LH", "LHU", "LL", "LUI", "LW", "LWL", "LWR", "MFC0", "MFHI", "MFLO", "MTC0", "MTHI", 
						  "MTLO", "MULT", "MULTU", "NOR", "OR", "ORI", "SB", "SC", "SH", "SLL", "SLLV", "SLT", "SLTI",
						  "SLTIU", "SLTU", "SRA", "SRAV", "SRL", "SRLV", "SUB", "SUBU", "SW", "SWL", "SWR", "SYNC", 
						  "SYSCALL", "TEQ", "TEQI", "TGE", "TGEI", "TGEIU", "TGEU", "TLBP", "TLBR", "TLBWI", "TLBWR", 
						  "TLT", "TLTI", "TLTIU", "TLTU", "TNE", "TNEI", "XOR", "XORI",
						  "LWC1","ADD.S","SUB.S","NOP"};


	analyze();


	string label_value[LABEL_NUM];
	int label_locate[LABEL_NUM];
	int label_num = label_count(label_value,label_locate,LABEL_NUM);


	assembler(ir_set,label_value,label_locate,label_num);



#else

	cout<<"debuging...!"<<endl;
	cout<<(int)'#'<<endl;
       
#endif
    return 0; 
}