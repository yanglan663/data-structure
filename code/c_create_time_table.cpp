#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string> 
#include <algorithm>
#include "a_student.h"

extern int pe_student_number;
extern int non_pe_student_number;
extern int classroom_number;
extern int all_student_number_mod;
extern int student_number_lower_bound;
//打印学生信息
void save_student_subject(ofstream &t,student one_student) {
	t << one_student.stu_id << "\t" << one_student.stu_name << "\t" << one_student.stu_class << "\t";
	t <<"语文\t" << "数学\t" << "英语\t" << "音乐\t" <<"美术\t"<<"体育\t";
	if (one_student.stu_physical_zhong == Elective) {
		t << "物理中考\t";
	}
	if (one_student.stu_chemistry_zhong == Elective) {
		t << "化学中考\t";
	}
	if (one_student.stu_biological == Elective) {
		t << "生物中考\t";
	}
	if (one_student.stu_political_zhong == Elective) {
		t << "政治中考\t";
	}
	if (one_student.stu_history_zhong == Elective) {
		t << "历史中考\t";
	}
	if (one_student.stu_geography == Elective) {
		t << "地理\t";
	}
	if (one_student.stu_physical_hui == Elective) {
		t << "物理会考\t";
	}
	if (one_student.stu_chemistry_hui == Elective) {
		t << "化学会考\t";
	}
	if (one_student.stu_political_hui == Elective) {
		t << "政治会考\t";
	}
	if (one_student.stu_history_hui == Elective) {
		t << "历史会考\t";
		
	}
	t << one_student.stu_class_number <<  "\n";
}
//保存学生的课表
void save_table(vector<student>all_student, vector<int>x, int table_1_size, int table_2_size, int student_number, int subject_size, int time_number) {
	int one_day_class_size = 8;
	int day_number = 5;
	string stu_name = "student_time_table.txt";
	ofstream table_file(stu_name);
	for (int stu_index = 0; stu_index < student_number; stu_index++) {
		save_student_subject(table_file, all_student.at(stu_index));
		string stu_name = "stu_index" + to_string(stu_index);
		//table_file << stu_name << endl;
		vector<vector<string>>table(one_day_class_size, vector<string>(day_number, "空闲"));
		int sum = 0;
		for (int sub_index = 0; sub_index < subject_size; sub_index++) {
			for (int time_index = 0; time_index < time_number; time_index++) {
				int x_index = table_1_size + table_2_size + stu_index*subject_size*time_number + sub_index*time_number + time_index;
				if (x[x_index] == 1) {
					sum++;
					int time_row_index = time_index % one_day_class_size;
					int time_col_index = time_index /one_day_class_size;
					
					if (sub_index%Subject_number == stu_chinese) {
						int class_numer = sub_index / Subject_number;
						string class_name = "语文" + to_string(class_numer) + "班";
						table[time_row_index][time_col_index] = class_name;
						

					}
					if (sub_index%Subject_number == stu_math) {
						int class_numer = sub_index / Subject_number;
						string class_name = "数学" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
						

					}
					if (sub_index%Subject_number == stu_english) {
						int class_numer = sub_index / Subject_number;
						string class_name = "英语" + to_string(class_numer) + "班";
						
						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_music) {
						int class_numer = sub_index / Subject_number;
						string class_name = "音乐" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_art) {
						int class_numer = sub_index / Subject_number;
						string class_name = "美术" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_pe) {
						int class_numer = sub_index / Subject_number;
						string class_name = "体育" + to_string(class_numer) + "班";
						
						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_physical_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "物中" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_chemistry_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "化中" + to_string(class_numer) + "班";
						
						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_biological) {
						int class_numer = sub_index / Subject_number;
						string class_name = "生物" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_political_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "政中" + to_string(class_numer) + "班";
						
						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_history_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "历中" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_geography) {
						int class_numer = sub_index / Subject_number;
						string class_name = "地理" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_physical_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "物会" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_chemistry_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "化会" + to_string(class_numer) + "班";
						
						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_political_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "政会" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_history_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "历会" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}

				}
			}
		}
	

		for (int i = 0; i < one_day_class_size; i++) {
			for (int j = 0; j < day_number; j++) {
				table_file << table[i][j] << "\t";
			}
			table_file << "\n";
			if (i == 4)
				table_file << "\n";
		}
		table_file << "总学分数目\t" << sum << endl;
		table_file << "\n";
		table_file << "\n";
		table_file << "\n";
	}
}
//打印每一门课的课表
void save_table(vector<int>x, int table_1_size, int table_2_size, int student_number, int subject_size, int time_number) {
	int one_day_class_size = 8;
	int day_number = 5;
	string stu_name = "subject_table.txt";
	ofstream table_file(stu_name);
	vector<vector<string>>table(one_day_class_size, vector<string>(day_number, "空闲"));
	for (int stu_index = 0; stu_index < student_number; stu_index++) {

		for (int sub_index = 0; sub_index < subject_size; sub_index++) {
			for (int time_index = 0; time_index < time_number; time_index++) {
				int x_index = table_1_size + table_2_size + stu_index*subject_size*time_number + sub_index*time_number + time_index;
				if (x[x_index] == 1) {
					int time_row_index = time_index % one_day_class_size;
					int time_col_index = time_index / one_day_class_size;
					if (sub_index%Subject_number == stu_chinese) {
						int class_numer = sub_index / Subject_number;
						string class_name = "语文" + to_string(class_numer) + "班";
						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_math) {
						int class_numer = sub_index / Subject_number;
						string class_name = "数学" + to_string(class_numer) + "班";
						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_english) {
						int class_numer = sub_index / Subject_number;
						string class_name = "英语" + to_string(class_numer) + "班";
						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_music) {
						int class_numer = sub_index / Subject_number;
						string class_name = "音乐" + to_string(class_numer) + "班";
						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_art) {
						int class_numer = sub_index / Subject_number;
						string class_name = "美术" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_pe) {
						int class_numer = sub_index / Subject_number;
						string class_name = "体育" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_physical_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "物中" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_chemistry_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "化中" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_biological) {
						int class_numer = sub_index / Subject_number;
						string class_name = "生物" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_political_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "政中" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_history_zhong) {
						int class_numer = sub_index / Subject_number;
						string class_name = "历中" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;

					}
					if (sub_index%Subject_number == stu_geography) {
						int class_numer = sub_index / Subject_number;
						string class_name = "地理" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_physical_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "物会" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_chemistry_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "化会" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_political_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "政会" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}
					if (sub_index%Subject_number == stu_history_hui) {
						int class_numer = sub_index / Subject_number;
						string class_name = "历会" + to_string(class_numer) + "班";

						table[time_row_index][time_col_index] = class_name;
					}

				
				}
			}
		}
	}
	for (int i = 0; i < one_day_class_size; i++) {
		for (int j = 0; j < day_number; j++) {
			table_file << table[i][j] << "\t";
		}
		table_file << "\n";
		if (i == 4)
			table_file << "\n";
	}
}
//查找空间时间
void save_subject_table(vector<int>x, int table_1_size, int subject_size, int time_size, int stu_subject_id, string subject_name) {
	int one_day_class_size = 8;
	int day_number = 5;
	string file_name = "s_"+subject_name + ".txt";
	ofstream f(file_name);
	for (int sub_index = 0; sub_index < subject_size; sub_index++) {
		vector<vector<string>>table(one_day_class_size, vector<string>(day_number, "空闲"));
		if (sub_index%Subject_number == stu_subject_id) {
			for (int time_index = 0; time_index < time_size; time_index++) {
				int x_index = table_1_size + sub_index*time_size + time_index;
				if (x[x_index]==1) {
					int time_row_index = time_index % one_day_class_size;
					int time_col_index = time_index / one_day_class_size;

					int class_numer = sub_index / Subject_number;
					string class_name = subject_name + to_string(class_numer) + "班";
					table[time_row_index][time_col_index] = class_name;
				}
			}
			for (int i = 0; i < one_day_class_size; i++) {
				for (int j = 0; j < day_number; j++) {
					f << table[i][j] << "\t";
				}
				f << "\n";
				if (i == 4)
					f << "\n";
				
			}
			f << "\n";
			f << "\n";
		}
	}
}
void save_subject_table(vector<int>x, int table_1_size, int subject_size, int time_size) {
	save_subject_table(x, table_1_size, subject_size, time_size, stu_chinese, "语文");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_math, "数学");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_english, "英语");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_art, "美术");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_music, "音乐");

	save_subject_table(x, table_1_size, subject_size, time_size, stu_pe, "体育");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_physical_zhong, "物中");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_chemistry_zhong, "化中");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_biological, "生物");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_political_zhong, "政中");

	save_subject_table(x, table_1_size, subject_size, time_size, stu_history_zhong, "历中");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_geography, "地理");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_physical_hui, "物会");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_chemistry_hui, "化会");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_political_hui, "政会");
	save_subject_table(x, table_1_size, subject_size, time_size, stu_history_hui, "历会");


}

void create_teacher_table(vector<int>x, int table_1_size, int subject_size, int time_size,vector<int>class_id,int stu_subject_id,string subject_name,int i) {
	int one_day_class_size = 8;
	int day_number = 5;
	string file_name = "s_teacher_"+ subject_name + ".txt";
	ofstream f(file_name,ios::app);
	vector<vector<string>>table(one_day_class_size, vector<string>(day_number, "空闲"));
	for (auto one_class_id : class_id) {
		for (int sub_index = 0; sub_index < subject_size; sub_index++) {
			if (sub_index%Subject_number == stu_subject_id&&sub_index / Subject_number == one_class_id) {
				for (int time_index = 0; time_index < time_size; time_index++) {
					int x_index = table_1_size + sub_index*time_size + time_index;
					if (x[x_index] == 1) {
						int time_row_index = time_index % one_day_class_size;
						int time_col_index = time_index / one_day_class_size;
						int class_numer = sub_index / Subject_number;
						string class_name = subject_name + to_string(class_numer) + "班";
						table[time_row_index][time_col_index] = class_name;
					}
				}
			}
		}
	}
	f << subject_name + "老师" << to_string(i) << endl;
	for (int i = 0; i < one_day_class_size; i++) {
		for (int j = 0; j < day_number; j++) {
			f << table[i][j] << "\t";
		}
		f << "\n";
		if (i == 4)
			f << "\n";

	}
	f << "\n";
	f << "\n";
}

void create_xingzhengban_teacher(vector<int>x, int table_1_size, int subject_size, int time_size) {
	//音乐老师
	vector<int>music_class_one{ 1,10,11 };
	vector<int>music_class_two{ 0,2,3,4,5,6,7,8,9 };
	create_teacher_table(x, table_1_size, subject_size, time_size, music_class_one, stu_music, "音乐",1);
	create_teacher_table(x, table_1_size, subject_size, time_size, music_class_two, stu_music, "音乐", 2);
	//美术
	vector<int>art_class_one{ 1,2,3,5,9,11 };
	vector<int>art_class_two{ 0,4,6,7,8,10 };
	create_teacher_table(x, table_1_size, subject_size, time_size, art_class_one, stu_art, "美术", 1);
	create_teacher_table(x, table_1_size, subject_size, time_size, art_class_two, stu_art, "美术", 2);
	//语文
	vector<int>chinese_class_one{ 8,7 };
	vector<int>chinese_class_two{ 9,6 };
	vector<int>chinese_class_three{ 10,1 };
	vector<int>chinese_class_four{ 3,2 };
	vector<int>chinese_class_five{ 11,0 };
	vector<int>chinese_class_six{ 5,4 };
	create_teacher_table(x, table_1_size, subject_size, time_size, chinese_class_one, stu_chinese, "语文", 1);
	create_teacher_table(x, table_1_size, subject_size, time_size, chinese_class_two, stu_chinese, "语文", 2);
	create_teacher_table(x, table_1_size, subject_size, time_size, chinese_class_three, stu_chinese, "语文", 3);
	create_teacher_table(x, table_1_size, subject_size, time_size, chinese_class_four, stu_chinese, "语文", 4);
	create_teacher_table(x, table_1_size, subject_size, time_size, chinese_class_five, stu_chinese, "语文", 5);
	create_teacher_table(x, table_1_size, subject_size, time_size, chinese_class_six, stu_chinese, "语文", 6);
	//数学
	vector<int>math_class_one{ 8,11 };
	vector<int>math_class_two{ 9,10 };
	vector<int>math_class_three{ 6,7 };
	vector<int>math_class_four{ 2,3 };
	vector<int>math_class_five{ 4,5 };
	vector<int>math_class_six{ 0,1 };
	create_teacher_table(x, table_1_size, subject_size, time_size, math_class_one, stu_math, "数学", 1);
	create_teacher_table(x, table_1_size, subject_size, time_size, math_class_two, stu_math, "数学", 2);
	create_teacher_table(x, table_1_size, subject_size, time_size, math_class_three, stu_math, "数学", 3);
	create_teacher_table(x, table_1_size, subject_size, time_size, math_class_four, stu_math, "数学", 4);
	create_teacher_table(x, table_1_size, subject_size, time_size, math_class_five, stu_math, "数学", 5);
	create_teacher_table(x, table_1_size, subject_size, time_size, math_class_six, stu_math, "数学", 6);
	//英语
	vector<int>english_class_one{ 0,2 };
	vector<int>english_class_two{ 9 ,11 };
	vector<int>english_class_three{ 1,3 };
	vector<int>english_class_four{ 4,6 };
	vector<int>english_class_five{ 5,7 };
	vector<int>english_class_six{ 8,10 };
	create_teacher_table(x, table_1_size, subject_size, time_size, english_class_one, stu_english, "英语", 1);
	create_teacher_table(x, table_1_size, subject_size, time_size, english_class_two, stu_english, "英语", 2);
	create_teacher_table(x, table_1_size, subject_size, time_size, english_class_three, stu_english, "英语", 3);
	create_teacher_table(x, table_1_size, subject_size, time_size, english_class_four, stu_english, "英语", 4);
	create_teacher_table(x, table_1_size, subject_size, time_size, english_class_five, stu_english, "英语", 5);
	create_teacher_table(x, table_1_size, subject_size, time_size, english_class_six, stu_english, "英语", 6);
	//物理中考
	vector<int>physical_class_one{ 1,8 };
	vector<int>physical_class_two{ 6,7 };
	vector<int>physical_class_three{ 9,11 };
	vector<int>physical_class_four{ 0,2 };
	vector<int>physical_class_five{ 4,5 };
	vector<int>physical_class_six{ 3,10 };
	create_teacher_table(x, table_1_size, subject_size, time_size, physical_class_one, stu_physical_zhong, "物理", 1);
	create_teacher_table(x, table_1_size, subject_size, time_size, physical_class_two, stu_physical_zhong, "物理", 2);
	create_teacher_table(x, table_1_size, subject_size, time_size, physical_class_three, stu_physical_zhong, "物理", 3);
	create_teacher_table(x, table_1_size, subject_size, time_size, physical_class_four, stu_physical_zhong, "物理", 4);
	create_teacher_table(x, table_1_size, subject_size, time_size, physical_class_five, stu_physical_zhong, "物理", 5);
	create_teacher_table(x, table_1_size, subject_size, time_size, physical_class_six, stu_physical_zhong, "物理", 6);

}
void count_miminize_teachers(vector<int>x, int table_1_size, int subject_size, int time_size, vector<int> class_id, string class_name) {
	int g_max_people = 0;
	int c_max_people = 0;
	for (int time_index = 0; time_index < time_size; time_index++) {
		for (auto one : class_id) {
			for (int sub_index = 0; sub_index < subject_size; sub_index++) {
				if (sub_index%Subject_number == one) {
					int x_index = table_1_size + sub_index*time_size + time_index;
					if (x[x_index] == 1) {
						c_max_people++;
					}
				}
			}
		}
		g_max_people = max(g_max_people, c_max_people);
		c_max_people = 0;
	}
	cout << class_name << "\t" << g_max_people << endl;

}
void count_miminize_teachers(vector<int>x, int table_1_size, int subject_size, int time_size) {
	vector<int>history{ stu_history_hui,stu_history_zhong };
	count_miminize_teachers(x, table_1_size, subject_size, time_size, history, "历史");
	vector<int>biogical{ stu_biological };
	count_miminize_teachers(x, table_1_size, subject_size, time_size, biogical, "生物");
	vector<int>geography{ stu_geography };
	count_miminize_teachers(x, table_1_size, subject_size, time_size, geography, "地理");
	vector<int>poltical{ stu_political_hui,stu_political_zhong };
	count_miminize_teachers(x, table_1_size, subject_size, time_size, poltical, "政治");

}
void start_create_table() {
	vector<int>vals = read_x();
	vector<student>all_student = get_stu();

	int const stu_subject_row_number = all_student.size();
	int const stu_subject_col_number = 12 * Subject_number;
	int const subject_time_row_numer = 12 * Subject_number;
	int const subject_time_col_numer = 40;
	save_table(all_student, vals, stu_subject_row_number*stu_subject_col_number, subject_time_row_numer*subject_time_col_numer,
		stu_subject_row_number, stu_subject_col_number, subject_time_col_numer);
	save_subject_table(vals, stu_subject_row_number*stu_subject_col_number, stu_subject_col_number, subject_time_col_numer);
	save_table( vals, stu_subject_row_number*stu_subject_col_number, subject_time_row_numer*subject_time_col_numer,
		stu_subject_row_number, stu_subject_col_number, subject_time_col_numer);
	//生成行政班老师课表
	create_xingzhengban_teacher(vals, stu_subject_row_number*stu_subject_col_number, stu_subject_col_number, subject_time_col_numer);
	count_miminize_teachers(vals, stu_subject_row_number*stu_subject_col_number, stu_subject_col_number, subject_time_col_numer);
}

