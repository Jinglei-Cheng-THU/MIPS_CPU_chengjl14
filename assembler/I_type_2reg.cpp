/*------------------------------------------
功能：对I_type_2reg指令进行汇编,立即数作为十进制数处理!  eg: addi $s1,$s2,100
included in ir.h
------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);
string Get_imm(string imm);
string Get_imm_5bit(string imm);

void I_type_2reg(string ir,int ir_type){
	ofstream fout("instruct.txt",ios::app);
	string rs = "", rt = "", imm = "";
	int choose = 0;
	int i;
	for(i = 0; i < ir.length(); i++){
		if(choose == 2) break;
		if(ir[i] == '$'){
			i++;
			choose++;
			while(ir[i] != ',' && i < ir.length()){
				if(choose == 1) { rt += ir[i]; }
				if(choose == 2) { rs += ir[i]; }
				i++;
			}
		}
	}
	bool flag = false;
	for(; i < ir.length(); i++){
		if(ir[i] != ' '){
			while(ir[i] != ' ' && ir[i] != '	' && i < ir.length()){
				imm += ir[i];
				i++;
			}
			flag = true;
		}
		if(flag) break;
	}
	switch(ir_type){
	case 1 : { fout<<"001000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;cout<<"001000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl; break; }  //addi
	case 2 : { fout<<"001001"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;cout<<"001001"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl; break; }  //addiu
	case 5 : { fout<<"001100"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;cout<<"001100"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl; break; }  //andi
	case 50 :{ fout<<"001101"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;cout<<"001101"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl; break; }  //ori
	case 54 :{ 	fout<<"00000000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm_5bit(imm)<<"000000"<<endl;cout<<"00000000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm_5bit(imm)<<"000000"<<endl; break; } //sll
	case 60 :{ fout<<"00000000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm_5bit(imm)<<"000011"<<endl;cout<<"00000000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm_5bit(imm)<<"000011"<<endl; break; } //sra
	case 62 :{ fout<<"00000000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm_5bit(imm)<<"000010"<<endl;cout<<"00000000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm_5bit(imm)<<"000010"<<endl; break; } //srl
	case 57 :{ fout<<"001010"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;cout<<"001010"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl; break; }  //slti
	case 58 :{ fout<<"001010"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;cout<<"001010"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl; break; }  //sltiu
	case 88 :{ fout<<"001110"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;cout<<"001110"<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl; break; }  //xori
	default: { fout<<"cannot find instruction in I_type_2reg ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in I_type_2reg ir_type = "<<ir_type<<endl; break;}
	}
	//fout<<Get_reg_value(rs)<<Get_reg_value(rt)<<Get_imm(imm)<<endl;
	fout.close();
}