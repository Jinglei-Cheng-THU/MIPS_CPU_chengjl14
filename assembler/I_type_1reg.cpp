/*------------------------------------------
功能：对I_type_1reg指令进行汇编,立即数作为十进制数处理!  eg:TEQI rs, immediate
included in ir.h
------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);
string Get_imm(string imm);

void I_type_1reg(string ir,int ir_type)
{
	ofstream fout("instruct.txt",ios::app);
	string rs = "", imm = "";
	int i;
	for(i = 0; i < ir.length(); i++)
	{
		if(ir[i] == '$')
		{
			i++;
			while(ir[i] != ',' && i < ir.length())
			{
			    rs += ir[i]; 
				i++;
			}
			i++;
			break;
		}
	}
	bool flag = false;
	for(; i < ir.length(); i++)
	{
		if(ir[i] != ' ' && ir[i] != '	'){
			while(ir[i] != ' ' && i < ir.length()){
				imm += ir[i];
				i++;
			}
			flag = true;
		}
		if(flag) break;
	}
	switch(ir_type){
	case 36 : { fout<<"001111"<<"00000"<<Get_reg_value(rs);cout<<"001111"<<"00000"<<Get_reg_value(rs); break; }  //lui
	case 72 : { fout<<"000001"<<Get_reg_value(rs)<<"01100";cout<<"000001"<<Get_reg_value(rs)<<"01100"; break; }  //teqi
	case 74 : { fout<<"000001"<<Get_reg_value(rs)<<"01000";cout<<"000001"<<Get_reg_value(rs)<<"01000"; break; }  //tgei
	case 75 : { fout<<"000001"<<Get_reg_value(rs)<<"01001";cout<<"000001"<<Get_reg_value(rs)<<"01001"; break; }  //tgeiu
	case 82 : { fout<<"000001"<<Get_reg_value(rs)<<"01010";cout<<"000001"<<Get_reg_value(rs)<<"01010"; break; }  //tlti
	case 83 : { fout<<"000001"<<Get_reg_value(rs)<<"01011";cout<<"000001"<<Get_reg_value(rs)<<"01011"; break; }  //tltiu
	case 86 : { fout<<"000001"<<Get_reg_value(rs)<<"01110";cout<<"000001"<<Get_reg_value(rs)<<"01110"; break; }  //tnei
	default: { fout<<"cannot find instruction in I_type_1reg ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in I_type_1reg ir_type = "<<ir_type<<endl; break;}
	}
	fout<<Get_imm(imm)<<endl;cout<<Get_imm(imm)<<endl;
	//cout<<"imm:"<<imm<<endl;//check
	fout.close();
}