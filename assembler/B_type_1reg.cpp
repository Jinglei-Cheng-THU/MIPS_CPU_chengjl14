/*---------------------------------------------
功能：对beq指令进行汇编  eg: bgez $rt,Label
included in ir.h
------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Get_reg_value(string reg);
int Get_label_locate(string str,string label[],int label_locate[],int label_num);

void B_type_1reg(string ir,string label_value[],int label_locate[],int label_num,int pc,int ir_type)
{ 
	ofstream fout("instruct.txt",ios::app);
	string str = "", temp = "";
	string rs = "", offset = "";
	char binary[20];
	bool flag = false;
	int des = 0;
	int i;
	for(i = 0; i < ir.length(); i++){
		if(flag) break;
		if(ir[i] == '$'){
			i++;
			while(ir[i] != ',' && i < ir.length()){
				 rs += ir[i++]; 
			}
			flag = true;
		}
	}
	flag = false;
	for(; i < ir.length(); i++){
		if(flag) break;
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
		str = itoa(value,binary,2);
	}
	switch(ir_type){
	case 8 : { fout<<"000001"<<Get_reg_value(rs)<<"00001"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"00001"<<str<<endl; break; } //bgez
	case 9 : { fout<<"000001"<<Get_reg_value(rs)<<"10001"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"10001"<<str<<endl; break; } //bgezal
	case 10: { fout<<"000001"<<Get_reg_value(rs)<<"10011"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"10011"<<str<<endl; break; } //bgezall
	case 11: { fout<<"000001"<<Get_reg_value(rs)<<"00011"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"00011"<<str<<endl; break; } //bgezl
	case 12: { fout<<"000111"<<Get_reg_value(rs)<<"00000"<<str<<endl; cout<<"000111"<<Get_reg_value(rs)<<"00000"<<str<<endl; break; } //bgtz
	case 13: { fout<<"010111"<<Get_reg_value(rs)<<"00000"<<str<<endl; cout<<"010111"<<Get_reg_value(rs)<<"00000"<<str<<endl; break; } //bgtzl
    case 14: { fout<<"000110"<<Get_reg_value(rs)<<"00000"<<str<<endl; cout<<"000110"<<Get_reg_value(rs)<<"00000"<<str<<endl; break; } //blez
	case 15: { fout<<"010110"<<Get_reg_value(rs)<<"00000"<<str<<endl; cout<<"010110"<<Get_reg_value(rs)<<"00000"<<str<<endl; break; } //blezl
    case 16: { fout<<"000001"<<Get_reg_value(rs)<<"00000"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"00000"<<str<<endl; break; } //bltz
	case 17: { fout<<"000001"<<Get_reg_value(rs)<<"10000"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"10000"<<str<<endl; break; } //bltzal
	case 18: { fout<<"000001"<<Get_reg_value(rs)<<"10010"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"10010"<<str<<endl; break; } //bltzall
	case 19: { fout<<"000001"<<Get_reg_value(rs)<<"00010"<<str<<endl; cout<<"000001"<<Get_reg_value(rs)<<"00010"<<str<<endl; break; } //bltzl
	default: { fout<<"cannot find instruction in B_type_1reg ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in B_type_1reg ir_type = "<<ir_type<<endl; break;}
	}
	//fout<<Get_reg_value(rt)<<Get_reg_value(rs)<<str<<endl;
	fout.close();
}