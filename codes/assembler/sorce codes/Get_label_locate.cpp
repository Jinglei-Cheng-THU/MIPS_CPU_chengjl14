/*---------------------------------------------
���ܣ���ȡ��str��ȵı�ǩ�ڻ���ļ��е�λ��
included in label.h
------------------------------------------------*/

#include<iostream>
#include<string>
using namespace std;

int Get_label_locate(string str,string label[],int label_locate[],int len){
	for(int i = 0; i < len; i++){
		if(str == label[i]) { return label_locate[i]; }
	}
	return -1;
}