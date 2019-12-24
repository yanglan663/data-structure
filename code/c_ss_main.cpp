#pragma once

#include <vector>
using namespace std;
extern void start_optimize();
extern void start_optimize(int old_studnet_size);
extern void start_check();
extern void start_create_table();
extern void s_student();//统计分班信息

extern int pe_student_number;//体育课人数限制
extern int non_pe_student_number; // 非体育课人数限制
extern int classroom_number;//教室限制
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
//	student_number_lower_bound = 0;//人数下限
//	classroom_number = 73;
//	subject_people_size = { 
//		50,//语文
//		50,//数学
//		50,//英语
//		50,//音乐
//		50,//美术
//		50,//体育
//		50,//物理中考
//		50,//化学中考
//		50,//生物
//		50,//政治中考
//		50,//历史中考
//		50,//地理
//		50,//物理会考
//		50,//化学会考
//		50,//政治会考
//		50//历史会考
//	};
//	
//	subjects_number = {101,102,103,104,105,106,107,108,109};
//
//
//	//start_optimize();////得到12人的行政班课表
//
//
//	
//	//left_people::start_optimize(old_student_size);////得到73和510的结果
//	const int old_student_size = 510;//初始解的人数
//	small_change::start_optimize(old_student_size);
//
//
//	start_check();
//	start_create_table();
//	s_student();
//}