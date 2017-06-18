

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);

void jalr(string ir,int ir_type){
	ofstream fout("instruct.txt",ios::app);
	string rs = "";
	int choose = 0;
	for(int i = 0; i < ir.length(); i++){
		if(ir[i] == '$'){
			i++;
			choose++;
			while(ir[i] != ',' && ir[i] != ',' && i < ir.length()){
				if(choose == 1) { rs += ir[i]; }
				i++;
			}
		}
	}
	
	fout<<"000000"<<Get_reg_value(rs)<<"00000"<<"0000000000001000"<<endl;

	fout.close();
}


//
//void jalr(){
//	ofstream fout("instruct.txt",ios::app);
//	fout<<"00100011111000000000000000000000"<<endl;
//	fout.close();
//}