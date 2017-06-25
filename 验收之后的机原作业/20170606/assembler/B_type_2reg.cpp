/*---------------------------------------------
功能：对beq指令进行汇编  eg: beq $rt,$rs,Label
included in ir.h
------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);
int Get_label_locate(string str,string label[],int label_locate[],int label_num);

void B_type_2reg(string ir,string label_value[],int label_locate[],int label_num,int pc,int ir_type){  ////////////////////////////???????????
	ofstream fout("instruct.txt",ios::app);
	string str = "", temp = "";
	string rs = "", rt = "", offset = "";
	char binary[20];
	int choose = 0;
	int des = 0;
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
		if(flag) break;//不要后面的空格
		if(ir[i] != ' '){
			while(ir[i] != ' ' && i < ir.length()){
				offset += ir[i];
				i++;
			}
			flag = true;
		}
	}
	offset += ":";
	pc /= 4;
	des = Get_label_locate(offset,label_value,label_locate,label_num);
	des -= pc;
	des--;
	if(des >= 0){
        temp = itoa(des,binary,2);
		for(i = 1; i <= 16 - temp.length(); i++){
		    str += "0";
		}
		str += temp;
	}
	else { 
		des = -des;
		temp = itoa(des,binary,2);
		for(i = 1; i <= 16 - temp.length(); i++){
		    str += "0";
		}
		str += temp;
		for(i = 0; i < str.length(); i++){             //按位取反
			if(str[i] == '0') { str[i] = '1'; }
			else { str[i] = '0'; }
		}
		int value = 0;
		for(i = 0; i < str.length(); i++){
			value = value * 2 + (int)str[i] - 48;
		}
		value += 1;                      //反码加1
		str = itoa(value,binary,2);		//转换成二进制
	}
	switch(ir_type){
	case 6 : { fout<<"000100"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; cout<<"000100"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; break; } //beq
	case 7 : { fout<<"010100"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; cout<<"010100"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; break; } //beql
	case 20 :{ fout<<"000101"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; cout<<"000101"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; break; } //bne
	case 21 :{ fout<<"010101"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; cout<<"010101"<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl; break; } //bnel
	default: { fout<<"cannot find instruction in B_type_2reg ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in B_type_2reg ir_type = "<<ir_type<<endl; break;}
	}
	//fout<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl;
	fout.close();
}