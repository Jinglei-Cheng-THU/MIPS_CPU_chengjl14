/*---------------------------------------------
功能：对I_type指令进行汇编  eg: J label
included in label.h
------------------------------------------------*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int Get_label_locate(string str,string label[],int label_locate[],int len);

void J_type(string ir,string label[],int label_locate[],int len,int ir_type){
	ofstream fout("instruct.txt",ios::app);
	//if(ir_type == "j"){ fout<<"000111"; }
	//if(ir_type == "jal") { fout<<"001001"; }
	string str = "", temp ="";
	int pc = 0;
	char binary[30];
	int i = 0;
	for(; i < ir.length(); i++){
		if(ir[i] != ' ') break;
	}
	for(; i < ir.length(); i++){
		if(ir[i] == ' ') break;
	}
	for(; i < ir.length(); i++){
		if(ir[i] != ' ') break;
	}
	for(; i < ir.length(); i++){
		if(ir[i] != ' '){ temp += ir[i]; }
		else break;
	}
	temp += ":";
	pc = Get_label_locate(temp,label,label_locate,len);
	temp = itoa(pc,binary,2);
	for(i = 1; i <= 26 - temp.length(); i++){
		str += "0";
	}
	str += temp;
	switch(ir_type){
    case 27 : { fout<<"000010";cout<<"000010"; break; } //j
	case 28 : { fout<<"000011";cout<<"000010"; break; } //jal
	default: { fout<<"cannot find instruction in J_type ir_type = "<<ir_type<<endl;
		       cout<<"cannot find instruction in J_type ir_type = "<<ir_type<<endl; break;}
	}
	fout<<str<<endl;cout<<str<<endl;
	fout.close();
}
