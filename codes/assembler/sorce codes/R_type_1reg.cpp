/*------------------------------------------
功能：对R_type_1reg指令进行汇编   eg: jr rs 
included in ir.h
------------------------------------------*/


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);

void R_type_1reg(string ir,int ir_type){
	ofstream fout("instruct.txt",ios::app);
	string rd = "";
	for(int i = 0; i < ir.length(); i++){
		if(ir[i] == '$'){
			i++;
			while(ir[i] != ',' && i < ir.length()){
				rd += ir[i]; 
				i++;
			}
		}
	}
	switch(ir_type){
	case 30 : { fout<<"000000"<<Get_reg_value(rd)<<"000000000000000001000"<<endl;cout<<"000000"<<Get_reg_value(rd)<<"000000000000000001000"<<endl;  break;}//jr
	case 41 : { fout<<"0000000000000000"<<Get_reg_value(rd)<<"00000010000"<<endl;cout<<"0000000000000000"<<Get_reg_value(rd)<<"00000010000"<<endl;  break;}//mfhi
	case 42 : { fout<<"0000000000000000"<<Get_reg_value(rd)<<"00000010010"<<endl;cout<<"0000000000000000"<<Get_reg_value(rd)<<"00000010010"<<endl;  break;}//mflo
	case 44 : { fout<<"000000"<<Get_reg_value(rd)<<"000000000000000010001"<<endl;cout<<"000000"<<Get_reg_value(rd)<<"000000000000000010001"<<endl;  break;}//mthi
	case 45 : { fout<<"000000"<<Get_reg_value(rd)<<"000000000000000010011"<<endl;cout<<"000000"<<Get_reg_value(rd)<<"000000000000000010011"<<endl;  break;}//mtlo
	default: { fout<<"cannot find instruction in R_type_1reg ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in R_type_1reg ir_type = "<<ir_type<<endl; break;}
	}
	fout.close();
}
