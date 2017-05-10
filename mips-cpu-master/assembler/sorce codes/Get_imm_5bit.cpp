/*---------------------------------------------
功能：立即数格式转换：（字符串）十进制->二进制
included in ir.h
------------------------------------------------*/

#include<iostream>
#include<string>
using namespace std;

string Get_imm_5bit(string imm)
{             
	long value = 0;
	string str = "";
	string temp = "";
	char binary[20];
	int i;
	for(i = 0; i < imm.length(); i++)
	{
		value = value * 10 + (int)imm[i] - 48;
	}
	if( value < 0 ) 
	{ 
		cout<<"fatal error in Get_imm_5bit.cpp. imm error, imm = "<<imm<<endl;
	    return "xxxxx";
	}
	temp = itoa(value,binary,2);
	for(i = 1; i <= 5 - temp.length(); i++){
		str +="0";
	}
	return str + temp;
}