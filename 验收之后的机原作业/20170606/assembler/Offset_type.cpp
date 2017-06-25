/*---------------------------------------------
功能：对lw  rt, offset(base)类型的指令进行汇编  eg: lw $s1, 100($s2)
included in ir.h
------------------------------------------------*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string Get_reg_value(string reg);
string Get_imm(string imm);

void Offset_type(string ir,int ir_type){
	ofstream fout("instruct.txt",ios::app);
	string rt = "", rs = "",offset = "";
	string str = "", temp = "";
	int value = 0;
	int i = 0;
	for(i = 0; i < ir.length(); i++){
		if(ir[i] == '$') { i++; break; }
	}
	for(; i < ir.length(); i++){
		if(ir[i] != ',') { rt += ir[i]; }
		else { i++; break; }
	}
	for(; i < ir.length(); i++){
		if(ir[i] != ' ') { break; }
	}
	for(; i < ir.length(); i++){
		if(ir[i] != '(') { offset += ir[i]; }
		else { i++; break; }
	}
	for(i += 1; i < ir.length(); i++) {
		if(ir[i] != ')') { rs += ir[i]; }
		else break;
	}
	switch(ir_type){
	case 31 : { fout<<"100000";cout<<"100000"; break; }  //lb
	case 32 : { fout<<"100100";cout<<"100100"; break; }  //lbu
    case 33 : { fout<<"100001";cout<<"100001"; break; }  //lh
	case 34 : { fout<<"100101";cout<<"100101"; break; }  //lhu
	case 35 : { fout<<"110000";cout<<"110000"; break; }  //ll
	case 37 : { fout<<"100011";cout<<"100011"; break; }  //lw
	case 38 : { fout<<"100010";cout<<"100010"; break; }  //lwl
	case 39 : { fout<<"100110";cout<<"100110"; break; }  //lwr
	case 51 : { fout<<"101000";cout<<"101000"; break; }  //sb
	case 52 : { fout<<"111000";cout<<"111000"; break; }  //sc
	case 53 : { fout<<"101001";cout<<"101001"; break; }  //sh
	case 66 : { fout<<"101011";cout<<"101011"; break; }  //sw
	case 67 : { fout<<"101010";cout<<"101010"; break; }  //swl
	case 68 : { fout<<"101110";cout<<"101110"; break; }  //swr
	case 89 : { fout<<"110001";cout<<"110001"; break; }  //LWC1
	default : { fout<<"cannot find instruction in Offset_type ir_type = "<<ir_type<<endl;
		        cout<<"cannot find instruction in Offset_type ir_type = "<<ir_type<<endl; break;}
	}
	fout<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(offset)<<endl;
	cout<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(offset)<<endl;
	fout.close();
}