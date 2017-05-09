
#ifndef IR_H_
#define IR_H_ "ir.h"
#include"Get_reg_value.h"

int Get_ir_serial(string str,string ir_set[],int len);  //获取指令str在指令集（数组）中的位置
string Get_ir_name(string str);  //获取汇编语句str中的指令名
string Get_imm(string imm);  //立即数格式转换：（字符串）十进制->二进制
string Get_imm_5bit(string imm);  //立即数格式转换：（字符串）十进制->二进制

void R_type(string ir,int ir_type);  //对R_type指令进行汇编
void R_type_2reg(string ir,int ir_type);  //对R_type_2reg指令进行汇编   eg: TGEU rs, rt  (其中的code域用00000填充)
void R_type_1reg(string ir,int ir_type);  //对R_type_1reg指令进行汇编   eg: jr rs 
void I_type_2reg(string ir,int ir_type);  //对I_type_2reg指令进行汇编 eg:addi rs,rt,immediate
void I_type_1reg(string ir,int ir_type);  //对I_type_1reg指令进行汇编 eg:TEQI rs, immediate
void J_type(string ir,string label[],int label_locate[],int len,int ir_type);  //对J_type指令进行汇编
void jalr();  //对jr指令进行汇编
void B_type_2reg(string ir,string label_value[],int label_locate[],int label_num,int pc,int ir_type); //对beq指令进行汇编
void B_type_1reg(string ir,string label_value[],int label_locate[],int label_num,int pc,int ir_type); //对beq指令进行汇编
void Offset_type(string ir,int ir_type);  //对lw  rt, offset(base)类型的指令进行汇编  eg: lw $s1, 100($s2)

#endif