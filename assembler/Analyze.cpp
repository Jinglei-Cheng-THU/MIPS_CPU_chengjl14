/*-------------------------------
���ܣ���Դ���������Ԥ����ȥ��ע�ͺ�tab�ո��
included in check.h
---------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void analyze()
{
	ifstream fin("mycode.txt");
	ofstream fout("ir.txt");
	string str = "";
	string des = "";
	bool empty_line = true;
	int i;
	while (!fin.eof()){
		getline(fin, str);
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') { break; }
			if (str[i] != '	')
			{
				des += str[i];
			}
			else
			{
				des += ' ';
			}

		}
		if (str == "") { continue; }//���ո�û�еĿ���
		for (i = 0; i < des.length(); i++)
		{
			if (des[i] != ' ') empty_line = false;//�ų�ȫ�ǿո����
		}
		if (!empty_line)
		{
			fout << des << endl;
			cout << des << endl;
		}
		empty_line = true;
		des = "";
	}
	fin.close();
	fout.close();
}

