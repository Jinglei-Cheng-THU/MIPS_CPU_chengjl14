/*------------------------------------------
功能：获取待汇编的文件的标号信息，将标号名存于value[]中，对应标号在文件中的位置（行信息）
      存入label_locate[]中，其中value_len为数组value的大小，即标号个数的上届，若实际标号
	  数大于value_len则显示出错信息：label_value[] over flow!
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
	int count = 0;                //count计数获取的标号个数，用于与label_value_len比较产生出错信息
	int getline_num = 0;
	int i = 0;
	while(!fin.eof()){
        getline(fin,str);
		getline_num++;
		if((0 <= str.rfind(':')) && (str.rfind(':') <= str.length())) //有冒号的行
		{
			for(i = 0; i < str.length(); i++)
			{            //过滤掉行首的空格符
	        	if(str[i] != ' ') break;
			}
			for(; i < str.length(); i++)
			{                 //获取标号名存入temp中
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


