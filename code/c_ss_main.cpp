#pragma once

#include <vector>
using namespace std;
extern void start_optimize();
extern void start_optimize(int old_studnet_size);
extern void start_check();
extern void start_create_table();
extern void s_student();//ͳ�Ʒְ���Ϣ

extern int pe_student_number;//��������������
extern int non_pe_student_number; // ����������������
extern int classroom_number;//��������
extern int all_student_number_mod;
extern int student_number_lower_bound;

extern vector<int>subjects_number;
extern vector<int>subject_people_size;

#include"c_second_3_c.h"
#include"c_second_4_c.h"
using namespace left_people;
using namespace small_change;
//int main() {
//	
//
//	pe_student_number = 0;
//	non_pe_student_number = 0;
//	student_number_lower_bound = 0;//��������
//	classroom_number = 73;
//	subject_people_size = { 
//		50,//����
//		50,//��ѧ
//		50,//Ӣ��
//		50,//����
//		50,//����
//		50,//����
//		50,//�����п�
//		50,//��ѧ�п�
//		50,//����
//		50,//�����п�
//		50,//��ʷ�п�
//		50,//����
//		50,//����ῼ
//		50,//��ѧ�ῼ
//		50,//���λῼ
//		50//��ʷ�ῼ
//	};
//	
//	subjects_number = {101,102,103,104,105,106,107,108,109};
//
//
//	//start_optimize();////�õ�12�˵�������α�
//
//
//	
//	//left_people::start_optimize(old_student_size);////�õ�73��510�Ľ��
//	const int old_student_size = 510;//��ʼ�������
//	small_change::start_optimize(old_student_size);
//
//
//	start_check();
//	start_create_table();
//	s_student();
//}