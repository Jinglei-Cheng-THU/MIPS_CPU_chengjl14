/*---------------------------------------------
���ܣ���������ʽת�������ַ�����ʮ����->������
included in ir.h
------------------------------------------------*/

#include<iostream>
#include<string>
using namespace std;

string Get_imm(string imm)
{             
	long value = 0;
	string str = "";
	string temp = "";
	char binary[20];
	int i;
	if(imm[0] != '-')
	{
		for(i = 0; i < imm.length(); i++){
			value = value * 10 + (int)imm[i] - 48;
			//cout<<"imm[i]"<<imm[i]<<endl;//check
		}
		if( value < 0 ) { 
			cout<<"fatal error in Get_imm.cpp. Imm error, imm = "<<imm<<endl; 
			return "xxxxxxxxxxxxxxxx";
		}
		temp = itoa(value,binary,2);
		for(i = 1; i <= 16 - temp.length(); i++){ //û�п�����������
			str +="0";
		}
		return str + temp;
	}
	else 
	{
		for(i = 1; i < imm.length(); i++){
			value = value * 10 + (int)imm[i] - 48;
		}
		if( value < 0 ) { 
			cout<<"fatal error in Get_imm.cpp. Imm error, imm = "<<imm<<endl;
			return "xxxxxxxxxxxxxxxx";
		}
		temp = itoa(value,binary,2);
		for(i = 1; i <= 16 - temp.length(); i++){
			str += "0";
		}
		str += temp;
		for(i = 0; i < str.length(); i++){             //��λȡ��
			if(str[i] == '0') { str[i] = '1'; }
			else { str[i] = '0'; }
		}
		value = 0;
		for(i = 0; i < str.length(); i++){
			value = value * 2 + (int)str[i] - 48;
		}
		value += 1;                      //�����1
		return itoa(value,binary,2);
	}
}