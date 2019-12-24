//#include <iostream>
//#include <sstream>
//#include <vector>
//#include <fstream>
//#include <string> 
//#include <ilcplex/ilocplex.h>
//using namespace std;
//static const bool Elective = true;
//static const bool Non_Elective = false;
//static const int Subject_number = 16;//ÿ����γ̵���Ŀ
//static const int Must_choose = 5;
//static const int stu_chinese = 0;
//static const int stu_math = 1;
//static const int stu_english = 2;
//static const int stu_music = 3;
//static const int stu_art = 4;
//static const int stu_pe = 5;
//static const int stu_physical_zhong = 6;
//static const int stu_chemistry_zhong = 7;
//static const int stu_biological = 8;
//static const int stu_political_zhong = 9;
//static const int stu_history_zhong = 10;
//static const int stu_geography = 11;
//static const int stu_physical_hui = 12;
//static const int stu_chemistry_hui = 13;
//static const int stu_political_hui = 14;
//static const int stu_history_hui = 15;
//
//class student {
//public:
//	int stu_id;
//	string stu_name;
//	int stu_class;
//	bool stu_chinese = Elective;
//	bool stu_math = Elective;
//	bool stu_english = Elective;
//	bool stu_pe = Elective;
//	bool stu_music = Elective;
//	bool stu_art = Elective;
//	bool stu_physical_zhong = Non_Elective;
//	bool stu_physical_hui = Non_Elective;
//	bool stu_chemistry_zhong = Non_Elective;
//	bool stu_chemistry_hui = Non_Elective;
//	bool stu_biological = Non_Elective;
//	bool stu_political_zhong = Non_Elective;
//	bool stu_political_hui = Non_Elective;
//	bool stu_history_zhong = Non_Elective;
//	bool stu_history_hui = Non_Elective;
//	bool stu_geography = Non_Elective;
//	bool stu_class_number = Non_Elective;
//};
//vector<student> get_stu() {
//	vector<student> all_student;
//	fstream f("class.txt");
//	string temp;
//	while (getline(f, temp, '\n')) {
//		istringstream in;
//		in.str(temp);
//		student t;
//		in >> t.stu_id >> t.stu_name >> t.stu_class >> t.stu_chinese >> t.stu_math >> t.stu_english >> t.stu_music >> t.stu_art >> t.stu_pe;
//		in >> t.stu_physical_zhong >> t.stu_chemistry_zhong >> t.stu_biological >> t.stu_political_zhong >> t.stu_history_zhong >> t.stu_geography;
//		in >> t.stu_physical_hui >> t.stu_chemistry_hui >> t.stu_political_hui >> t.stu_history_hui >> t.stu_class_number;
//		all_student.push_back(t);
//	}
//	return all_student;
//}
//vector<vector<int>>create_student_class(vector<student>&all_student, int const &row_number, int const &col_number) {
//	vector<vector<int>>stu_subject(row_number, vector<int>(col_number, 0));
//	int stu_size = all_student.size();
//	//row
//	for (int stu_index = 0; stu_index < stu_size; stu_index++) {
//		int group_numner = all_student.at(stu_index).stu_class;
//		int current_col_number = Subject_number*(group_numner - 1);
//		//col
//		for (int i = current_col_number; i < current_col_number + Must_choose; i++) {
//			stu_subject[stu_index][i] = 1;
//		}
//	}
//	return stu_subject;
//}
//vector<vector<int>>create_subject_time(int const &row_number, int const &col_number) {
//	vector<vector<int>>subject_time(row_number, vector<int>(col_number, 0));
//	return subject_time;
//}
//void create_x(IloEnv &env, IloNumVarArray &x, IloModel &model,vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	for (int i = 0; i < s_c_size + c_t_size; i++) {
//		if (i < s_c_size) {
//			//ѧ��-�γ�
//			int current_row = i / s_c_col_number;
//			int current_col = i - s_c_col_number*current_row;
//			//ÿ���༶��Ӧ�� ���� ��ѧ Ӣ�� ���� ����
//			if (stu_subject[current_row][current_col] == 1) {
//				x.add(IloNumVar(env, 1, 1, ILOINT));
//			}
//			else {
//				//�����п���3���� 4-12Ϊ0   ,
//				if (current_col % Subject_number == stu_political_zhong&&current_col>(Subject_number * 3 - 1)) {
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//��ʷ�п���4����  5-12Ϊ0
//				else if (current_col % Subject_number == stu_history_zhong&&current_col>(Subject_number * 4 - 1)) {
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//�����п���7���� 8-12Ϊ0
//				else if (current_col % Subject_number == stu_geography&&current_col>(Subject_number * 7 - 1)) {
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//��ѧ�п���11����
//				else if (current_col % Subject_number == stu_chemistry_zhong&&current_col>(Subject_number * 11 - 1))
//				{
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//�����п���11����
//				else if (current_col % Subject_number == stu_biological&&current_col>(Subject_number * 11 - 1))
//				{
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//����ῼ��1����
//				else if (current_col % Subject_number == stu_physical_hui&&current_col>(Subject_number * 1 - 1))
//				{
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//��ѧ�ῼ��2����
//				else if (current_col % Subject_number == stu_chemistry_hui&&current_col>(Subject_number * 2 - 1))
//				{
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//���λῼ��9����
//				else if (current_col % Subject_number == stu_political_hui&&current_col>(Subject_number * 9 - 1))
//				{
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//��ʷ�ῼ��8����
//				else if (current_col % Subject_number == stu_history_hui&& current_col>(Subject_number * 8 - 1))
//				{
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				//������������
//				else if (current_col % Subject_number == stu_pe&& current_col>(Subject_number * 2 - 1)) {
//					x.add(IloNumVar(env, 0, 0, ILOINT));
//				}
//				else {
//					//����ÿ���༶��Ӧ������ ��ѧ Ӣ�� ���� ��������Ϊ0
//					if (current_col % Subject_number == stu_chinese
//						|| current_col % Subject_number == stu_math
//						|| current_col % Subject_number == stu_english
//						|| current_col % Subject_number == stu_music
//						|| current_col % Subject_number == stu_art) {
//						x.add(IloNumVar(env, 0, 0, ILOINT));
//					}
//					else {
//						x.add(IloNumVar(env, 0, 1, ILOINT));
//					}
//				}
//			}
//		}
//		else {
//			//�γ�-ʱ��
//			int current_relative_x_index = i - s_c_size;
//			int current_row = current_relative_x_index / c_t_col_number;
//			int current_col = current_relative_x_index - c_t_col_number*current_row;
//			if (current_row%Subject_number == stu_political_zhong&&current_row > (Subject_number * 3 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_history_zhong&&current_row > (Subject_number * 4 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_geography&&current_row > (Subject_number * 7 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_chemistry_zhong&&current_row > (Subject_number * 11 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_biological&&current_row > (Subject_number * 11 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_physical_hui&&current_row > (Subject_number * 1 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_chemistry_hui&&current_row > (Subject_number * 2 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_political_hui&&current_row > (Subject_number * 9 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_history_hui&&current_row > (Subject_number * 8 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else if (current_row%Subject_number == stu_pe&&current_row > (Subject_number * 2 - 1)) {
//				x.add(IloNumVar(env, 0, 0, ILOINT));
//			}
//			else {
//				x.add(IloNumVar(env, 0, 1, ILOINT));
//			}
//		}
//	}
//	
//	//���ñ���������
//	for (int i = 0; i < s_c_size + c_t_size; i++) {
//		string x_name = "x" + to_string(i);
//		x[i].setName(x_name.c_str());
//	}
//}
//void change_x_range(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	//��ѧ����ѡ�Ŀγ�����Ϊ0
//	for (int stu_index= 0; stu_index < all_student.size(); stu_index++) {
//		//��ѡ�������п�
//		if (all_student.at(stu_index).stu_physical_zhong == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_physical_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//		//��ѡ��ѧ�п�
//		if (all_student.at(stu_index).stu_chemistry_zhong == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_chemistry_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//		//��ѡ�������п�
//		if (all_student.at(stu_index).stu_biological == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_biological) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//		//��ѡ�������п�
//		if (all_student.at(stu_index).stu_political_zhong == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_political_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//		//��ѡ����ʷ�п�
//		if (all_student.at(stu_index).stu_history_zhong == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_history_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//		//��ѡ���˵����п�
//		if (all_student.at(stu_index).stu_geography == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_geography) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//		//��ѡ������ῼ
//		if (all_student.at(stu_index).stu_physical_hui == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_physical_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//		//��ѡ��ѧ�ῼ
//		if (all_student.at(stu_index).stu_chemistry_hui == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_chemistry_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//
//		}
//		//��ѡ�����λῼ
//		if (all_student.at(stu_index).stu_political_hui == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_political_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//
//		}
//		//��ѡ����ʷ�ῼ
//		if (all_student.at(stu_index).stu_history_hui == Non_Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_history_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					x[x_index].setBounds(0, 0);
//				}
//			}
//		}
//
//	}
//}
//void create_constraint_one(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	//������
//	stringstream ints{ "[50,270]" };
//	IloNumArray subject_capacity(env);
//	ints >> subject_capacity;
//	//���ܳ���ÿ�ſ�����������
//	//��(i)stu_subject[i][j]<=subject_capacity[j]
//	for (int col_index = 0; col_index < s_c_col_number; col_index++) {
//		IloExpr expr(env);
//		for (int row_index = 0; row_index < s_c_row_number; row_index++) {
//			int x_index = row_index*s_c_col_number + col_index;
//			expr += x[x_index];
//		}
//		if (col_index%Subject_number == stu_pe)
//			model.add(expr <= subject_capacity[1]);
//		else {
//			model.add(expr <= subject_capacity[0]);
//		}
//	}
//}
//void create_constraint_two(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	//ͬ���Ŀ����ѡһ��
//	//��(j)stu_subject[i][j]=1
//	IloNumArray student_with_one_class(env);
//	stringstream ints3{ "[1]" };
//	ints3 >> student_with_one_class;
//	for (int stu_index = 0; stu_index < all_student.size(); stu_index++) {
//		//ѡ���������п�
//		if (all_student.at(stu_index).stu_physical_zhong == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_physical_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ���˻�ѧ�п�
//		if (all_student.at(stu_index).stu_chemistry_zhong == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_chemistry_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ���������п�
//		if (all_student.at(stu_index).stu_biological == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_biological) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//
//		}
//		//ѡ���������п�
//		if (all_student.at(stu_index).stu_political_zhong == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_political_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ������ʷ�п�
//		if (all_student.at(stu_index).stu_history_zhong == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_history_zhong) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ���˵����п�
//		if (all_student.at(stu_index).stu_geography == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_geography) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ��������ῼ
//		if (all_student.at(stu_index).stu_physical_hui == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_physical_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ���˻�ѧ�ῼ
//		if (all_student.at(stu_index).stu_chemistry_hui == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_chemistry_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ�������λῼ
//		if (all_student.at(stu_index).stu_political_hui == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_political_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ������ʷ�ῼ
//		if (all_student.at(stu_index).stu_history_hui == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_history_hui) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ��������
//		if (all_student.at(stu_index).stu_pe == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_pe) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ��������
//		if (all_student.at(stu_index).stu_chinese == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_chinese) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ������ѧ
//		if (all_student.at(stu_index).stu_math == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_math) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ����Ӣ��
//		if (all_student.at(stu_index).stu_english == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_english) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ��������
//		if (all_student.at(stu_index).stu_music == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_music) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//		//ѡ��������
//		if (all_student.at(stu_index).stu_art == Elective) {
//			IloExpr expr(env);
//			for (int i = 0; i < s_c_col_number; i++) {
//				if (i%Subject_number == stu_art) {
//					int x_index = stu_index*s_c_col_number + i;
//					expr += x[x_index];
//				}
//			}
//			model.add(expr == student_with_one_class[0]);
//		}
//	}
//}
//void create_constraint_three(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	stringstream ints2{ "[6,6,5,1,1,3,5,5,2,3,3,2,3,3,2,2]" };
//	IloNumArray credit(env);
//	ints2 >> credit;
//	//���Լ��
//	//����ÿ�ſο�ʱ��Լ��
//	//��(j)subject_time[i][j]==credit[j]
//	for (int row_index = 0; row_index < c_t_row_number; row_index++) {
//		IloExpr expr(env);
//		for (int col_index = 0; col_index < c_t_col_number; col_index++) {
//			int x_index = s_c_size + row_index*c_t_col_number + col_index;
//			expr += x[x_index];
//		}
//		if (row_index%Subject_number == stu_political_zhong&&row_index > (Subject_number * 3 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_history_zhong&&row_index >(Subject_number * 4 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_geography&&row_index > (Subject_number * 7 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_chemistry_zhong&&row_index > (Subject_number * 11 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_biological&&row_index > (Subject_number * 11 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_physical_hui&&row_index > (Subject_number * 1 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_chemistry_hui&&row_index > (Subject_number * 2 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_political_hui&&row_index > (Subject_number * 9 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_history_hui&&row_index > (Subject_number * 8 - 1)) {
//			continue;
//		}
//		else if (row_index%Subject_number == stu_pe&&row_index >(Subject_number * 2 - 1)) {
//			continue;
//		}
//		else {
//			model.add(expr == credit[row_index%Subject_number]);
//		}
//
//	}
//}
//void create_constraint_four(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	//ͬʱ�Ͽεİ༶��<=14
//	//��(i)subject_time[i][j]<=14
//	IloNumArray room_number(env);
//	stringstream ints4{ "[16]" };
//	ints4 >> room_number;
//	for (int col_index = 0; col_index < c_t_col_number; col_index++) {
//		IloExpr expr(env);
//		for (int row_index = 0; row_index < c_t_row_number; row_index++) {
//			int x_index = s_c_size + row_index*c_t_col_number + col_index;
//			expr += x[x_index];
//		}
//		model.add(expr <= room_number[0]);
//	}
//
//}
//void create_constraint_five(IloEnv &env, IloNumVarArray &x, IloModel &model, vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	//һ��ѧ����һ��ʱ�����ֻ����һ�ſ�
//	IloNumArray stu_class_time_r(env);
//	stringstream ints5{ "[1]" };
//	ints5 >> stu_class_time_r;
//	int current_x_size = x.getSize();
//	//ѧ���γ̵�һ��
//	for (int s_c_row_index = 0; s_c_row_index < s_c_row_number; s_c_row_index++) {
//		//�γ�ʱ���һ��
//		for (int c_r_col_index = 0; c_r_col_index < c_t_col_number; c_r_col_index++) {
//			//��ͬ��ά��
//			IloExpr expr(env);
//			for (int k = 0; k < s_c_col_number; k++) {
//				x.add(IloNumVar(env, 0, 1, ILOINT));
//				string x_name = "x" + to_string(current_x_size);
//				x[current_x_size].setName(x_name.c_str());
//				int x_index_of_s_c = s_c_row_index*s_c_col_number + k;
//				int x_index_of_c_t = s_c_size + k*c_t_col_number + c_r_col_index;
//				expr += x[current_x_size];
//				//��������Լ��
//				model.add(x[current_x_size] <= x[x_index_of_s_c]);
//				model.add(x[current_x_size] <= x[x_index_of_c_t]);
//				IloExpr expr_4(env);
//				expr_4 += 1;
//				expr_4 += x[current_x_size];
//				expr_4 -= x[x_index_of_s_c];
//				model.add(expr_4 >= x[x_index_of_c_t]);
//				++current_x_size;//������Ŀ����
//			}
//			model.add(expr <= stu_class_time_r[0]);
//		}
//	}
//}
//void create_model(vector<student>all_student, vector<vector<int>>stu_subject, vector<vector<int>>subject_time, int s_c_size, int s_c_row_number, int s_c_col_number, int c_t_size, int c_t_row_number, int c_t_col_number) {
//	IloEnv env;
//	IloNumVarArray x(env);
//	IloModel model(env);
//	//Ŀ�꺯��
//	model.add(IloMaximize(env, 0));
//
//	create_x(env,x,model, all_student, stu_subject, subject_time, s_c_size, s_c_row_number, s_c_col_number, c_t_size, c_t_row_number, c_t_col_number);
//	
//	change_x_range(env, x, model, all_student, stu_subject, subject_time, s_c_size, s_c_row_number, s_c_col_number, c_t_size, c_t_row_number, c_t_col_number);
//
//	create_constraint_one(env, x, model, all_student, stu_subject, subject_time, s_c_size, s_c_row_number, s_c_col_number, c_t_size, c_t_row_number, c_t_col_number);
//
//	create_constraint_two(env, x, model, all_student, stu_subject, subject_time, s_c_size, s_c_row_number, s_c_col_number, c_t_size, c_t_row_number, c_t_col_number);
//	
//	create_constraint_three(env, x, model, all_student, stu_subject, subject_time, s_c_size, s_c_row_number, s_c_col_number, c_t_size, c_t_row_number, c_t_col_number);
//	
//	create_constraint_four(env, x, model, all_student, stu_subject, subject_time, s_c_size, s_c_row_number, s_c_col_number, c_t_size, c_t_row_number, c_t_col_number);
//	
//	create_constraint_five(env, x, model, all_student, stu_subject, subject_time, s_c_size, s_c_row_number, s_c_col_number, c_t_size, c_t_row_number, c_t_col_number);
//
//
//	IloCplex cplex(model);
//	try
//	{
//		//cplex.setParam();
//		bool ismip = cplex.isMIP();
//		cout << " Is Mip " << ismip << endl;
//		cplex.exportModel("�ſ�.lp");
//		cplex.solve();
//		IloNumArray vals(env);
//		env.out() << "Solution status = " << cplex.getStatus() << endl;
//		env.out() << "Solution value  = " << cplex.getObjValue() << endl;
//		cplex.getValues(vals, x);
//		//env.out() << "Values        = " << vals << endl;
//	}
//	catch (IloException e) {
//		cerr << "Concert exception caught: " << e << endl;
//	}
//	
//}
//int main() {
//	vector<student>all_student = get_stu();
//	int const stu_subject_row_number = 510;
//	int const stu_subject_col_number = 12 *Subject_number;
//	vector<vector<int>>stu_subject = create_student_class(all_student, stu_subject_row_number, stu_subject_col_number);
//	int const subject_time_row_numer = 12 * Subject_number;
//	int const subject_time_col_numer = 40;
//	vector<vector<int>>subject_time = create_subject_time(subject_time_row_numer, subject_time_col_numer);
//	create_model(all_student, stu_subject, stu_subject, 510 * 12 * Subject_number, 510, 12 * Subject_number, 40 * 12 * Subject_number, 12 * Subject_number, 40);
//}