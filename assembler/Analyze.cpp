/*-------------------------------
功能：对源汇编程序进行预处理，去掉注释和tab空格符
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
		if (str == "") { continue; }//连空格都没有的空行
		for (i = 0; i < des.length(); i++)
		{
			if (des[i] != ' ') empty_line = false;//排除全是空格的行
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

