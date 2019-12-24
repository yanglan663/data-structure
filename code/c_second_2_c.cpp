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

extern int pe_student_number ;
extern int non_pe_student_number ;
extern int classroom_number ;
extern int all_student_number_mod ;
extern int student_number_lower_bound ;
extern vector<int>subject_people_size;
//设置不开的班的课程对应的变量为0
void create_student_subject_var(vector<student>&all_studen, IloEnv &env, IloNumVarArray &x, vector<vector<int>>stu_subject, int s_s_size, int s_s_row_number, int s_s_col_number) {
	for (int x_index = 0; x_index < s_s_size; x_index++) {
		int current_row = x_index / s_s_col_number;
		int current_col = x_index - s_s_col_number*current_row;
		if (stu_subject[current_row][current_col] == 1) {
			x.add(IloNumVar(env, 1, 1, ILOINT));
		}
		else {
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
			//历史会考开8个班
			else if (current_col % Subject_number == stu_history_hui&& current_col>(Subject_number * stu_history_hui_class_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			//体育开2个班
			else if (current_col % Subject_number == stu_pe&& current_col>(Subject_number * stu_pe_class_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else if (current_col % Subject_number == stu_physical_zhong&& current_col>(Subject_number * stu_physical_zhong_numbers - 1))
			{
				x.add(IloNumVar(env, 0, 0, ILOINT));
			}
			else {
				//不是每个班级对应的语文 数学 英语 音乐 美术 设置为0
				if (current_col % Subject_number == stu_chinese
					|| current_col % Subject_number == stu_math
					|| current_col % Subject_number == stu_english
					|| current_col % Subject_number == stu_music
					|| current_col % Subject_number == stu_art
					|| current_col % Subject_number == stu_physical_zhong
					/*|| current_col % Subject_number == stu_chemistry_zhong*/
					|| current_col % Subject_number == stu_pe) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else {
					x.add(IloNumVar(env, 0, 1, ILOINT));
				}
			}
		}
	}
}
void create_subject_time_var(IloEnv &env, IloNumVarArray &x, int c_t_size, int c_t_row_number, int c_t_col_number) {
	for (int x_index = 0; x_index <c_t_size; x_index++) {
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
			x.add(IloNumVar(env, 0, 1, ILOINT));
		}
	}
}
void create_student_subject_time_var(vector<student>all_student, IloEnv &env, IloNumVarArray &x, int s_s_size, int c_t_size, int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number) {

	for (int stu_index = 0; stu_index< s_s_t_student_number; stu_index++) {
		for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
			for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
				int x_index = s_s_size + c_t_size + stu_index*s_s_t_subject_number*s_s_t_time_number + sub_index*s_s_t_time_number + time_index;

				if (sub_index%Subject_number == stu_political_zhong&&sub_index >(Subject_number * stu_political_zhong_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_history_zhong&&sub_index >(Subject_number * stu_history_zhong_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_geography&&sub_index >(Subject_number * stu_geography_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_chemistry_zhong&&sub_index >(Subject_number * stu_chemistry_zhong_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_biological&&sub_index >(Subject_number * stu_biological_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_physical_hui&&sub_index >(Subject_number * stu_physical_hui_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_chemistry_hui&&sub_index >(Subject_number * stu_chemistry_hui_class_numbers - 1)) {

					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_political_hui&&sub_index >(Subject_number * stu_political_hui_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_history_hui&&sub_index >(Subject_number * stu_history_hui_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_pe&&sub_index >(Subject_number * stu_pe_class_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else if (sub_index%Subject_number == stu_physical_zhong&&sub_index >(Subject_number * stu_physical_zhong_numbers - 1)) {
					x.add(IloNumVar(env, 0, 0, ILOINT));
				}
				else
				{
					//不是每个班级对应的语文 数学 英语 音乐 美术 设置为0
					if (sub_index % Subject_number == stu_chinese
						|| sub_index % Subject_number == stu_math
						|| sub_index % Subject_number == stu_english
						|| sub_index % Subject_number == stu_music
						|| sub_index % Subject_number == stu_art
						|| sub_index % Subject_number == stu_physical_zhong
					/*	|| sub_index % Subject_number == stu_chemistry_zhong*/
						|| sub_index % Subject_number == stu_pe) {
						if (all_student.at(stu_index).stu_class != (sub_index / Subject_number + 1)) {
							x.add(IloNumVar(env, 0, 0, ILOINT));
						}
						else {
							x.add(IloNumVar(env, 0, 1, ILOINT));
						}
					}
					else {
						x.add(IloNumVar(env, 0, 1, ILOINT));
					}
				}
			}
		}
	}
}
//使subject_id对应的变量，设置为0
void change_x_range_halp(IloNumVarArray &x,int s_s_size, int c_t_size, int s_s_t_subject_number, int s_s_t_time_number,int stu_index,int subject_id) {
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == subject_id) {
			int x_first_index = stu_index*s_s_t_subject_number + sub_index;
			x[x_first_index].setBounds(0, 0);
			for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
				int x_third = s_s_size + c_t_size;
				x_third += stu_index*s_s_t_subject_number*s_s_t_time_number + sub_index*s_s_t_time_number + time_index;
				x[x_third].setBounds(0, 0);
			}
		}
	}
}
//将没有选择的课设置为0
void change_x_range(vector<student>all_student, IloEnv &env, IloNumVarArray &x,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
{
	
	for (int stu_index = 0; stu_index < all_student.size(); stu_index++) {
		//没有选择化学中考
		if (all_student.at(stu_index).stu_chemistry_zhong == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_chemistry_zhong);

		}
		//没有选择化学会考
		if (all_student.at(stu_index).stu_chemistry_hui == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_chemistry_hui);

		}
		//没有选择历史中考
		if (all_student.at(stu_index).stu_history_zhong == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_history_zhong);

		}
		//没有选择历史会考
		if (all_student.at(stu_index).stu_history_hui == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_history_hui);

		}
		//如果没有选择物理中考
		if (all_student.at(stu_index).stu_physical_zhong == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_physical_zhong);

		}
		//如果没有选择物理会考
		if (all_student.at(stu_index).stu_physical_hui == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_physical_hui);

		}
		//如果没有选择政治中考
		if (all_student.at(stu_index).stu_political_zhong == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_political_zhong);

		}
		//没有选择政治中考
		if (all_student.at(stu_index).stu_political_hui == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_political_hui);

		}
		//没有选择地理
		if (all_student.at(stu_index).stu_geography == Non_Elective ) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_geography);

		}
		//没有选择生物
		if ( all_student.at(stu_index).stu_biological == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_biological);

		}
		//没有选择体育
		if (all_student.at(stu_index).stu_pe == Non_Elective) {
			change_x_range_halp(x, s_s_size, c_t_size, s_s_t_subject_number, s_s_t_time_number, stu_index, stu_pe);

		}
	}
}
void set_x_name(IloNumVarArray &x, int s_s_size, int c_t_size, int s_s_t_size) {
	
	for (int i = 0; i < s_s_size + c_t_size + s_s_t_size; i++) {
		string x_name = "x" + to_string(i);
		x[i].setName(x_name.c_str());
	}

}
//满足课容量的约束
void create_constraint_one(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
{
	//第一张表
	stringstream subject_capacity_ints; //{ "[51,51]" };
	subject_capacity_ints << "[";
	for (auto i = 0; i < subject_people_size.size(); i++) {
		subject_capacity_ints << subject_people_size.at(i);
		if (i == subject_people_size.size() - 1)
			break;
		subject_capacity_ints << ",";
	}
	subject_capacity_ints << "]";
	IloNumArray subject_capacity(env);
	subject_capacity_ints >> subject_capacity;
	
	for (int sub_index = 0; sub_index < s_s_col_number; sub_index++) {
		//体育课
		IloExpr expr(env);
		if (sub_index%Subject_number == stu_chinese) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_chinese]);
		}
		else if (sub_index%Subject_number == stu_math) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_math]);
		}
		else if (sub_index%Subject_number == stu_english) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_english]);
		}
		else if (sub_index%Subject_number == stu_art) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_art]);
		}
		else if (sub_index%Subject_number == stu_music) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_music]);
		}
		else if (sub_index%Subject_number == stu_pe) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_pe]);
		}
		else if (sub_index%Subject_number == stu_physical_zhong) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_physical_zhong]);
		}
		else if (sub_index%Subject_number == stu_chemistry_zhong) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_chemistry_zhong]);
		}
		else if (sub_index%Subject_number == stu_biological) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_biological]);
		}
		else if (sub_index%Subject_number == stu_political_zhong) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_political_zhong]);
		}
		else if (sub_index%Subject_number == stu_history_zhong) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_history_zhong]);
		}
		else if (sub_index%Subject_number == stu_geography) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_geography]);
		}
		else if (sub_index%Subject_number == stu_physical_hui) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_physical_hui]);
		}
		else if (sub_index%Subject_number == stu_chemistry_hui) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_chemistry_hui]);
		}
		else if (sub_index%Subject_number == stu_political_hui) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_political_hui]);

		}
		else if (sub_index%Subject_number == stu_history_hui) {
			for (int stu_index = 0; stu_index < s_s_row_number; stu_index++) {
				int x_index = stu_index*s_s_col_number + sub_index;
				expr += x[x_index];
			}
			model.add(expr <= subject_capacity[stu_history_hui]);

		}


	}
}


//关联表一和表三
void combine_student_subject_with_student_subject_time(IloEnv &env, IloNumVarArray &x, IloModel &model, int stu_index, int sub_index, IloNumArray credit,
	int s_s_size,
	int c_t_size,
	int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number, int x_index_one) {
	IloExpr expr_one_and_three(env);
	for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
		int x_index_three = s_s_size + c_t_size + stu_index*s_s_t_subject_number*s_s_t_time_number + sub_index*s_s_t_time_number + time_index;
		expr_one_and_three += x[x_index_three];
	}
	
	model.add(expr_one_and_three == credit[sub_index%Subject_number] * x[x_index_one]);
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
//对开的课，学时求和，满足学时的要求
void create_constraint_three(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
{
	stringstream ints2{ "[6,6,5,1,1,3,5,5,2,3,3,2,3,3,1,1]" };
	IloNumArray credit(env);
	ints2 >> credit;
	for (int sub_index = 0; sub_index < c_t_row_number; sub_index++) {
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
			IloExpr expr(env);
			for (int time_index = 0; time_index < c_t_col_number; time_index++) {
				int x_index = s_s_size + sub_index*c_t_col_number + time_index;
				expr += x[x_index];
			}
			model.add(expr == credit[sub_index%Subject_number]);
		}
	}
}
//教室约束  单独考虑体育课
void create_constraint_four(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
{
	//第二张表
	IloNumArray room_number(env);
	stringstream ints4; //{ "[51]" };
	ints4 << "[";
	ints4 << classroom_number;
	ints4 << "]";
	ints4 >> room_number;

	for (int time_index = 0; time_index < c_t_col_number; time_index++) {
		IloExpr expr(env);
		for (int sub_index = 0; sub_index < c_t_row_number; sub_index++) {
			//体育课不占教室
			if (sub_index%Subject_number != stu_pe) {
				int x_index = s_s_size + sub_index*c_t_col_number + time_index;
				expr += x[x_index];
			}
		}
		//教室定值
		model.add(expr <= room_number[0]);
		
	}
	//第三张表
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		//cout << sub_index << endl;
		for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
			int x_index_two = s_s_size + sub_index*c_t_col_number + time_index;
			IloExpr expr_l(env);
			expr_l += x[x_index_two];
			IloExpr expr_r(env);
			for (int stu_index = 0; stu_index < s_s_t_student_number; stu_index++) {
				int x_index_three = s_s_size + c_t_size + stu_index*s_s_t_subject_number*s_s_t_time_number + sub_index*s_s_t_time_number + time_index;
				expr_r += x[x_index_three];
			}
			if (sub_index%Subject_number == stu_chinese)
				model.add(expr_r <= subject_people_size[stu_chinese] * expr_l);
			else if (sub_index%Subject_number == stu_math) {
				model.add(expr_r <= subject_people_size[stu_math] * expr_l);
			}
			else if (sub_index%Subject_number == stu_english) {
				model.add(expr_r <= subject_people_size[stu_english] * expr_l);
			}
			else if (sub_index%Subject_number == stu_music) {
				model.add(expr_r <= subject_people_size[stu_music] * expr_l);
			}
			else if (sub_index%Subject_number == stu_art) {
				model.add(expr_r <= subject_people_size[stu_art] * expr_l);
			}
			else if (sub_index%Subject_number == stu_pe) {
				model.add(expr_r <= subject_people_size[stu_pe] * expr_l);
			}
			else if (sub_index%Subject_number == stu_physical_zhong) {
				model.add(expr_r <= subject_people_size[stu_physical_zhong] * expr_l);
			}
			else if (sub_index%Subject_number == stu_chemistry_zhong) {
				model.add(expr_r <= subject_people_size[stu_chemistry_zhong] * expr_l);
			}
			else if (sub_index%Subject_number == stu_biological) {
				model.add(expr_r <= subject_people_size[stu_biological] * expr_l);
			}
			else if (sub_index%Subject_number == stu_political_zhong) {
				model.add(expr_r <= subject_people_size[stu_political_zhong] * expr_l);
			}
			else if (sub_index%Subject_number == stu_history_zhong) {
				model.add(expr_r <= subject_people_size[stu_history_zhong] * expr_l);
			}
			else if (sub_index%Subject_number == stu_geography) {
				model.add(expr_r <= subject_people_size[stu_geography] * expr_l);
			}
			else if (sub_index%Subject_number == stu_physical_hui) {
				model.add(expr_r <= subject_people_size[stu_physical_hui] * expr_l);
			}
			else if (sub_index%Subject_number == stu_chemistry_hui) {
				model.add(expr_r <= subject_people_size[stu_chemistry_hui] * expr_l);
			}
			else if (sub_index%Subject_number == stu_political_hui) {
				model.add(expr_r <= subject_people_size[stu_political_hui] * expr_l);
			}
			else if (sub_index%Subject_number == stu_history_hui) {
				model.add(expr_r <= subject_people_size[stu_history_hui] * expr_l);
			}
			model.add(expr_r >= student_number_lower_bound*expr_l);
		}
	}
}
//一个时间只能上一门课
void create_constraint_five(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
{
	stringstream ints{ "[1]" };
	IloNumArray stu_class_time_r(env);
	ints >> stu_class_time_r;
	for (int stu_index = 0; stu_index < s_s_t_student_number; stu_index++) {
		for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
			IloExpr expr_l(env);
			for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
				int x_index = s_s_size + c_t_size + stu_index*s_s_t_subject_number*s_s_t_time_number + sub_index*s_s_t_time_number + time_index;

				expr_l += x[x_index];
			}
			model.add(expr_l <= stu_class_time_r[0]);
		}
	}
}

//0 - 4	  8 - 12      16 - 20		24 - 27	 32 - 36
//生物    化学,音乐   语文				    美术地理历史
//
//5-7     13-15		21-23		28-31	    37-39	
//政治	英语	   物理					    数学
void chang_subject_time_bound(IloNumVarArray &x, int s_s_size, int c_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number,int sub_index,int left_time,int right_time) {
	for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
		if (time_index >= left_time && time_index <= right_time) {
			int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
			x[x_index].setBounds(0, 0);
		}
	}
}
//某门课，不能再某些时间开
void create_constraint_six(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
{
	//生物 0 - 4
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_biological) {
			int left_time = 0;
			int right_time = 4;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	////化学(中考，会考)8-12
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_chemistry_hui|| sub_index%Subject_number==stu_chemistry_zhong) {
			int left_time = 8;
			int right_time = 12;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//音乐(8-12)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_music) {
			int left_time = 8;
			int right_time = 12;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//语文(16-20)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_chinese) {
			int left_time = 16;
			int right_time = 20;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//美术(32-36)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_art) {
			int left_time = 32;
			int right_time = 36;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//地理(32-36)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_geography) {
			int left_time = 32;
			int right_time = 36;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//历史(32-36)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_history_hui|| sub_index%Subject_number == stu_history_zhong) {
			int left_time = 32;
			int right_time = 36;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//政治(5-7)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_political_hui || sub_index%Subject_number == stu_political_zhong) {
			int left_time = 5;
			int right_time = 7;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//英语(13-15)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_english) {
			int left_time = 13;
			int right_time = 15;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//物理(21-23)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_physical_zhong || sub_index%Subject_number == stu_physical_hui) {
			int left_time = 21;
			int right_time = 23;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
	//数学(37-39)
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number ==stu_math) {
			int left_time = 37;
			int right_time = 39;
			chang_subject_time_bound(x, s_s_size, c_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number, sub_index, left_time, right_time);
		}
	}
}

//课程联排
//语文 周五上午联排一次
//数学 周三上午联排一次
//英语 周二上午联排一次
//考虑课程-时间
void create_constraint_seven(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number) 
{
	
	//语文
	int firday_morning_first = 32;
	int firday_morning_second = 33;
	int firday_morning_third = 34;
	int firday_morning_fourth = 35;
	int firday_morning_fifth = 36;
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_chinese) {
			IloExpr expr_sum_equal_2(env);
			for (int time_index = firday_morning_first; time_index <= firday_morning_fifth; time_index++) {
				int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
				expr_sum_equal_2 += x[x_index];
			}
			//五节课求和等于2
			model.add(expr_sum_equal_2 == 2);
			//周五上午一二节联
			int x_index_without_timeindex = s_s_size + sub_index*s_s_t_time_number;
			model.add(x[x_index_without_timeindex+ firday_morning_first]- x[x_index_without_timeindex+ firday_morning_second]==0);
			//周五上午三四五节联排
			model.add(x[x_index_without_timeindex + firday_morning_third] + x[x_index_without_timeindex + firday_morning_fifth]<=1);
		}
	}
	//英语
	int tuesday_morning_first = 8;
	int tuesday_morning_second = 9;
	int tuesday_morning_third = 10;
	int tuesday_morning_fourth = 11;
	int tuesday_morning_fifth = 12;
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_english) {
			IloExpr expr_sum_equal_2(env);
			for (int time_index = tuesday_morning_first; time_index <= tuesday_morning_fifth; time_index++) {
				int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
				expr_sum_equal_2 += x[x_index];
			}
			//五节课求和等于2
			model.add(expr_sum_equal_2 == 2);
			//周二上午一二节联
			int x_index_without_timeindex = s_s_size + sub_index*s_s_t_time_number;
			model.add(x[x_index_without_timeindex + tuesday_morning_first] - x[x_index_without_timeindex + tuesday_morning_second] == 0);
			//周二上午三四五节联排
			model.add(x[x_index_without_timeindex + tuesday_morning_third] + x[x_index_without_timeindex + tuesday_morning_fifth] <= 1);
		}
	}
	//数学
	int wednesday_morning_first = 16;
	int wednesday_morning_second = 17;
	int wednesday_morning_third = 18;
	int wednesday_morning_fourth = 19;
	int wednesday_morning_fifth = 20;
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		if (sub_index%Subject_number == stu_math) {
			IloExpr expr_sum_equal_2(env);
			for (int time_index = wednesday_morning_first; time_index <= wednesday_morning_fifth; time_index++) {
				int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
				expr_sum_equal_2 += x[x_index];
			}
			//五节课求和等于2
			model.add(expr_sum_equal_2 == 2);
			//周三上午一二节联排
			int x_index_without_timeindex = s_s_size + sub_index*s_s_t_time_number;
			model.add(x[x_index_without_timeindex + wednesday_morning_first] - x[x_index_without_timeindex + wednesday_morning_second] == 0);
			//周三上午三四五节联排
			model.add(x[x_index_without_timeindex + wednesday_morning_third] + x[x_index_without_timeindex + wednesday_morning_fifth] <= 1);
		}
	}
	
}

//语文 数学 英语 除了联排日，一天各一节
//课程-时间表

void have_one_class_one_day_chinese_math(IloEnv &env, IloNumVarArray &x, IloModel &model, int s_s_size,int s_s_t_time_number,int sub_index,int left_time_index,int right_time_index) {
	IloExpr expr(env);
	for (int time_index = left_time_index; time_index <= right_time_index; time_index++) {
		int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
		expr += x[x_index];
	}
	model.add(expr == 1);

	
}
void have_one_class_one_day_not_chinese_and_math(IloEnv &env, IloNumVarArray &x, IloModel &model, int s_s_size, int s_s_t_time_number, int sub_index, int left_time_index, int right_time_index) {
	IloExpr expr(env);
	for (int time_index = left_time_index; time_index <= right_time_index; time_index++) {
		int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
		expr += x[x_index];
	}
	model.add(expr <= 1);


}
void create_constraint_eight(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number)
{
	

	for (int sub_index=0; sub_index < s_s_t_subject_number; sub_index++) {
		//语文周一 周二 周三 周四 各一节
		if (sub_index%Subject_number == stu_chinese) {
			//周一
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 21, 23);
			//周四
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
		}
		if (sub_index%Subject_number == stu_math) {
			//周一
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周四
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_chinese_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 36);
		}
		if (sub_index%Subject_number == stu_english) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_physical_zhong) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_chemistry_zhong) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_biological) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_political_zhong) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_history_zhong) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_geography) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_physical_hui) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_chemistry_hui) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_political_hui) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_history_hui) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		if (sub_index%Subject_number == stu_pe) {
			//周一
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 0, 7);
			//周二
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 8, 15);
			//周三
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 16, 23);
			//周四
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 24, 31);
			//周五
			have_one_class_one_day_not_chinese_and_math(env, x, model, s_s_size, s_s_t_time_number, sub_index, 32, 39);
		}
		
	}
}
//一个老师，一个时间，只能上一门课
void one_teacher_one_time_one_class(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<int>one_teacher_class_number, int s_s_size, int s_s_t_time_number, int time_index, int sub_number) {

	IloExpr music_class_one_left(env);
	for (int class_number : one_teacher_class_number) {
		int x_index = s_s_size + (class_number*Subject_number + sub_number)*s_s_t_time_number + time_index;
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
	vector<int>music_class_one { 1,10,11 };
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
	vector<int>math_class_two{9,10};
	vector<int>math_class_three{ 6,7 };
	vector<int>math_class_four{ 2,3 };
	vector<int>math_class_five{ 4,5 };
	vector<int>math_class_six{0,1 };
	//英语
	vector<int>english_class_one{ 0,2 };
	vector<int>english_class_two{ 9 ,11 };
	vector<int>english_class_three{ 1,3 };
	vector<int>english_class_four{ 4,6 };
	vector<int>english_class_five{ 5,7 };
	vector<int>english_class_six{ 8,10 };
	//物理中考
	vector<int>physical_class_one{ 1,8 };
	vector<int>physical_class_two{ 6,7};
	vector<int>physical_class_three{ 9,11 };
	vector<int>physical_class_four{ 0,2 };
	vector<int>physical_class_five{ 4,5 };
	vector<int>physical_class_six{ 3,10 };
	//生物
	vector<int>biogical_class_one{ 0,1,2 };
	vector<int>biogical_class_two{ 3,4,5,6 };
	vector<int>biogical_class_three{ 7,8,9,10 };

	for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
		//音乐
		one_teacher_one_time_one_class(env, x, model, music_class_one, s_s_size, s_s_t_time_number, time_index,stu_music);
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
	//生物 同一个时间最多只有三个老师上课
	for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
		IloExpr expr(env);
		for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
			if (sub_index%Subject_number == stu_biological) {
				int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
				expr += x[x_index];
			}
		}
		model.add(expr <= 3);
	}
	

}
//课程不能再[left_time right_tiem]间开
void help_constraint_ten(IloNumVarArray &x,int table_1_size,int s_s_t_time_number,int subject_index,int left_time,int right_time,int subject_id) {
	if (subject_index%Subject_number == subject_id) {
		for (int time_index = left_time; time_index <= right_time; time_index++) {
			int x_index = table_1_size + subject_index*s_s_t_time_number + time_index;
			x[x_index].setBounds(0, 0);
		}
	}

}
void help_connect_two_pe_class(IloModel &model,IloNumVarArray &x,vector<int>pe_class_1,int table_1_size,int subject_number,int time_number,int first_pe_id) {
	for (auto class_id : pe_class_1) {
		for (int sub_index = 0; sub_index < subject_number; sub_index++) {
			if (sub_index%Subject_number == stu_pe&&sub_index / Subject_number == class_id) {
				for (int time_index = 0; time_index < time_number; time_index++) {
					int x_index_class_one = table_1_size + first_pe_id*time_number + time_index;
					int x_index_class_other = table_1_size + sub_index*time_number + time_index;
					model.add(x[x_index_class_one] == x[x_index_class_other]);
				}
			}
		}
	}
	

}
void create_constraint_ten(vector<student>all_student, IloEnv &env, IloNumVarArray &x, IloModel &model,
	int s_s_size, int s_s_row_number, int s_s_col_number,
	int c_t_size, int c_t_row_number, int c_t_col_number,
	int s_s_t_size, int s_s_t_student_number, int s_s_t_subject_number, int s_s_t_time_number) {
	int left_time = -1;
	int right_time = -1;
	for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
		{

			//周一
			left_time = 5;
			right_time = 7;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chinese);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_math);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_english);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
			//周二
			left_time = 13;
			right_time = 15;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chinese);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_math);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_english);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
			//周三
			left_time = 20;
			right_time = 22;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_math);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_english);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			//体育
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, left_time, stu_pe);
			//周四
			left_time = 28;
			right_time = 31;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chinese);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_math);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_english);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
			//周五
			left_time = 36;
			right_time = 39;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chinese);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_math);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_english);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
		}
		
		{//物理中考 化学中考 不在8节开
			//周一
			left_time = 7;
			right_time = 7;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);
			//周二
			left_time = 15;
			right_time = 15;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);
			//周三
			left_time = 23;
			right_time = 23;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);

			//周四
			left_time = 31;
			right_time = 31;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);

			//周五
			left_time = 39;
			right_time = 39;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);

			//物理中考 化学中考 不在5节开
			//周一
			left_time = 4;
			right_time = 4;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);

			//周二
			left_time = 12;
			right_time = 12;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);

			//周三
			left_time = 20;
			right_time = 20;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);

			//周四
			left_time = 28;
			right_time = 28;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);

			//周五
			left_time = 36;
			right_time = 36;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);
		}
		{
			//音乐美术体育不在第一节开
			//周一
			left_time = 0;
			right_time = 0;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
			//周二
			left_time = 8;
			right_time = 8;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
			//周三
			left_time = 16;
			right_time = 16;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
			//周四
			left_time = 24;
			right_time = 24;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
			//周五
			left_time = 32;
			right_time = 32;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
		}
		{
			//语文 数学 英语 音乐 美术 物理中考 化学中考 化学会考 多一个空闲时间
			left_time = 3;
			right_time = 3;
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chinese);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_math);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_english);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_art);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_music);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_physical_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_chemistry_zhong);
			help_constraint_ten(x, s_s_size, s_s_t_time_number, sub_index, left_time, right_time, stu_pe);
		}
		{
		
			//化学只在两个时间段上课
			//课程--时间
			//0 1 3 4 7 9 班一个时间上化学
			vector<int>chemistry_classes_1{ 1,3,4,7,9};
			int first_chemistry_class_id = stu_chemistry_zhong;
			for (auto class_id : chemistry_classes_1) {
				for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
					if (sub_index%Subject_number == stu_chemistry_zhong&&sub_index / Subject_number == class_id) {
						for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
							int x_index_class_one = s_s_size + first_chemistry_class_id*s_s_t_time_number + time_index;
							int x_index_class_other = s_s_size + sub_index*s_s_t_time_number + time_index;
							model.add(x[x_index_class_one] == x[x_index_class_other]);
						}
					}
				}
			}
			//2 5 6 8 10 11班一个时间上化学
			vector<int>chemistry_classes_2{5,6,8,10,11};
			int second_chemistry_class_id = Subject_number*2+stu_chemistry_zhong;
			for (auto class_id : chemistry_classes_2) {
				for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
					if (sub_index%Subject_number == stu_chemistry_zhong&&sub_index / Subject_number == class_id) {
						for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
							int x_index_class_one = s_s_size + second_chemistry_class_id*s_s_t_time_number + time_index;
							int x_index_class_other = s_s_size + sub_index*s_s_t_time_number + time_index;
							model.add(x[x_index_class_one] == x[x_index_class_other]);
						}
					}
				}
			}

		}
		//体育合班
		{
			// 0 3
			vector<int>pe_class_1{ 3 };
			int one_pe_class_id =  stu_pe;
			help_connect_two_pe_class(model, x, pe_class_1, s_s_size, s_s_t_subject_number, s_s_t_time_number, one_pe_class_id);
			//1 2
			pe_class_1={ 2 };
			one_pe_class_id = Subject_number*1+stu_pe;
			help_connect_two_pe_class(model, x, pe_class_1, s_s_size, s_s_t_subject_number, s_s_t_time_number, one_pe_class_id);
			////4 7
			pe_class_1 = { 7};
			one_pe_class_id = Subject_number * 4 + stu_pe;
			help_connect_two_pe_class(model, x, pe_class_1, s_s_size, s_s_t_subject_number, s_s_t_time_number, one_pe_class_id);
			////5 6
			pe_class_1 = { 6};
			one_pe_class_id = Subject_number * 5 + stu_pe;
			help_connect_two_pe_class(model, x, pe_class_1, s_s_size, s_s_t_subject_number, s_s_t_time_number, one_pe_class_id);
			////8 11
			pe_class_1 = { 11 };
			one_pe_class_id = Subject_number * 8 + stu_pe;
			help_connect_two_pe_class(model, x, pe_class_1, s_s_size, s_s_t_subject_number, s_s_t_time_number, one_pe_class_id);
			////9 10
			pe_class_1 = { 10 };
			one_pe_class_id = Subject_number * 9 + stu_pe;
			help_connect_two_pe_class(model, x, pe_class_1, s_s_size, s_s_t_subject_number, s_s_t_time_number, one_pe_class_id);
			//任意一个时刻只有两个体育老师
			for (int time_index = 0; time_index < s_s_t_time_number; time_index++) {
				IloExpr expr(env);
				for (int sub_index = 0; sub_index < s_s_t_subject_number; sub_index++) {
					if (sub_index%Subject_number == stu_pe) {
						int x_index = s_s_size + sub_index*s_s_t_time_number + time_index;
						expr += x[x_index];
					}
				}
				model.add(expr <= 2);
			}
		}



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

	create_subject_time_var(env, x,c_t_size, c_t_row_number, c_t_col_number);



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
	create_constraint_ten(all_student, env, x, model,
		s_s_size, s_s_row_number, s_s_col_number,
		c_t_size, c_t_row_number, c_t_col_number,
		s_s_t_size, s_s_t_student_number, s_s_t_subject_number, s_s_t_time_number);

	try
	{

		/*IloExpr obj(env);
		cout << x.getSize() << endl;
		for (int i = 0; i < s_s_t_student_number; i++) {
			for (int j = 0; j < s_s_t_subject_number; j++) {
				for (int k = 0; k < s_s_t_time_number; k++) {
					int x_index = s_s_size + c_t_size + i*s_s_t_subject_number*s_s_t_time_number + j*s_s_t_time_number + k;
					
					obj += x[x_index];
				}
			}
		}*/
		model.add(IloMaximize(env, 0));
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

	//check_constraint(all_student, stu_subject, subject_time);
}


void start_optimize() {
	vector<student>all_student = get_stu();
	cout << "学生数目" << all_student.size() << endl;
	int const stu_subject_row_number = all_student.size();
	int const stu_subject_col_number = 12 * Subject_number;
	vector<vector<int>>stu_subject = create_student_class(all_student, stu_subject_row_number, stu_subject_col_number);
	int const subject_time_row_numer = 12 * Subject_number;
	int const subject_time_col_numer = 40;
	vector<vector<int>>subject_time = create_subject_time(subject_time_row_numer, subject_time_col_numer);
	create_model(all_student,
		stu_subject, stu_subject_row_number*stu_subject_col_number, stu_subject_row_number, stu_subject_col_number,
		subject_time, subject_time_row_numer*subject_time_col_numer, subject_time_row_numer, subject_time_col_numer,
		stu_subject_row_number*stu_subject_col_number*subject_time_col_numer, stu_subject_row_number, stu_subject_col_number, subject_time_col_numer);

}
void start_optimize(int old_student_size) {


	vector<student>all_student = get_stu();
	cout << "学生数目" << all_student.size() << endl;
	int const stu_subject_row_number = all_student.size();
	int const stu_subject_col_number = 12 * Subject_number;
	vector<vector<int>>stu_subject = create_student_class(all_student, stu_subject_row_number, stu_subject_col_number);
	int const subject_time_row_numer = 12 * Subject_number;
	int const subject_time_col_numer = 40;
	vector<vector<int>>subject_time = create_subject_time(old_student_size,subject_time_row_numer, subject_time_col_numer);
	create_model(all_student,
		stu_subject, stu_subject_row_number*stu_subject_col_number, stu_subject_row_number, stu_subject_col_number,
		subject_time, subject_time_row_numer*subject_time_col_numer, subject_time_row_numer, subject_time_col_numer,
		stu_subject_row_number*stu_subject_col_number*subject_time_col_numer, stu_subject_row_number, stu_subject_col_number, subject_time_col_numer);

}
//int main() {
//	start_optimize();
//}
