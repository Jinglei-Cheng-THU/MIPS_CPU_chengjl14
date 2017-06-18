
#ifndef LABEL_COUNT_H_
#define LABEL_COUNT_H_ "label.h"

int label_count(string value[],int label_locate[],int value_len);    //获取汇编源程序标号信息
void Print_label(string label_value[],int label_locate[],int label_num);  //打印获取的标号信息
int Get_label_locate(string str,string label[],int label_locate[],int len);  //获取与str相等的标签在汇编文件中的位置

#endif
