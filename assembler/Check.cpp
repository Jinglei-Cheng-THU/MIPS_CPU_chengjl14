/*--------------------------
 ���ܣ��ж������ļ��е������Ƿ���ȫ��ͬ������������
 ���룺��Ҫ�жϵ������ļ�manual.txt & instruct.txt
 ������������в���ͬ�е��кż��ȽϽ����Ϣ��
  --------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define PR(x) cout<<#x"="<<x<<endl;

int Check(){
	cout<<endl<<"start checking..."<<endl;
	ifstream file1("manual.txt");   //Դ�ļ�
	ifstream file2("instruct.txt");   //������ļ�
	string fstr1 = "";
	string fstr2 = "";
	long line_sum = 0;       //���ļ���������
	bool check_rezult = true;
    while(!file1.eof() && !file2.eof()){
		line_sum++;
		getline(file1,fstr1);
		getline(file2,fstr2);
		//getline(file2,fstr2);
		if(fstr1 != fstr2) { cout<<"Didn't match at line:"<<line_sum<<endl; check_rezult = false; }
	}
	cout<<line_sum<<" lines have been checked"<<endl;
	if(!file1.eof()) { cout<<"file1 hasn't finished yet!"<<endl; check_rezult = false; }
	if(!file2.eof()) { cout<<"file2 hasn't finished yet!"<<endl; check_rezult = false; }
	if(check_rezult) {cout<<"assemble success!"<<endl; }
	else { cout<<"assemble fail!"<<endl; }
	file1.close();
	file2.close();
	cout<<"end"<<endl;
	return 0;
}