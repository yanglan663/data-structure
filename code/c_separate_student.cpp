#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string> 
#include <map>
#include "a_student.h"
//#include <ilcplex/ilocplex.h>

void get_one_class_number(student one_student_in_know_table, vector<student>&all_student, string subject_name_and_id, map<string, int>&each_class_student_number) {
	
	//for (auto one_student : all_student) {
		//if (one_student_in_know_table.stu_class == one_student.stu_class&&one_student_in_know_table.stu_class_number == one_student.stu_class_number) {
			each_class_student_number[subject_name_and_id]++;
		//}
	//}

}
map<string,int> separate_student(vector<student>student_know_table, vector<student>all_student, vector<int>x, int subject_size) {
	map<string, int>each_class_student_number;
	for (int stu_index = 0; stu_index < student_know_table.size(); stu_index++) {
		for (int sub_index = 0; sub_index < subject_size; sub_index++) {
			int x_index = stu_index*subject_size + sub_index;
			if (x[x_index] == 1) {
				if (sub_index%Subject_number == stu_chinese) {
					int class_numer = sub_index / Subject_number;
					string class_name = "语文" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);

				}
				if (sub_index%Subject_number == stu_math) {
					int class_numer = sub_index / Subject_number;
					string class_name = "数学" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_english) {
					int class_numer = sub_index / Subject_number;
					string class_name = "英语" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_art) {
					int class_numer = sub_index / Subject_number;
					string class_name = "美术" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_music) {
					int class_numer = sub_index / Subject_number;
					string class_name = "音乐" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_pe) {
					int class_numer = sub_index / Subject_number;
					string class_name = "体育" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_physical_zhong) {
					int class_numer = sub_index / Subject_number;
					string class_name = "物中" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_chemistry_zhong) {
					int class_numer = sub_index / Subject_number;
					string class_name = "化中" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_biological) {
					int class_numer = sub_index / Subject_number;
					string class_name = "生物" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);

				}
				if (sub_index%Subject_number == stu_political_zhong) {
					int class_numer = sub_index / Subject_number;
					string class_name = "政中" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_history_zhong) {
					int class_numer = sub_index / Subject_number;
					string class_name = "历中" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);


				}
				if (sub_index%Subject_number == stu_geography) {
					int class_numer = sub_index / Subject_number;
					string class_name = "地理" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);

				}
				if (sub_index%Subject_number == stu_physical_hui) {
					int class_numer = sub_index / Subject_number;
					string class_name = "物会" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);

				}
				if (sub_index%Subject_number == stu_chemistry_hui) {
					int class_numer = sub_index / Subject_number;
					string class_name = "化会" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);
				}
				if (sub_index%Subject_number == stu_political_hui) {
					int class_numer = sub_index / Subject_number;
					string class_name = "政会" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);

				}
				if (sub_index%Subject_number == stu_history_hui) {
					int class_numer = sub_index / Subject_number;
					string class_name = "历会" + to_string(class_numer) + "班";
					get_one_class_number(student_know_table.at(stu_index), all_student, class_name, each_class_student_number);

				}

			}
		}
	}
	return each_class_student_number;
}
void count_satisfy_student_number(vector<int>vals, vector<student>all_student,int table_1_size,int table_2_size,int student_size,int subject_size,int time_size) {
	
	map<int, int>rs;
	for (int stu_index = 0; stu_index < student_size; stu_index++) {
		int sum = 0;
		for (int sub_index = 0; sub_index < subject_size; sub_index ++ ) {
			for (int time_index = 0; time_index < time_size; time_index++) {
				int x_index = table_1_size + table_2_size + stu_index*subject_size*time_size + sub_index*time_size + time_index;
				sum += vals[x_index];
			}
		}
		if (all_student.at(stu_index).stu_class_number == 101 && sum == 38) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 102 && sum == 38) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 103 && sum == 38) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 104 && sum == 36) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 105 && sum == 36) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 106 && sum == 36) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 107 && sum == 38) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 108 && sum == 38) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
		if (all_student.at(stu_index).stu_class_number == 109 && sum == 38) {
			rs[all_student.at(stu_index).stu_class_number]++;
		}
	}
	for (auto one : rs) {
		cout << one.first << "\t"<<one.second << endl;
	}
}
void s_student() {
	vector<int>vals = read_x();
	vector<student>student_know_table = get_stu();
	vector<student>all_student = get_all_stu();
	int const stu_subject_row_number = student_know_table.size();
	int const stu_subject_col_number = 12 * Subject_number;
	int const subject_time_row_numer = 12 * Subject_number;
	int const subject_time_col_numer = 40;
	map<string, int>rs = separate_student(student_know_table, all_student, vals, stu_subject_col_number);
	ofstream file("sp.txt");
	for (auto i : rs) {
		file << i.first << "\t" << i.second << endl;
	}
	cout << "hello" << endl;
	count_satisfy_student_number(vals, student_know_table, student_know_table.size() * 192, 192 * 40, student_know_table.size(), 192, 40);
}


//
//int main() {
//	
//}
