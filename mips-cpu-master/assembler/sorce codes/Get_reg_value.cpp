
#include<iostream>
#include<string>
using namespace std;

string Get_reg_value(string reg){
	string temp = "",str="";
	char binary[10];
	int reg_num=0;
	switch(reg[0]){
	case 'z': return "00000";
	case 'v': { if(reg[1] == '0') return "00010";
		        else return "00011";
			  }
	case 'a': { if( reg[1] == 't' ) return "00001";
				else
				{
					reg_num = 4 + int(reg[1]) - 48;
					temp = itoa(reg_num,binary,2);
					temp = "00" + temp;
					return temp;
				}
			  }
	case 't': { if(reg[1] >= '0' && reg[1] <= '7'){
		            reg_num = 8 + int(reg[1]) - 48;
					temp = itoa(reg_num,binary,2);
					return "0" + temp; }
		        else if(reg[1] == 8) return "11000";
				     else return "11001";
			  }
	case 's': { if(reg[1] != 'p') { reg_num = 16 + int(reg[1]) - 48;
	            	return itoa(reg_num,binary,2);}
		        else return "11101";
			  }
	case 'g': return "11100";
	case 'f':{
				if(reg[1] != 'p') 
				{
					for(int i=1;i<reg.length();i++)
						reg_num=reg_num*10+int(reg[i])-48;
					temp=itoa(reg_num,binary,2);
					for(int i = 1; i <= 5 - temp.length(); i++)
						str +="0";
					return str + temp;
				}
				else	return "11110";
			 }
	case 'r': return "11111";
	default: { return "xxxxx"; }//cout<<"reg_trans fault! (in  Get_reg_value)"<<endl; exit(0); }
	}
}
