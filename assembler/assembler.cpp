/*---------------------------------------------
���ܣ������������
included in assembler.h
author  chen
create time : 2010.4.4
update time : 2010.4.4
------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath> 
#include<iomanip>
#include<cctype>
#include<algorithm>
using namespace std;

void assembler(string ir_set[],string label_value[],int label_locate[],int label_num){
	ifstream fin("ir.txt");
    ofstream fout("instruct.txt",ios::app);
	string str = "";
	int pc_count = 0;     //ָ���������,����Ϊ4
	int ir_value;         //ָ��ir��ָ��е����
	char pc_trans[25];    //���ڸ�ʽת��ʱ�õ�    unclear
	string upper ="";
	string ir_name = "";
	while(!fin.eof()){
		getline(fin,str);
		if((0 <= str.rfind(':')) && (str.rfind(':') <= str.length())) { continue; }  //���˵������
		upper = itoa(pc_count,pc_trans,16);   //��pc_count��ֵת��Ϊʮ��������
		transform(upper.begin(),upper.end(),upper.begin(),towupper);   //��upper��ֵת��Ϊ��д��ʽ
		fout<<"@"<<upper<<endl;
		ir_name = Get_ir_name(str);
		ir_value = Get_ir_serial(ir_name,ir_set,11);
		switch(ir_value){
		case 0 : { cout<<"I am in add "<<endl; R_type(str,"add");   break;}//add
		case 1 : { cout<<"I am in addi "<<endl; I_type(str,"addi");  break;}//addi
		case 2 : { cout<<"I am in lw "<<endl;  lw_sw(str,"lw");    break;}//lw
		case 3 : { cout<<"I am in sw "<<endl;  lw_sw(str,"sw");    break;}//sw
		case 4 : { cout<<"I am in sll "<<endl; I_type(str,"sll");   break;}//sll
		case 5 : { cout<<"I am in slt "<<endl; R_type(str,"slt");   break;}//slt
		case 6 : { cout<<"I am in beq "<<endl;beq(str,label_value,label_locate,label_num,pc_count); break;}//beq
		case 7 : { cout<<"I am in j "<<endl;J_type(str,label_value,label_locate,label_num,"j"); break;}//j
		case 8 : { cout<<"I am in jr "<<endl;jr();    break;}//jr
		case 9 : { cout<<"I am in jal "<<endl;J_type(str,label_value,label_locate,label_num,"jal"); break;}//jal
		case 10 : Break();break;//break
        default: { cout<<"error"<<endl; exit(0); }
		}
		pc_count +=4;
	}
	fin.close();
}