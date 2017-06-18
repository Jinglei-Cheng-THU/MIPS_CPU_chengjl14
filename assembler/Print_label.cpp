/*-------------------------------------------------
功能：打印标签名及在汇编代码中的位置，检测标签获取是否正确
included in label.h
---------------------------------------------------*/

#include<iostream>
#include<string>
using namespace std;


void Print_label(string label_value[],int label_locate[],int label_num){
	cout<<"label_num = "<<label_num<<endl;
	for(int i = 0; i < label_num; i++) {
		cout<<label_locate[i]<<"   "<<label_value[i]<<endl;
	}
}