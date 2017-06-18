
#ifndef IR_H_
#define IR_H_ "ir.h"
#include"Get_reg_value.h"

int Get_ir_serial(string str,string ir_set[],int len);  //��ȡָ��str��ָ������飩�е�λ��
string Get_ir_name(string str);  //��ȡ������str�е�ָ����
string Get_imm(string imm);  //��������ʽת�������ַ�����ʮ����->������
string Get_imm_5bit(string imm);  //��������ʽת�������ַ�����ʮ����->������

void R_type(string ir,int ir_type);  //��R_typeָ����л��
void R_type_2reg(string ir,int ir_type);  //��R_type_2regָ����л��   eg: TGEU rs, rt  (���е�code����00000���)
void R_type_1reg(string ir,int ir_type);  //��R_type_1regָ����л��   eg: jr rs 
void I_type_2reg(string ir,int ir_type);  //��I_type_2regָ����л�� eg:addi rs,rt,immediate
void I_type_1reg(string ir,int ir_type);  //��I_type_1regָ����л�� eg:TEQI rs, immediate
void J_type(string ir,string label[],int label_locate[],int len,int ir_type);  //��J_typeָ����л��
void jalr();  //��jrָ����л��
void B_type_2reg(string ir,string label_value[],int label_locate[],int label_num,int pc,int ir_type); //��beqָ����л��
void B_type_1reg(string ir,string label_value[],int label_locate[],int label_num,int pc,int ir_type); //��beqָ����л��
void Offset_type(string ir,int ir_type);  //��lw  rt, offset(base)���͵�ָ����л��  eg: lw $s1, 100($s2)

#endif