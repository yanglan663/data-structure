#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string> 
#include <ilcplex/ilocplex.h>


static const bool Elective = true;
static const bool Non_Elective = false;
static const int Subject_number = 16;//每个班课程的数目
static const int Must_choose = 6;//行政班的课程数量
static const int stu_chinese = 0;
static const int stu_math = 1;
static const int stu_english = 2;
static const int stu_music = 3;
static const int stu_art = 4;
static const int stu_pe = 5;
static const int stu_physical_zhong = 6;
static const int stu_chemistry_zhong = 7;
static const int stu_biological = 8;
static const int stu_political_zhong = 9;
static const int stu_history_zhong = 10;
static const int stu_geography = 11;
static const int stu_physical_hui = 12;
static const int stu_chemistry_hui = 13;
static const int stu_political_hui = 14;
static const int stu_history_hui = 15;





static const int stu_political_zhong_class_numbers = 3;
static const int stu_history_zhong_class_numbers = 4;

static const int stu_chemistry_zhong_class_numbers = 12-1;

static const int stu_physical_zhong_numbers = 12;

static const int stu_biological_class_numbers = 11;

static const int stu_physical_hui_class_numbers = 1+1;
static const int stu_chemistry_hui_class_numbers = 2;
static const int stu_political_hui_class_numbers = 9;
static const int stu_history_hui_class_numbers = 8;
static const int stu_geography_class_numbers = 7;
static const int stu_pe_class_numbers = 12;


using namespace std;


class student {
public:
	int stu_id;
	string stu_name;
	int stu_class;//班级
	bool stu_chinese = Elective;
	bool stu_math = Elective;
	bool stu_english = Elective;
	bool stu_pe = Elective;
	bool stu_music = Elective;
	bool stu_art = Elective;
	bool stu_physical_zhong = Non_Elective;
	bool stu_physical_hui = Non_Elective;
	bool stu_chemistry_zhong = Non_Elective;
	bool stu_chemistry_hui = Non_Elective;
	bool stu_biological = Non_Elective;
	bool stu_political_zhong = Non_Elective;
	bool stu_political_hui = Non_Elective;
	bool stu_history_zhong = Non_Elective;
	bool stu_history_hui = Non_Elective;
	bool stu_geography = Non_Elective;
	int stu_class_number = Non_Elective;//课程号
	bool operator == (student other) const {
		return this->stu_class == other.stu_class&&this->stu_class_number == other.stu_class_number;
	}
};
void print_coordinate(int row, int col);
void print_coordinate(int row, int col, int k);
void choose_student(vector<student>&all_student, vector<int>subjects_number);
vector<student> get_stu();//读取部分需要的学生信息
vector<student> get_all_stu();//读取所有学生的信息
vector<int> read_x();
vector<vector<int>>create_student_class(vector<student>&all_student, int const &row_number, int const &col_number);
vector<vector<int>>create_student_class(int const old_student_size, vector<student>&all_student, int const &row_number, int const &col_number);
vector<vector<int>>create_subject_time(int const &row_number, int const &col_number);
vector<vector<int>>create_subject_time(int const old_student_size,int const &row_number, int const &col_number);
