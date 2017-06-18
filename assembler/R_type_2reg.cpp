/*------------------------------------------
功能：对R_type_2reg指令进行汇编   eg: TGEU rs, rt  (其中的code域用00000填充)
included in ir.h
------------------------------------------*/


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);

void R_type_2reg(string ir,int ir_type){
	ofstream fout("instruct.txt",ios::app);
	string rs = "", rt = "";
	int choose = 0;
	for(int i = 0; i < ir.length(); i++){
		if(ir[i] == '$'){
			i++;
			choose++;
			while(ir[i] != ',' && ir[i] != ' ' && i < ir.length()){
				if(choose == 1) { rs += ir[i]; }
				if(choose == 2) { rt += ir[i]; }
				i++;
			}
		}
	}
	switch(ir_type){
	case 24 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011010"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011010"<<endl;break;}//div
	case 25 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011011"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011011"<<endl;break;}//divu
	case 29 : { if(choose == 1) {
	            	fout<<"000000"<<Get_reg_value(rs)<<"000001111100000001001"<<endl;
			  cout<<"000000"<<Get_reg_value(rs)<<"000001111100000001001"<<endl;}
		        else { fout<<"000000"<<Get_reg_value(rs)<<"00000"<<Get_reg_value(rt)<<"00000001001"<<endl;
				cout<<"000000"<<Get_reg_value(rs)<<"00000"<<Get_reg_value(rt)<<"00000001001"<<endl;}
				break;
			  }  //jalr
	case 40 : { fout<<"010000"<<"00000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"00000000000"<<endl;
		cout<<"010000"<<"00000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"00000000000"<<endl;break;}//mfc0
	case 43 : { fout<<"010000"<<"00100"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"00000000000"<<endl; 
		cout<<"010000"<<"00100"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"00000000000"<<endl; break;}//mtc0
	case 46 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011000"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011000"<<endl;break;}//mult
	case 47 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011001"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"011001"<<endl;break;}//multu
	case 71 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110100"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110100"<<endl;break;}//teq
	case 73 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110000"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110000"<<endl;break;}//tge
	case 76 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110001"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110001"<<endl;break;}//tgeu
	case 81 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110010"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110010"<<endl;break;}//tlt
	case 84 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110011"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110011"<<endl;break;}//tltu
	case 85 : { fout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110110"<<endl;
		cout<<"000000"<<Get_reg_value(rs)<<Get_reg_value(rt)<<"0000000000"<<"110110"<<endl;break;}//tne
	default: { fout<<"cannot find instruction in R_type_2reg ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in R_type_2reg ir_type = "<<ir_type<<endl; break;}
	}
	fout.close();
}

