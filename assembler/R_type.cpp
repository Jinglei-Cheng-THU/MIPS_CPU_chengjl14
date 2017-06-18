/*------------------------------------------
功能：对R_type指令进行汇编   eg: add $s1,$s2,$s3
included in ir.h
------------------------------------------*/


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);

void R_type(string ir,int ir_type){
	ofstream fout("instruct.txt",ios::app);
	string rs = "", rt = "", rd = "";
	int choose = 0;
	for(int i = 0; i < ir.length(); i++){
		if(ir[i] == '$'){
			i++;
			choose++;
			while(ir[i] != ',' && i < ir.length()){
				if(choose == 1) { rd += ir[i]; }
				if(choose == 2) { rs += ir[i]; }
				if(choose == 3) { rt += ir[i]; }
				i++;
			}
		}
	}
	switch(ir_type){
	case 0 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100000"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100000"<<endl;  break;}//add
	case 3 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100001"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100001"<<endl;break;}//addu
	case 4 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100100"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100100"<<endl;break;}//and
	case 48 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100111"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100111"<<endl;break;}//nor
	case 49 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100101"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100101"<<endl;break;}//or
	case 55 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000000100"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000000100"<<endl;break;}//sllv
	case 56 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000101010"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000101010"<<endl;break;}//slt
	case 59 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000101011"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000101011"<<endl;break;}//sltu
	case 61 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000000111"<<endl; 
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000000111"<<endl; break;}//srav
	case 63 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000000110"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000000110"<<endl;break;}//srlv
	case 64 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100010"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100010"<<endl;break;}//sub
	case 65 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100011"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100011"<<endl;break;}//subu
	case 87 :{ fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100110"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_reg_value(rd)<<"00000100110"<<endl;break;}//xor
	case 90 :{ fout<<"01000110000"<<Get_reg_value(rt)<<Get_reg_value(rs)<<Get_reg_value(rd)<<"000000"<<endl;
		cout<<"01000110000"<<Get_reg_value(rt)<<Get_reg_value(rs)<<Get_reg_value(rd)<<"000000"<<endl;break;}//ADD.S
	case 91 :{ fout<<"01000110000"<<Get_reg_value(rt)<<Get_reg_value(rs)<<Get_reg_value(rd)<<"000001"<<endl;
		cout<<"01000110000"<<Get_reg_value(rt)<<Get_reg_value(rs)<<Get_reg_value(rd)<<"000001"<<endl;break;}//SUB.S
	default: { fout<<"cannot find instruction in R_type ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in R_type ir_type = "<<ir_type<<endl; break;}
	}
	fout.close();
}

