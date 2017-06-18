/*----------------------------------------------
功能：获取汇编语句str中的指令名
included in "ir.h"
-----------------------------------------------*/

#include<iostream>
#include<string>
using namespace std;

string Get_ir_name(string str){                 //depart
	string temp = "";
	int space_num = 0,i=0;
	for(; i < str.length(); i++) {
		if(str[i] == ' ') { space_num++; }
		else break;
	}
	for(i = space_num ; i < str.length() && i >= 0; i++) {
		if(str[i] != ' ') { temp += str[i]; }
		else { break; }
	}
	return temp;
}