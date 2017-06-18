/*------------------------------------------------
功能：获取指令str在指令集（数组）中的位置
included in "ir.h"
-------------------------------------------------*/

#include<iostream>
#include<string>
using namespace std;

int Get_ir_serial(string str,string ir_set[],int len){
	for(int i = 0; i < len; i++){
		if(str == ir_set[i]){
			return i;
		}
	}
	return -1;
}