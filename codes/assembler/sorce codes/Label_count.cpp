/*------------------------------------------
���ܣ���ȡ�������ļ��ı����Ϣ�������������value[]�У���Ӧ������ļ��е�λ�ã�����Ϣ��
      ����label_locate[]�У�����value_lenΪ����value�Ĵ�С������Ÿ������Ͻ죬��ʵ�ʱ��
	  ������value_len����ʾ������Ϣ��label_value[] over flow!
included in label.h
------------------------------------------*/


#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//#define PR(x) cout<<#x"="<<x<<endl;

int label_count(string label_value[],int label_locate[],int label_value_len){
	ifstream fin("ir.txt");
    if(!fin)
	{ 
		cout<<"file fin doesn't exit!"<<endl; 
		exit(0); 
	}
	string str = "";
	string temp = "";
	int count = 0;                //count������ȡ�ı�Ÿ�����������label_value_len�Ƚϲ���������Ϣ
	int getline_num = 0;
	int i = 0;
	while(!fin.eof()){
        getline(fin,str);
		getline_num++;
		if((0 <= str.rfind(':')) && (str.rfind(':') <= str.length())) //��ð�ŵ���
		{
			for(i = 0; i < str.length(); i++)
			{            //���˵����׵Ŀո��
	        	if(str[i] != ' ') break;
			}
			for(; i < str.length(); i++)
			{                 //��ȡ���������temp��
    	    	if(str[i] != ' '){ temp += str[i]; }
	        	else break;
			}
			label_value[count] = temp;
			temp = "";
			label_locate[count] = getline_num - 1;
			count++;
			getline_num--;
			if(count >= label_value_len) {
				cout<<"label_value[] over flow!"<<endl;
				exit(0);
			}
		}
	}
	fin.close();
	return count;
}


