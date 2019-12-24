#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string> 
#include <ilcplex/ilocplex.h>

#include "a_student.h"


vector<int>subjects_number{};
vector<int>subject_people_size{};
int pe_student_number = 0;
int non_pe_student_number = 0;
int classroom_number = 0;

int student_number_lower_bound = 0;

void print_coordinate(int row, int col) {
	cout << "row number " << row << " col number " << col << endl;
}
void print_coordinate(int row, int col, int k) {
	cout << "student " << row << " subject " << col << " time " << k << endl;
}
//按要求选择学生
void choose_student(vector<student>&all_student, vector<int>subjects_number) {
	vector<student> small_student_number;
	for (int one_subject_number : subjects_number) {
		for (student one_student : all_student) {
			if (one_student.stu_class_number == one_subject_number) {
				//if (find(small_student_number.begin(), small_student_number.end(), one_student) == small_student_number.end())
				{
					small_student_number.push_back(one_student);
				}
			}
		}
	}

	all_student.assign(small_student_number.begin(), small_student_number.end());
}
//读取部分学生
vector<student> get_stu() {
	vector<student> all_student;
	fstream f("class.txt");
	string temp;
	int i = 0;
	while (getline(f, temp, '\n')) {
		istringstream in;
		in.str(temp);
		student t;
		in >> t.stu_id >> t.stu_name >> t.stu_class >> t.stu_chinese >> t.stu_math >> t.stu_english >> t.stu_music >> t.stu_art;
		in >> t.stu_pe;
		in >> t.stu_physical_zhong;
		in >> t.stu_chemistry_zhong;
		in >> t.stu_biological;
		in >> t.stu_political_zhong;
		in >> t.stu_history_zhong;
		in >> t.stu_geography;
		in >> t.stu_physical_hui;
		in >> t.stu_chemistry_hui;
		in >> t.stu_political_hui;
		in >> t.stu_history_hui;
		

		/*t.stu_chemistry_zhong= false;
		t.stu_physical_zhong= false;
		t.stu_pe = false;
		*/

		/*t.stu_chemistry_hui = false;
		t.stu_physical_hui = false;
		t.stu_political_zhong = false;
		t.stu_political_hui = false;
		t.stu_history_zhong = false;
		t.stu_history_hui = false;
		t.stu_geography = false;
		t.stu_biological = false;*/
		

		in >> t.stu_class_number;
		all_student.push_back(t);

	}
	
	choose_student(all_student, subjects_number);
	return all_student;
}
//读取全部510人
vector<student> get_all_stu() {
	vector<student> all_student;
	fstream f("class.txt");
	string temp;
	int i = 0;
	while (getline(f, temp, '\n')) {
		istringstream in;
		in.str(temp);
		student t;
		in >> t.stu_id >> t.stu_name >> t.stu_class >> t.stu_chinese >> t.stu_math >> t.stu_english >> t.stu_music >> t.stu_art >> t.stu_pe;
		in >> t.stu_physical_zhong >> t.stu_chemistry_zhong;
		in >> t.stu_biological;
		in >> t.stu_political_zhong;
		in >> t.stu_history_zhong;
		in >> t.stu_geography;
		in >> t.stu_physical_hui;
		in >> t.stu_chemistry_hui;
		in >> t.stu_political_hui;
		in >> t.stu_history_hui;
		in >> t.stu_class_number;
		all_student.push_back(t);
		i++;
	}
	
	return all_student;
}
vector<int> read_x() {
	vector<int> rs;
	fstream f("rs.txt");
	string temp;
	int i = 0;
	while (getline(f, temp, '\n')) {
		istringstream in;
		in.str(temp);
		in >> i;
		rs.push_back(i);
	}
	return rs;
}
vector<vector<int>>create_student_class(int old_student_size, vector<student>&all_student, int const &row_number, int const &col_number) {
	vector<vector<int>>stu_subject(row_number, vector<int>(col_number, 0));
	int stu_size = all_student.size();
	vector<int> old_x = read_x();
	//row
	for (int stu_index = 0; stu_index < stu_size; stu_index++) {
		for (int sub_index = 0; sub_index < col_number; sub_index++) {
			int old_x_index = stu_index*col_number + sub_index;
			if (old_x[old_x_index] == 1) {
				stu_subject[stu_index][sub_index] = 1;
			}
			else {
				stu_subject[stu_index][sub_index] = 0;
			}
		}
	}
	return stu_subject;
}
vector<vector<int>>create_student_class(vector<student>&all_student, int const &row_number, int const &col_number) {
	vector<vector<int>>stu_subject(row_number, vector<int>(col_number, 0));
	int stu_size = all_student.size();
	//row
	for (int stu_index = 0; stu_index < stu_size; stu_index++) {
		int group_numner = all_student.at(stu_index).stu_class;
		int current_col_number = Subject_number*(group_numner - 1);
		//col
		//语文 数学 英语 音乐 美术
		for (int i = current_col_number; i < current_col_number + Must_choose; i++) {
			stu_subject[stu_index][i] = 1;
		}
		//如果学生选择了物理中考
		if (all_student.at(stu_index).stu_physical_zhong == Elective) {
			for (int i = current_col_number; i < current_col_number + Subject_number; i++) {
				if (i%Subject_number == stu_physical_zhong)
					stu_subject[stu_index][i] = 1;
			}
		}
		//如果学生选择了化学中考
		/*if (all_student.at(stu_index).stu_chemistry_zhong == Elective) {
			for (int i = current_col_number; i < current_col_number + Subject_number; i++) {
				if (i%Subject_number == stu_chemistry_zhong)
					stu_subject[stu_index][i] = 1;
			}
		}*/
	}
	return stu_subject;
}

vector<vector<int>>create_subject_time(int const &row_number, int const &col_number) {
	vector<vector<int>>subject_time(row_number, vector<int>(col_number, 0));
	return subject_time;
}
//根据现有信息定下第二张表的时间
vector<vector<int>>create_subject_time(int old_student_size,int const &row_number, int const &col_number) {
	vector<int> old_x = read_x();
	vector<vector<int>>subject_time(row_number, vector<int>(col_number, -1));
	int old_first_table_size = old_student_size*row_number;
	for (int sub_index = 0; sub_index < row_number; sub_index++) {
		for (int time_index = 0; time_index < col_number; time_index++) {
			int old_x_index = old_first_table_size + sub_index*col_number + time_index;
			if (old_x[old_x_index] == 1) {
				subject_time[sub_index][time_index] = 1;
			}
			else {
				subject_time[sub_index][time_index] = 0;
			}
		
		}
	}
	return subject_time;
}
