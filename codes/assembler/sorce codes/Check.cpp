/*--------------------------
 功能：判断两个文件中的内容是否完全相同（检验汇编结果）
 输入：需要判断的两个文件manual.txt & instruct.txt
 输出：给出所有不相同行的行号及比较结果信息。
  --------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define PR(x) cout<<#x"="<<x<<endl;

int Check(){
	cout<<endl<<"start checking..."<<endl;
	ifstream file1("manual.txt");   //源文件
	ifstream file2("instruct.txt");   //汇编结果文件
	string fstr1 = "";
	string fstr2 = "";
	long line_sum = 0;       //对文件行数计数
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