#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string> 
#include "a_student.h"
#include <ilcplex/ilocplex.h>

extern int pe_student_number;
extern int non_pe_student_number;
extern int classroom_number;
extern int all_student_number_mod;
extern int student_number_lower_bound;
extern vector<int>subject_people_size;
void check_constraint(vector<int> vals,vector<student>all_student,
	vector<vector<int>>stu_subject, int s_s_size, int s_s_row_number, int s_s_col_number,
	vector<vector<int>>subject_time, int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number
	
) {
	//ѧʱ-�γ� stu_subject
	ofstream s_s("stu_subjext.txt");
	for (int i = 0; i < s_s_row_number; i++) {
		for (int j = 0; j < s_s_col_number; j++) {
			int x_index = i*s_s_col_number + j;
			stu_subject[i][j] = vals[x_index];
			s_s << vals[x_index] << "\t";
		}
		s_s << endl;
	}
	//�γ�-ʱ�� subject_time
	ofstream s_t("sub_time.txt");
	for (int i = 0; i < c_t_row_number; i++) {
		for (int j = 0; j < c_t_col_number; j++) {
			int x_index = s_s_size + i*c_t_col_number + j;
			subject_time[i][j] = vals[x_index];
			s_t << vals[x_index] << "\t";
		}
		s_t << endl;
	}
	ofstream s_s_t("stu_sub_time.txt");
	for (int stu_index = 0; stu_index < s_s_t_student_number; stu_index++) {
		int sum = 0;
		for (int j = 0; j < s_s_t_subject_number; j++) {
			for (int k = 0; k < s_s_t_time_number; k++) {
				int x_index = s_s_size + c_t_size + stu_index*s_s_t_subject_number*s_s_t_time_number + j*s_s_t_time_number + k;
				sum += vals[x_index];
				s_s_t << vals[x_index] << "\t";
			}
		}
		s_s_t << endl;
		if (sum > 40)
		{
			cout << sum << " total class > 40" << endl;
		}
	}
	
	int student_size = stu_subject.size();
	int subject_index = stu_subject[0].size();
	int time_size = subject_time[0].size();
	//Լ��1
	for (int sub_index = 0; sub_index < subject_index; sub_index++) {
		int sum = 0;
		for (int stu_index = 0; stu_index < student_size; stu_index++) {
			sum += stu_subject[stu_index][sub_index];
			if (sub_index%Subject_number == stu_chinese&&sum > subject_people_size[stu_chinese]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_math&&sum > subject_people_size[stu_math]) {
				cout << "Υ��Լ��1" << endl;
			}	
			if (sub_index%Subject_number == stu_english&&sum > subject_people_size[stu_english]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_music&&sum > subject_people_size[stu_music]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_art&&sum > subject_people_size[stu_art]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_pe&&sum > subject_people_size[stu_pe]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_physical_zhong&&sum > subject_people_size[stu_physical_zhong]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_chemistry_zhong&&sum > subject_people_size[stu_chemistry_zhong]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_biological&&sum > subject_people_size[stu_biological]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_political_zhong&&sum > subject_people_size[stu_political_zhong]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_history_zhong&&sum > subject_people_size[stu_history_zhong]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_geography&&sum > subject_people_size[stu_geography]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_physical_hui&&sum > subject_people_size[stu_physical_hui]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_chemistry_hui&&sum > subject_people_size[stu_chemistry_hui]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_political_hui&&sum > subject_people_size[stu_political_hui]) {
				cout << "Υ��Լ��1" << endl;
			}
			if (sub_index%Subject_number == stu_history_hui&&sum > subject_people_size[stu_history_hui]) {
				cout << "Υ��Լ��1" << endl;
			}

		}
		
	}


	//Լ��2
	for (int stu_index = 0; stu_index < student_size; stu_index++) {
		if (all_student.at(stu_index).stu_chinese == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_chinese&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_math == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_math&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "��ѧΥ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_english == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_english&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "Ӣ��Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_music == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_music&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_art == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_art&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_pe == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_pe&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_physical_zhong == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_physical_zhong&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "�����п�Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_chemistry_zhong == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_chemistry_zhong&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "��ѧ�п�Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_biological == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_biological&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_political_zhong == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_political_zhong&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "�����п�Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_history_zhong == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_history_zhong&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "��ʷ�п�Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_geography == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_geography&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_physical_hui == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_physical_hui&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����ῼΥ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_chemistry_hui == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_chemistry_hui&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "����Υ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_political_hui == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_political_hui&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "���λῼΥ��Լ��2" << endl;
			}
		}
		if (all_student.at(stu_index).stu_history_hui == Elective) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				if (sub_index%Subject_number == stu_history_hui&&stu_subject[stu_index][sub_index] == 1) {
					sum++;
				}
			}
			if (sum != 1) {
				cout << "��ʷ�ῼΥ��Լ��2" << endl;
			}
		}
	}
	//Լ��3
	vector<int> credit{ 6,6,5,1,1,3,5,5,2,3,3,2,3,3,1,1 };
	for (int sub_index = 0; sub_index < subject_index; sub_index++) {

		if (sub_index%Subject_number == stu_political_zhong&&sub_index >(Subject_number * stu_political_zhong_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_history_zhong&&sub_index > (Subject_number * stu_history_zhong_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_geography&&sub_index > (Subject_number * stu_geography_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_chemistry_zhong&&sub_index > (Subject_number * stu_chemistry_zhong_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_biological&&sub_index > (Subject_number * stu_biological_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_physical_hui&&sub_index > (Subject_number * stu_physical_hui_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_chemistry_hui&&sub_index > (Subject_number * stu_chemistry_hui_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_political_hui&&sub_index > (Subject_number * stu_political_hui_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_history_hui&&sub_index > (Subject_number * stu_history_hui_class_numbers - 1)) {
			continue;
		}
		else if (sub_index%Subject_number == stu_pe&&sub_index > (Subject_number * stu_pe_class_numbers - 1)) {
			continue;
		}
		else {
			int sum = 0;
			for (int time_index = 0; time_index < time_size; time_index++) {
				sum += subject_time[sub_index][time_index];
			}
			if (sum != credit.at(sub_index%Subject_number)) {
				cout << "�γ��±� "<<sub_index << endl;
				cout << "�������Ŀ"<<sub_index%Subject_number <<" ѡ���ѧ�� "<<sum<< endl;
				cout << "ѧ��Լ��������" << endl;
			}
				
		}
	}
	//Լ��4
	vector<int>class_rooms;
	for (int time_index = 0; time_index < time_size; time_index++) {
		int sum = 0;
		for (int sub_index = 0; sub_index < subject_index; sub_index++) {
			if(sub_index%Subject_number!=stu_pe)
				sum += subject_time[sub_index][time_index];
		}
		class_rooms.push_back(sum);
		if (sum > classroom_number) {
			cout << sum << endl;
			cout << "����Լ��������" << endl;
		}
	}
	sort(class_rooms.begin(), class_rooms.end());
	cout << "min room "<<class_rooms.front() << " max room " << class_rooms.back() << endl;

	vector<string>subject_name{ "��    ��","��    ѧ","Ӣ    ��","��    ��","��    ��","��    ��","�����п�","��ѧ�п�","��    ��","�����п�","��ʷ�п�","��    ��","����ῼ","��ѧ�ῼ","���λῼ","��ʷ�ῼ" };
	//Լ��5
	for (int stu_index = 0; stu_index < student_size; stu_index++) {
		for (int time_index = 0; time_index < time_size; time_index++) {
			int sum = 0;
			for (int sub_index = 0; sub_index < subject_index; sub_index++) {
				sum += stu_subject[stu_index][sub_index] * subject_time[sub_index][time_index];
			}
			if (sum > 1) {
				cout << all_student.at(stu_index).stu_name << "\t"<< all_student.at(stu_index).stu_id<<"\t";
				for (int sub_index = 0; sub_index < subject_index; sub_index++) {
					if (stu_subject[stu_index][sub_index] * subject_time[sub_index][time_index]) {
						cout << subject_name[sub_index%Subject_number] << sub_index/Subject_number << "\t";

					}
				}
				cout << "Լ��5������" << endl;
				break;
			}
		}
	}
}



void start_check() {
	vector<student>all_student = get_stu();
	cout << "ѧ����Ŀ" << all_student.size() << endl;
	int const stu_subject_row_number = all_student.size();
	int const stu_subject_col_number = 12 * Subject_number;
	vector<vector<int>>stu_subject = create_student_class(all_student, stu_subject_row_number, stu_subject_col_number);
	int const subject_time_row_numer = 12 * Subject_number;
	int const subject_time_col_numer = 40;
	vector<vector<int>>subject_time = create_subject_time(subject_time_row_numer, subject_time_col_numer);
	vector<int>vals = read_x();
	check_constraint(vals, all_student,
		stu_subject, stu_subject_row_number*stu_subject_col_number, stu_subject_row_number, stu_subject_col_number,
		subject_time, stu_subject_col_number*subject_time_col_numer, subject_time_row_numer, subject_time_col_numer,
		stu_subject_row_number*stu_subject_col_number*subject_time_col_numer, stu_subject_row_number, stu_subject_col_number, subject_time_col_numer);

}
//
//int main() {
//	start_check();
//}
