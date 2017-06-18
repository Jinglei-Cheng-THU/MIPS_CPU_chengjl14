#include<iostream> 
#include<fstream>
#include<string> 
#include<cmath> 
#include<iomanip>
#include<cctype>
#include<algorithm>

using namespace std;

int main(void) {
	
	string str = "";
	int bin_temp = 0;
	int count_line = 0;
	ifstream bin_hex("instruct.txt");
	ofstream fout("final_hex.txt");
	fout.close();
	fout.open("final_hex.txt", ios::app);
	cout << endl;
	while (!bin_hex.eof()) {
		getline(bin_hex, str);
		if (str == "") { continue; }
		fout << "memory[" << count_line << "]<=32'h" << str << ";" << endl;
		count_line += 1;
	}
	for (int i = count_line; i < 512; i++) {
		fout << "memory[" << i << "]=32'h00000000;" << endl;
	}
	fout.close();
	bin_hex.close();

	cout << "Hello VS2015" << endl;
	return 0;
}