#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string> 
#include <ilcplex/ilocplex.h>
#include <set>
#include <list>
#include "a_student.h"
#include "c_second_3_c.h"

extern int pe_student_number;
extern int non_pe_student_number;
extern int classroom_number;



extern void create_student_subject_time_var(vector<student>all_student, IloEnv &env, IloNumVarArray &x, int s_s_size, int c_t_size, int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);
extern void change_x_range_halp(IloNumVarArray &x, int s_s_size, int c_t_size, int s_s_t_subject_number, int s_s_t_time_number, int stu_index, int subject_id);
extern void change_x_range(vector<student>all_student, IloEnv &env, IloNumVarArray &x,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);
extern void set_x_name(IloNumVarArray &x, int s_s_size, int c_t_size, int s_s_t_size);
extern void create_constraint_one(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);
extern void create_constraint_three(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);

extern void create_constraint_four(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);

extern void create_constraint_five(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);
extern void chang_subject_time_bound(IloNumVarArray &x, int s_s_size, int c_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number, int sub_index, int left_time, int right_time);
extern void create_constraint_six(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);
extern void create_constraint_seven(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);

extern void have_one_class_one_day_chinese_math(IloEnv &env, IloNumVarArray &x, IloModel &model, int s_s_size, int s_s_t_time_number, int sub_index, int left_time_index, int right_time_index);
extern void have_one_class_one_day_not_chinese_and_math(IloEnv &env, IloNumVarArray &x, IloModel &model, int s_s_size, int s_s_t_time_number, int sub_index, int left_time_index, int right_time_index);
extern void create_constraint_eight(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number);


namespace small_change {

	void create_student_subject_var(vector<student>&all_studen, IloEnv &env, IloNumVarArray &x, vector<vector<int>>stu_subject, int s_s_size, int s_s_row_number, int s_s_col_number) {
		for (int x_index = 0; x_index < s_s_size; x_index++) {
			int current_row = x_index / s_s_col_number;
			int current_col = x_index - s_s_col_number*current_row;
			//政治中考开3个班 4-12为0
			if (current_col % Subject_number == stu_political_zhong&&current_col>(Subject_number *stu_political_zhong_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));

			}
			//历史中考开4个班  5-12为0
			else if (current_col % Subject_number == stu_history_zhong&&current_col>(Subject_number * stu_history_zhong_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));

			}
			//地理中考开7个班 8-12为0
			else if (current_col % Subject_number == stu_geography&&current_col>(Subject_number * stu_geography_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			//化学中考开12个班
			else if (current_col % Subject_number == stu_chemistry_zhong&&current_col>(Subject_number * stu_chemistry_zhong_class_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			//生物中考开12个班
			else if (current_col % Subject_number == stu_biological&&current_col>(Subject_number * stu_biological_class_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			//物理会考开1个班
			else if (current_col % Subject_number == stu_physical_hui&&current_col>(Subject_number * stu_physical_hui_class_numbers - 1))
			{

				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			//化学会考开1个班
			else if (current_col % Subject_number == stu_chemistry_hui&&current_col>(Subject_number * stu_chemistry_hui_class_numbers - 1))
			{

				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			//政治会考开9个班
			else if (current_col % Subject_number == stu_political_hui&&current_col>(Subject_number * stu_political_hui_class_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_col % Subject_number == stu_history_hui&& current_col>(Subject_number * stu_history_hui_class_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_col % Subject_number == stu_pe&& current_col>(Subject_number * stu_pe_class_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_col % Subject_number == stu_physical_zhong&& current_col>(Subject_number * stu_physical_zhong_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else {
				if (current_col % Subject_number == stu_physical_hui
					|| current_col % Subject_number==stu_physical_zhong
					|| current_col % Subject_number==stu_chemistry_zhong
					|| current_col % Subject_number==stu_chemistry_hui
					) {
					x.add(IloNumVar(env, 0, 1, ILOINT));
				}
				else {
					if (stu_subject[current_row][current_col] == 0) {
						x.add(IloNumVar(env, 0, 0, ILOINT));
					}
					else {
						x.add(IloNumVar(env, 1, 1, ILOINT));
					}
				}
			}

		}
	}

	void create_subject_time_var(IloEnv &env, IloNumVarArray &x, vector<vector<int>>subject_time, int c_t_size, int c_t_row_number, int c_t_col_number) {
		for (int x_index = 0; x_index < c_t_size; x_index++) {
			int current_row = x_index / c_t_col_number;
			int current_col = x_index - current_row*c_t_col_number;
			if (current_row%Subject_number == stu_political_zhong&&current_row >(Subject_number * stu_political_zhong_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_history_zhong&&current_row > (Subject_number * stu_history_zhong_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_geography&&current_row > (Subject_number * stu_geography_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_chemistry_zhong&&current_row > (Subject_number * stu_chemistry_zhong_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_biological&&current_row > (Subject_number * stu_biological_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_physical_hui&&current_row > (Subject_number * stu_physical_hui_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_chemistry_hui&&current_row > (Subject_number * stu_chemistry_hui_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_political_hui&&current_row > (Subject_number * stu_political_hui_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_history_hui&&current_row > (Subject_number * stu_history_hui_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_pe&&current_row > (Subject_number * stu_pe_class_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_row%Subject_number == stu_physical_zhong&&current_row > (Subject_number * stu_physical_zhong_numbers - 1)) {
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else {
				if (current_row%Subject_number== stu_physical_hui
					|| current_row%Subject_number == stu_physical_zhong
					|| current_row%Subject_number == stu_chemistry_zhong
					|| current_row%Subject_number == stu_chemistry_hui){
					x.add(IloNumVar(env, 0, 1, ILOINT));
				}
				else {
					if (subject_time[current_row][current_col] == 0) {
						x.add(IloNumVar(env, 0, 0, ILOINT));
					}
					else {
						x.add(IloNumVar(env, 1, 1, ILOINT));
					}

				}

			}
		}
	}
	//学生可以少选学时
	void combine_student_subject_with_student_subject_time(IloEnv &env, IloNumVarArray &x, IloModel &model, int stu_index, int sub_index, IloNumArray credit,
		int s_s_size,
		int c_t_size,
		int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number, int x_index_one) {
		IloExpr expr_one_and_three(env);
		for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
			int x_index_three = s_s_size + c_t_size + stu_index*s_s_t_subject_number*s_s_t_time_number + sub_index*s_s_t_time_number + time_index;
			expr_one_and_three += x[x_index_three];
		}
		
		model.add(expr_one_and_three <= credit[sub_index%Subject_number] * x[x_index_one]);
	}
	void create_constraint_two(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
		int s_s_size, int s_s_row_number, int s_s_col_number,
		int c_t_size, int c_t_row_number, int c_t_col_number,
		int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
	{
		IloNumArray student_with_one_class(env);
		stringstream ints3{ "[1]" };
		ints3 >> student_with_one_class;

		stringstream ints2{ "[6,6,5,1,1,3,5,5,2,3,3,2,3,3,1,1]" };
		IloNumArray credit(env);
		ints2 >> credit;
		//学生
		for (int stu_index = 0; stu_index < all_student.size(); stu_index++) {
			//选择了物理中考
			if (all_student.at(stu_index).stu_physical_zhong == Elective) {
				IloExpr expr_one(env);//第一张表，某一门课的学分求和
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_physical_zhong) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];//任意一个学生，所有物理课求和，为1
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);
					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了化学中考
			if (all_student.at(stu_index).stu_chemistry_zhong == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_chemistry_zhong) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了生物中考
			if (all_student.at(stu_index).stu_biological == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_biological) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了政治中考
			if (all_student.at(stu_index).stu_political_zhong == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_political_zhong) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了历史中考
			if (all_student.at(stu_index).stu_history_zhong == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_history_zhong) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了地理中考
			if (all_student.at(stu_index).stu_geography == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_geography) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了物理会考
			if (all_student.at(stu_index).stu_physical_hui == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_physical_hui) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了化学会考
			if (all_student.at(stu_index).stu_chemistry_hui == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_chemistry_hui) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了政治会考
			if (all_student.at(stu_index).stu_political_hui == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_political_hui) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);


					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了历史会考
			if (all_student.at(stu_index).stu_history_hui == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_history_hui) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了体育
			if (all_student.at(stu_index).stu_pe == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_pe) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了语文
			if (all_student.at(stu_index).stu_chinese == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_chinese) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了数学
			if (all_student.at(stu_index).stu_math == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_math) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了英语
			if (all_student.at(stu_index).stu_english == Elective) {
				IloExpr expr_one(env);
				IloExpr expr_three(env);//第三张表，某一门课的学分求和
										//课程
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_english) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了音乐
			if (all_student.at(stu_index).stu_music == Elective) {
				IloExpr expr_one(env);
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_music) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
			//选择了美术
			if (all_student.at(stu_index).stu_art == Elective) {
				IloExpr expr_one(env);
				IloExpr expr_three(env);//第三张表，某一门课的学分求和
										//课程
				for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
					if (sub_index%Subject_number == stu_art) {
						int x_index = stu_index*s_s_col_number + sub_index;
						expr_one += x[x_index];
						combine_student_subject_with_student_subject_time(env, x, model,
							stu_index, sub_index, credit,
							s_s_size, c_t_size,
							s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, x_index);

					}
				}
				model.add(expr_one == student_with_one_class[0]);
			}
		}
	}
	// 一个老师，一个时间，只能上一门课
	void one_teacher_one_time_one_class(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<int>one_teacher_class_number, int s_s_size, int s_s_t_time_number, int time_index, int sub_number) {

		IloExpr music_class_one_left(env);
		for (int class_number : one_teacher_class_number) {
			int x_index = s_s_size + (class_number*Subject_number + sub_number)*s_s_t_time_number + time_index;
			music_class_one_left += x[x_index];
		}
		model.add(music_class_one_left <= 1);
	}
	void one_teacher_one_time_one_class(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<int>one_teacher_class_number_1,vector<int>one_teacher_class_number_2, int s_s_size, int s_s_t_time_number, int time_index, int sub_number_1,int sub_number_2) {

		IloExpr music_class_one_left(env);
		for (int class_number : one_teacher_class_number_1) {
			int x_index = s_s_size + (class_number*Subject_number + sub_number_1)*s_s_t_time_number + time_index;
			music_class_one_left += x[x_index];
		}
		for (int class_number : one_teacher_class_number_2) {
			int x_index = s_s_size + (class_number*Subject_number + sub_number_2)*s_s_t_time_number + time_index;
			music_class_one_left += x[x_index];
		}
		model.add(music_class_one_left <= 1);
	}
	//同一个老师的一门课不能在同一个时间开
	void create_constraint_nine(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
		int s_s_size, int s_s_row_number, int s_s_col_number,
		int c_t_size, int c_t_row_number, int c_t_col_number,
		int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
	{
		//音乐
		vector<int>music_class_one{ 1,10,11 };
		vector<int>music_class_two{ 0,2,3,4,5,6,7,8,9 };
		//美术
		vector<int>art_class_one{ 1,2,3,5,9,11 };
		vector<int>art_class_two{ 0,4,6,7,8,10 };
		//语文
		vector<int>chinese_class_one{ 8,7 };
		vector<int>chinese_class_two{ 9,6 };
		vector<int>chinese_class_three{ 10,1 };
		vector<int>chinese_class_four{ 3,2 };
		vector<int>chinese_class_five{ 11,0 };
		vector<int>chinese_class_six{ 5,4 };
		//数学
		vector<int>math_class_one{ 8,11 };
		vector<int>math_class_two{ 9,10 };
		vector<int>math_class_three{ 6,7 };
		vector<int>math_class_four{ 2,3 };
		vector<int>math_class_five{ 4,5 };
		vector<int>math_class_six{ 0,1 };
		//英语
		vector<int>english_class_one{ 0,2 };
		vector<int>english_class_two{ 9 ,11 };
		vector<int>english_class_three{ 1,3 };
		vector<int>english_class_four{ 4,6 };
		vector<int>english_class_five{ 5,7 };
		vector<int>english_class_six{ 8,10 };
		//物理中考
		vector<int>physical_class_one{ 1,8 };
		vector<int>physical_class_two{ 6,7 };
		vector<int>physical_class_three{ 9,11 };
		vector<int>physical_class_four{ 0,2 };
		vector<int>physical_class_five{ 4,5 };
		vector<int>physical_class_six{ 3,10 };
		//生物
		vector<int>biogical_class_one{ 0,1,2 };
		vector<int>biogical_class_two{ 3,4,5,6 };
		vector<int>biogical_class_three{ 7,8,9,10 };

		//地理
		vector<int>geography_class_one{ 0,1 };
		vector<int>geography_class_two{ 2,3};
		vector<int>geography_class_three{ 4,6,5 };
		for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
			//音乐
			one_teacher_one_time_one_class(env, x, model, music_class_one, s_s_size, s_s_t_time_number, time_index, stu_music);
			one_teacher_one_time_one_class(env, x, model, music_class_two, s_s_size, s_s_t_time_number, time_index, stu_music);
			//美术
			one_teacher_one_time_one_class(env, x, model, art_class_one, s_s_size, s_s_t_time_number, time_index, stu_art);
			one_teacher_one_time_one_class(env, x, model, art_class_two, s_s_size, s_s_t_time_number, time_index, stu_art);
			//语文
			one_teacher_one_time_one_class(env, x, model, chinese_class_one, s_s_size, s_s_t_time_number, time_index, stu_chinese);
			one_teacher_one_time_one_class(env, x, model, chinese_class_two, s_s_size, s_s_t_time_number, time_index, stu_chinese);
			one_teacher_one_time_one_class(env, x, model, chinese_class_three, s_s_size, s_s_t_time_number, time_index, stu_chinese);
			one_teacher_one_time_one_class(env, x, model, chinese_class_four, s_s_size, s_s_t_time_number, time_index, stu_chinese);
			one_teacher_one_time_one_class(env, x, model, chinese_class_five, s_s_size, s_s_t_time_number, time_index, stu_chinese);
			one_teacher_one_time_one_class(env, x, model, chinese_class_six, s_s_size, s_s_t_time_number, time_index, stu_chinese);
			//数学
			one_teacher_one_time_one_class(env, x, model, math_class_one, s_s_size, s_s_t_time_number, time_index, stu_math);
			one_teacher_one_time_one_class(env, x, model, math_class_two, s_s_size, s_s_t_time_number, time_index, stu_math);
			one_teacher_one_time_one_class(env, x, model, math_class_three, s_s_size, s_s_t_time_number, time_index, stu_math);
			one_teacher_one_time_one_class(env, x, model, math_class_four, s_s_size, s_s_t_time_number, time_index, stu_math);
			one_teacher_one_time_one_class(env, x, model, math_class_five, s_s_size, s_s_t_time_number, time_index, stu_math);
			one_teacher_one_time_one_class(env, x, model, math_class_six, s_s_size, s_s_t_time_number, time_index, stu_math);
			//英语
			one_teacher_one_time_one_class(env, x, model, english_class_one, s_s_size, s_s_t_time_number, time_index, stu_english);
			one_teacher_one_time_one_class(env, x, model, english_class_two, s_s_size, s_s_t_time_number, time_index, stu_english);
			one_teacher_one_time_one_class(env, x, model, english_class_three, s_s_size, s_s_t_time_number, time_index, stu_english);
			one_teacher_one_time_one_class(env, x, model, english_class_four, s_s_size, s_s_t_time_number, time_index, stu_english);
			one_teacher_one_time_one_class(env, x, model, english_class_five, s_s_size, s_s_t_time_number, time_index, stu_english);
			one_teacher_one_time_one_class(env, x, model, english_class_six, s_s_size, s_s_t_time_number, time_index, stu_english);
			//物理中考
			one_teacher_one_time_one_class(env, x, model, physical_class_one, s_s_size, s_s_t_time_number, time_index, stu_physical_zhong);
			one_teacher_one_time_one_class(env, x, model, physical_class_two, s_s_size, s_s_t_time_number, time_index, stu_physical_zhong);
			one_teacher_one_time_one_class(env, x, model, physical_class_three, s_s_size, s_s_t_time_number, time_index, stu_physical_zhong);
			one_teacher_one_time_one_class(env, x, model, physical_class_four, s_s_size, s_s_t_time_number, time_index, stu_physical_zhong);
			one_teacher_one_time_one_class(env, x, model, physical_class_five, s_s_size, s_s_t_time_number, time_index, stu_physical_zhong);
			one_teacher_one_time_one_class(env, x, model, physical_class_six, s_s_size, s_s_t_time_number, time_index, stu_physical_zhong);

			//生物
			one_teacher_one_time_one_class(env, x, model, biogical_class_one, s_s_size, s_s_t_time_number, time_index, stu_biological);
			one_teacher_one_time_one_class(env, x, model, biogical_class_two, s_s_size, s_s_t_time_number, time_index, stu_biological);
			one_teacher_one_time_one_class(env, x, model, biogical_class_three, s_s_size, s_s_t_time_number, time_index, stu_biological);
			//地理
			one_teacher_one_time_one_class(env, x, model, geography_class_one, s_s_size, s_s_t_time_number, time_index, stu_geography);
			one_teacher_one_time_one_class(env, x, model, geography_class_two, s_s_size, s_s_t_time_number, time_index, stu_geography);
			one_teacher_one_time_one_class(env, x, model, geography_class_three, s_s_size, s_s_t_time_number, time_index, stu_geography);
		}
		//化学 同一个时间最多只有六个老师上课
		for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
			IloExpr expr(env);
			for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
				if (sub_index%Subject_number == stu_chemistry_zhong) {
					int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
					expr += x[x_index];
				}
			}
			model.add(expr <= 6);
		}
		//历史 同一个时间最多只有4个老师上课
		for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
			IloExpr expr(env);
			for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
				if (sub_index%Subject_number == stu_history_hui|| sub_index%Subject_number ==stu_history_zhong ) {
					int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
					expr += x[x_index];
				}
			}
			model.add(expr <= 4);
		}
		//政治 同一个时间最多只有4个老师上课
		for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
			IloExpr expr(env);
			for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
				if (sub_index%Subject_number == stu_political_hui || sub_index%Subject_number == stu_political_zhong) {
					int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
					expr += x[x_index];
				}
			}
			model.add(expr <= 4);
		}
	}

	void create_model(vector<student>all_student,
		vector<vector<int>>stu_subject, int s_s_size, int s_s_row_number, int s_s_col_number,
		vector<vector<int>>subject_time, int c_t_size, int c_t_row_number, int c_t_col_number,
		int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
	{
		IloEnv env;
		IloNumVarArray x(env);
		IloModel model(env);
		create_student_subject_var(all_student, env, x, stu_subject, s_s_size, s_s_row_number, s_s_col_number);
		create_subject_time_var(env, x, subject_time, c_t_size, c_t_row_number, c_t_col_number);
		create_student_subject_time_var(all_student, env, x, s_s_size, c_t_size, s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		change_x_range(all_student, env, x, s_s_size, s_s_row_number, s_s_col_number, c_t_size, c_t_row_number, c_t_col_number, s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		set_x_name(x, s_s_size, c_t_size, s_s_t_size);
		create_constraint_one(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_two(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_three(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_four(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_five(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_six(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_seven(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_eight(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
		create_constraint_nine(all_student, env, x, model,
			s_s_size, s_s_row_number, s_s_col_number,
			c_t_size, c_t_row_number, c_t_col_number,
			s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);
	
		try
		{

			IloExpr obj(env);
			cout << x.getSize() << endl;
			for (int i = 0; i < s_s_t_student_number; i++) {
				for (int j = 0; j < s_s_t_subject_number; j++) {
					for (int k = 0; k < s_s_t_time_number; k++) {
						int x_index = s_s_size + c_t_size + i*s_s_t_subject_number*s_s_t_time_number + j*s_s_t_time_number + k;

						obj += x[x_index];
					}
				}
			}
			model.add(IloMaximize(env, obj));
			IloCplex cplex(model);
			bool ismip = cplex.isMIP();
			cout << " Is Mip " << ismip << endl;
			string name = "ss_people_" + to_string(all_student.size()) + "_Pe_constraint_" + to_string(pe_student_number) + "_non_pe_contraint_" + to_string(non_pe_student_number) + "_room_" + to_string(classroom_number) + "_subject_size_" + to_string(Subject_number) + ".lp";
			cplex.exportModel(name.c_str());
			cplex.solve();
			IloNumArray vals(env);
			env.out() << "Solution status = " << cplex.getStatus() << endl;
			env.out() << "Solution value  = " << cplex.getObjValue() << endl;
			cplex.getValues(vals, x);
			ofstream file("rs.txt");
			for (int i = 0; i < s_s_size + c_t_size + s_s_t_size; i++) {
				file << fixed << (vals[i]) << endl;

			}
			file.close();


		}
		catch (IloException e) {
			cerr << "Concert exception caught: " << e << endl;
		}


	}

	void start_optimize(int old_student_size) {

		vector<student>all_student = get_stu();
		cout << "学生数目" << all_student.size() << endl;
		int const stu_subject_row_number = all_student.size();
		int const stu_subject_col_number = 12 * Subject_number;
		vector<vector<int>>stu_subject = create_student_class(old_student_size, all_student, stu_subject_row_number, stu_subject_col_number);
		int const subject_time_row_numer = 12 * Subject_number;
		int const subject_time_col_numer = 40;
		vector<vector<int>>subject_time = create_subject_time(old_student_size, subject_time_row_numer, subject_time_col_numer);
		create_model(all_student,
			stu_subject, stu_subject_row_number*stu_subject_col_number, stu_subject_row_number, stu_subject_col_number,
			subject_time, subject_time_row_numer*subject_time_col_numer, subject_time_row_numer, subject_time_col_numer,
			stu_subject_row_number*stu_subject_col_number*subject_time_col_numer, stu_subject_row_number, stu_subject_col_number, subject_time_col_numer);

	}


}