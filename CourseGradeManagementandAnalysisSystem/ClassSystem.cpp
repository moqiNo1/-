#include "ClassSystem.h"
void ClassSystem::operation()
{
	char choice;
	bool flag_oper = true;
	while (flag_oper)
	{
		system("cls");
		cout << "**************************************************************" << endl;
		cout << "*                   课程成绩管理与分析系统                   *" << endl;
		cout << "**************************************************************" << endl;
		cout << "*                      1:读入课程成绩                        *" << endl;
		cout << "*                      2:浏览学生成绩                        *" << endl;
		cout << "*                      3:查询学生成绩                        *" << endl;
		cout << "*                      4:修改学生成绩                        *" << endl;
		cout << "*                      5:补录学生成绩                        *" << endl;
		cout << "*                      6:删除学生成绩                        *" << endl;
		cout << "*                      7:保存修改成绩                        *" << endl;
		cout << "*                      8:统计课程成绩                        *" << endl;
		cout << "*                      9:保存统计数据                        *" << endl;
		cout << "*                      0:退出操作系统                        *" << endl;
		cout << "**************************************************************" << endl;
		cout << "请输入您的选择：";
		cin >> choice;
		switch (choice)
		{
		case '1':          readData();             break;
		case '2':          displayData();          break;
		case '3':          searchData();           break;
		case '4':          changeData();           break;
		case '5':          addData();              break;
		case '6':          deleteData();           break;
		case '7':          storeData();            break;
		case '8':          countData();            break;
		case '9':          saveScore();            break;
		case '0':       flag_oper = false;         break;
		default:cout << "无此选项，请重新输入" << endl; system("pause"); break;
		}

	}

}
int ClassSystem::readData()
{
	char choice;
	int flag_read;
	cout << "1.文件读取" << endl << "2.控制台输入" << endl;
	cout << "请输入您的选择（1或2）:";
	cin >> choice;
	switch (choice)
	{
	case '1': flag_read = readData_file(); break;
	case '2': flag_read = readData_input(); break;
	default:  flag_read = readData_file(); break;
	}
	if (flag_read) return 1;
	else return 0;
}
int ClassSystem::readData_file()
{
	ifstream infile("StudentScore.dat", ios::in | ios::_Nocreate);
	if (flag_data)
	{
		cout << "已经读入数据，不能重复读入" << endl;
		system("pause");
		return 0;
	}
	if (!infile)
	{
		cerr << "当前工程目录下不存在StudentScore.dat文件，打开失败！！！" << endl;
		infile.close();
		system("pause");
		return 0;
	}

	string temp;
	infile >> temp >> Course.coursename;
	infile >> temp >> Course.coursenum;
	infile >> temp >> Course.department;
	infile >> temp >> Course.teacher;
	infile >> temp >> Course.numstudent;
	for (int i = 1; i < 10;i++)
		infile >> temp;
	StudentInFor stemp;
	while (!infile.eof())
	{
		if (num_person < MAXPERSON)
		{
			infile >> stemp.student_number >> stemp.name >> stemp.sex;
			infile >> stemp.class_number;
			infile >> stemp.homework_score >> stemp.experiment_score >> stemp.report_score >> stemp.exam_score;

			if (!beExisting(stemp.student_number))
				conper[num_person++]=stemp;
		}
		else
		{
			cerr << "数据输入人数不能超过" << MAXPERSON << endl;
			break;
		}
	}
	flag_data = true;
	infile.close();
	cout << "共读入" << num_person << "条数据" << endl;
	system("pause");
    return 1;
}
int ClassSystem::beExisting(string pno)
{
	int flag_ex = 0;
	for (int i = 0; i < num_person; i++)
	{
		if (conper[i].student_number == pno)
		{
			flag_ex = 1;

			break;
		}
	}
		return flag_ex;
}
int ClassSystem::readData_input()
{
	cout << "请输入课程名称："; cin >> Course.coursename;
	cout << "请输入课程编号："; cin >> Course.coursenum;
	cout << "请输入开课单位："; cin >> Course.department;
	cout << "请输入授课教师："; cin >> Course.teacher;
	cout << "请输入选课人数:"; cin >> Course.numstudent;
	string temp;
	StudentInFor stu;
	int i = 0;
	for (; i < Course.numstudent; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的学号:";
		cin >> stu.student_number;
		cout << "请输入第" << i + 1 << "个学生的姓名:";
		cin >> stu.name;
		cout << "请输入第" << i + 1 << "个学生的性别:";
		cin >> stu.sex;
		cout << "请输入第" << i + 1 << "个学生的班级名称:";
		cin >> stu.class_number;
		cout << "请输入第" << i + 1 << "个学生的平时成绩（作业）:";
		cin >> stu.homework_score;
		cout << "请输入第" << i + 1 << "个学生的平时成绩（实验）:";
		cin >> stu.experiment_score;
		cout << "请输入第" << i + 1 << "个学生的平时成绩（报告）:";
		cin >> stu.report_score;
		cout << "请输入第" << i + 1 << "个学生的考试成绩:";
		cin >> stu.exam_score;
	}
	while (i = Course.numstudent)
	{
		cout << "是否终止输入（是/否）：" << endl;
		cin >> temp;
		if (temp == "是")break;
	}

	cout << "共读入：" << Course.numstudent << "个人成绩" << endl;
	system("pause");
	return 1;




}
int ClassSystem::displayData()
{
		if ((!flag_data) || (!num_person))

		{
			cout << "没有读入数据，请先读入数据！" << endl;
			system("pause");
			return 0;
		}
		cout << "课程名称：" << Course.coursename << endl;
		cout << "课程编号：" << Course.coursenum << endl;
		cout << "开课单位：" << Course.department << endl;
		cout << "授课教师：" << Course.teacher << endl;
		cout << "选课人数：" << Course.numstudent << endl;
		cout << endl;
		cout<<setfill('*')<< resetiosflags(ios::left) << setiosflags(ios::right);
		cout << setw(89) << "成绩列表" << setw(89) << '*' << endl;
		cout << setfill(' ') << resetiosflags(ios::right) << setiosflags(ios::left);
		cout << setiosflags(ios::left);
		cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "性别" << setw(20) << " 班级名称 " << setw(20) << "平时成绩（作业)" << setw(20) << "平时成绩（实验）" << setw(20) << "平时成绩（报告）" << setw(20) << "考试成绩" << setw(20) << "最终成绩" << endl;
		for (int i = 0; i < num_person; i++)
		{
			cout << setw(20) << conper[i].student_number;
			cout << setw(20) << conper[i].name;
			cout << setw(20) << conper[i].sex;
			cout << setw(20) << conper[i].class_number;
			cout << setw(20) << conper[i].homework_score;
			cout << setw(20) << conper[i].experiment_score;
			cout << setw(20) << conper[i].report_score;
			cout << setw(20) << conper[i].exam_score;
			conper[i].final_score = 0.2 * conper[i].homework_score + 0.15 * conper[i].experiment_score + 0.05 * conper[i].report_score + 0.6 * conper[i].exam_score;
			cout << setw(20) << conper[i].final_score;
			cout << endl;
		}
		system("pause");
		return 1;
}
int ClassSystem::searchData()
{
	int choice;
	cout << "请选择您需要的查询依据：" << endl;
	cout << "***************" << endl;;
	cout << "*1、按学号查询*" << endl;
	cout << "*2、按姓名查询*" << endl;
	cout << "*3、按性别查询*" << endl;
	cout << "*4、按班级查询*" << endl;
	cout << "***************" << endl;
	cout << "请输入您所需查询依据前的序号：";
	cin >> choice;
	switch (choice)
	{
	case 1:searchNumber(); break;
	case 2:searchName(); break;
	case 3:searchSex(); break;
	case 4:searchClass(); break;
	default:cout << "查无此项" << endl; break;
	}
	system("pause");
	return 1;

}
void ClassSystem::searchNumber()
{
	string search_number;
	cout << "请输入您想要查询的学号" << endl;
	cin >> search_number;
	bool flag_search = false;
	for (int i = 0; i < num_person; i++)
		if (conper[i].student_number == search_number)
		{   
			cout << setiosflags(ios::left);

			cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "性别" << setw(20) << " 班级名称 " << setw(20) << "平时成绩（作业)" << setw(20) << "平时成绩（实验）" << setw(20) << "平时成绩（报告）" << setw(20) << "考试成绩" << setw(20) << "最终成绩" << endl;
            cout << setw(20) << conper[i].student_number;
			cout << setw(20) << conper[i].name;
			cout << setw(20) << conper[i].sex;
			cout << setw(20) << conper[i].class_number;
			cout << setw(20) << conper[i].homework_score;
			cout << setw(20) << conper[i].experiment_score;
			cout << setw(20) << conper[i].report_score;
			cout << setw(20) << conper[i].exam_score;
			cout << setw(20) << conper[i].final_score;
			flag_search = true;
			break;
	    } 
	if (flag_search == false)
		cout << "找不到该学生信息" << endl;
	

}
void ClassSystem::searchName()
{
	string search_name;
	cout << "请输入您想要查询的姓名"<< endl;
	cin >> search_name;
	bool flag_search = false;
	for (int i = 0; i < num_person; i++)
		if (conper[i].name== search_name)
		{
			cout << setiosflags(ios::left);
			cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "性别" << setw(20) << " 班级名称 " << setw(20) << "平时成绩（作业)" << setw(20) << "平时成绩（实验）" << setw(20) << "平时成绩（报告）" << setw(20) << "考试成绩" << setw(20) << "最终成绩" << endl;
			cout << setw(20) << conper[i].student_number;
			cout << setw(20) << conper[i].name;
			cout << setw(20) << conper[i].sex;
			cout << setw(20) << conper[i].class_number;
			cout << setw(20) << conper[i].homework_score;
			cout << setw(20) << conper[i].experiment_score;
			cout << setw(20) << conper[i].report_score;
			cout << setw(20) << conper[i].exam_score;
			cout << setw(20) << conper[i].final_score;
			flag_search = true;
			break;
		}
	if (flag_search == false)
		cout << "找不到该学生信息" << endl;
}
void ClassSystem::searchSex()
{
	string search_sex;
	cout << "请输入您想要查询的性别"<< endl;
	cin >> search_sex;
	bool flag_search = false;
	cout << setiosflags(ios::left);
	cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "性别" << setw(20) << " 班级名称 " << setw(20) << "平时成绩（作业)" << setw(20) << "平时成绩（实验）" << setw(20) << "平时成绩（报告）" << setw(20) << "考试成绩" << setw(20) << "最终成绩" << endl;
	for (int i = 0; i < num_person; i++)
		if (conper[i].sex == search_sex)
		{
			cout << setiosflags(ios::left);			
			cout << setw(20) << conper[i].student_number;
			cout << setw(20) << conper[i].name;
			cout << setw(20) << conper[i].sex;
			cout << setw(20) << conper[i].class_number;
			cout << setw(20) << conper[i].homework_score;
			cout << setw(20) << conper[i].experiment_score;
			cout << setw(20) << conper[i].report_score;
			cout << setw(20) << conper[i].exam_score;
			cout << setw(20) << conper[i].final_score;
			flag_search = true;
			cout << endl;
		}
	if (flag_search == false)
		cout << "找不到该学生信息" << endl;
}
void ClassSystem::searchClass()
{
	string search_class_number;
	cout << "请输入您想要查询的班级名称" << endl;
	cin >> search_class_number;
	bool flag_search = false;
	cout << setiosflags(ios::left);
	cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "性别" << setw(20) << " 班级名称 " << setw(20) << "平时成绩（作业)" << setw(20) << "平时成绩（实验）" << setw(20) << "平时成绩（报告）" << setw(20) << "考试成绩" << setw(20) << "最终成绩" << endl;
	for (int i = 0; i < num_person; i++)
		if (conper[i].class_number == search_class_number)
		{
			cout << setiosflags(ios::left);		
			cout << setw(20) << conper[i].student_number;
			cout << setw(20) << conper[i].name;
			cout << setw(20) << conper[i].sex;
			cout << setw(20) << conper[i].class_number;
			cout << setw(20) << conper[i].homework_score;
			cout << setw(20) << conper[i].experiment_score;
			cout << setw(20) << conper[i].report_score;
			cout << setw(20) << conper[i].exam_score;
			cout << setw(20) << conper[i].final_score;
			flag_search = true;
			cout << endl;
		}
	if (flag_search == false)
		cout << "找不到该学生信息" << endl;
}
int ClassSystem::changeData()
{
	string change_num;
	cout << "请输入需要修改成绩的学生的学号：" << endl;
	cin >> change_num;
	bool flag_search = false;
	for (int i = 0; i < num_person; i++)
	{if (conper[i].student_number == change_num)
		{
			cout << setiosflags(ios::left);
			cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "性别" << setw(20) << " 班级名称 " << setw(20) << "平时成绩（作业)" << setw(20) << "平时成绩（实验）" << setw(20) << "平时成绩（报告）" << setw(20) << "考试成绩" << setw(20) << "最终成绩" << endl;
			cout << setw(20) << conper[i].student_number;
			cout << setw(20) << conper[i].name;
			cout << setw(20) << conper[i].sex;
			cout << setw(20) << conper[i].class_number;
			cout << setw(20) << conper[i].homework_score;
			cout << setw(20) << conper[i].experiment_score;
			cout << setw(20) << conper[i].report_score;
			cout << setw(20) << conper[i].exam_score;
			cout << setw(20) << conper[i].final_score;
			cout << endl;
			flag_search = true;
			int choice;
			cout << "*********请选择您想要修改的内容**********" << endl;
			cout << "*****************************************" << endl;
			cout << "*             1.学号                    *" << endl;
			cout << "*             2.姓名                    *" << endl;
			cout << "*             3.性别                    *" << endl;
			cout << "*             4.班级名称                *" << endl;
			cout << "*             5.平时成绩（作业）        *" << endl;
			cout << "*             6.平时成绩（实验）        *" << endl;
			cout << "*             7.平时成绩（报告）        *" << endl;
			cout << "*             8.考试成绩                *" << endl;
			cout << "*****************************************" << endl;
			cout << endl;
			cout << "请输入您要修改的内容编号" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{string changednum;
			cout << "请输入修改后的学号:";
			cin >> changednum;
			conper[i].student_number = changednum;
			}
			break;
			case 2:
			{	string changedname;
			cout << "请输入修改后的姓名:";
			cin >> changedname;
			conper[i].name = changedname;
			}
			break;
			case 3:
			{	string changedsex;
			cout << "请输入修改后的性别:";
			cin >> changedsex;
			conper[i].sex = changedsex;
			}
			break;
			case 4:
			{	string changedclassname;
			cout << "请输入修改后的班级";
			cin >> changedclassname;
			conper[i].class_number = changedclassname;
			}
			break;
			case 5:
			{	float changedhomework_score;
			cout << "请输入修改后的平时成绩（作业）:";
			cin >> changedhomework_score;
			conper[i].homework_score = changedhomework_score;
			}
			break;
			case 6:
			{	float changedexperiment_score;
			cout << "请输入修改后的平时成绩（实验）:";
			cin >> changedexperiment_score;
			conper[i].experiment_score = changedexperiment_score;
			}
			break;
			case 7:
			{	float changedreport_score;
			cout << "请输入修改后的平时成绩（报告）:";
			cin >> changedreport_score;
			conper[i].report_score = changedreport_score;
			}
			break;
			case 8:
			{	float changedexam_score;
			cout << "请输入修改后的考试成绩:";
			cin >> changedexam_score;
			conper[i].exam_score = changedexam_score;
			}
			break;
			default:cout << "请重新输入！";
				break;
			}
	}
			break;
		}
	if (flag_search == false)

		cout << "找不到该学生信息" << endl;
	
	system("pause");
	return 1;
}
int ClassSystem::addData()
{
	if ((!flag_data) || (!num_person))

	{
		cout << "没有读入数据，请先读入数据！" << endl;
		system("pause");
		return 0;
	}
	if (num_person == MAXPERSON)
	{
		cout << "已超出最大人数，无法补录！" << endl;
		system("pause");
		return 0;
	}
	StudentInFor temp;
	cout << "请输入补录学生的学号" << endl;
	cin >> temp.student_number;
	for (int i = 0; i < num_person; i++)
	{
		if (temp.student_number == conper[i].student_number)
		{
			cout << "已存在该同学，不能补录！" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "姓名:";cin >> temp.name;
	cout << "性别:";cin >> temp.sex;
	cout << "班级名称:"; cin >> temp.class_number;
	cout << "平时成绩（作业）："; cin >> temp.homework_score;
	cout << "平时成绩（实验）："; cin >> temp.experiment_score;
	cout << "平时成绩（报告）："; cin >> temp.report_score;
	cout << "考试成绩："; cin >> temp.exam_score;
	temp.final_score = temp.homework_score * 0.2 + temp.experiment_score * 0.15 + temp.report_score * 0.05 + temp.exam_score * 0.6;
	cout << "最终成绩：" << temp.final_score;
	conper[num_person]=temp;
	num_person = num_person + 1;
	system("pause");
	return 1;
}
int ClassSystem::deleteData()
{
	cout << "**************************" << endl;
	cout << "*      1.根据学号删除    *" << endl;
	cout << "*      2.根据姓名删除    *" << endl;
	cout << "*      3.根据性别删除    *" << endl;
	cout << "*      4.根据班级删除    *" << endl;
	cout << "**************************" << endl;
	cout << "请输入您要删除的内容编号: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: deleteNumber();
		break;
	case 2: deleteName();
		break;
	case 3: deleteSex();
		break;
	case 4: deleteClass();
		break;
	default:cout << "没有该选项，请重新输入！" << endl;
		break;
	}
	return 1;
}
void ClassSystem::deleteNumber()
{
	string delete_number;
	cout << "请输入您想删除的学生成绩的学生学号" << endl;
	cin >> delete_number;
	bool flag_delete = false;
	cout << setiosflags(ios::left);
	for (int j = 0; j < num_person; j++)
	{
		if (delete_number == conper[j].student_number)
		{
			for (int i = j; i < num_person; i++)
			{
				conper[i].student_number = conper[i + 1].student_number;
				conper[i].name = conper[i + 1].name;
				conper[i].sex = conper[i + 1].sex;
				conper[i].class_number = conper[i + 1].class_number;
				conper[i].homework_score = conper[i + 1].homework_score;
				conper[i].experiment_score = conper[i + 1].experiment_score;
				conper[i].report_score = conper[i + 1].report_score;
				conper[i].exam_score = conper[i + 1].exam_score;
				conper[i].final_score = conper[i + 1].final_score;
			}
			num_person--;
			flag_delete = true;
			cout << "删除成功!" << endl;
			break;
		}

		if (flag_delete = false)

			cout << "找不到该学生信息" << endl;
	}
	system("pause");
	
}
void ClassSystem::deleteName()
{
	string delete_name;
	cout << "请输入您想删除的学生成绩的学生姓名" << endl;
	cin >> delete_name;
	bool flag_delete = false;
	cout << setiosflags(ios::left);
	for (int j = 0; j < num_person; j++)
	{
		if (delete_name == conper[j].name)
		{
			for (int i = j; i < num_person; i++)
			{
				conper[i].student_number = conper[i + 1].student_number;
				conper[i].name = conper[i + 1].name;
				conper[i].sex = conper[i + 1].sex;
				conper[i].class_number = conper[i + 1].class_number;
				conper[i].homework_score = conper[i + 1].homework_score;
				conper[i].experiment_score = conper[i + 1].experiment_score;
				conper[i].report_score = conper[i + 1].report_score;
				conper[i].exam_score = conper[i + 1].exam_score;
				conper[i].final_score = conper[i + 1].final_score;
			}
			num_person--;
			flag_delete = true;
			cout << "删除成功!" << endl;
		    break;
		}

		if (flag_delete = false)

			cout << "找不到该学生信息" << endl;
	}
	system("pause");

}
void ClassSystem::deleteSex()
{
	string delete_sex;
	cout << "请输入您想删除的学生成绩的学生性别" << endl;
	cin >> delete_sex;
	cout << setiosflags(ios::left);
	bool flag_delete = false;
	for (int j = 0; j < num_person; j++)
	{
		bool f = false;
		if (delete_sex == conper[j].sex)
		{
			for (int i = j; i < num_person; i++)
			{
				conper[i] = conper[i + 1];
			}
			num_person--;
			flag_delete = true;
			f = true;
			cout << "删除成功!" << endl;

		}
		if (f)
			j--;
	}
		if (flag_delete = false)
			cout << "找不到该学生信息" << endl;
	
	system("pause");
}
void ClassSystem::deleteClass()
{
	string delete_class_num;
	cout << "请输入您想删除的学生成绩的学生班级名称" << endl;
	cin >> delete_class_num;
	cout << setiosflags(ios::left);
	bool flag_delete = false;
	for (int j = 0; j < num_person; j++)
	{
		bool f = false;
		if (delete_class_num == conper[j].class_number)
		{
			for (int i = j; i < num_person; i++)
			{
				conper[i] = conper[i + 1];
			}
			num_person--;
			flag_delete = true;
			f = true;
			cout << "删除成功!" << endl;

		}
		if (f)
			j--;
	}
	if (flag_delete = false)
		cout << "找不到该学生信息" << endl;

	system("pause");
}
int ClassSystem::storeData()
{
	ofstream outfile("StudentScore.dat",ios::out);
	if (!outfile)
	{
		cerr << "当前工程目录下不存在StudentScore.dat文件，保存失败！！！" << endl;
		outfile.close();
		system("pause");
		return 0;
	}

	outfile << "课程名称：     " << Course.coursename<< endl;
	outfile << "课程编号：     " << Course.coursenum << endl;
	outfile << "开课单位：     " << Course.department << endl;
	outfile << "授课教师：     " << Course.teacher << endl;
	outfile << "选课人数：     " << Course.numstudent << endl;
	outfile << "**********************************************************************成绩列表************************************************************************" << endl;
	outfile << setiosflags(ios::left);
	outfile << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "性别" << setw(20) << " 班级名称 " << setw(20) << "平时成绩（作业）" << setw(20) << "平时成绩（实验）" << setw(20) << "平时成绩（报告）" << setw(20) << "考试成绩" << endl;
	for (int i = 0; i < num_person; i++)
	{
		outfile << setw(20) << conper[i].student_number;
		outfile << setw(20) << conper[i].name;
		outfile << setw(20) << conper[i].sex;
		outfile << setw(20) << conper[i].class_number;
		outfile << setw(20) << conper[i].homework_score;
		outfile << setw(20) << conper[i].experiment_score;
		outfile << setw(20) << conper[i].report_score;
		outfile << setw(20) << conper[i].exam_score;
		outfile << endl;
	}

	cout << "共输出" << num_person << "条数据" << endl;
	outfile.close();
	system("pause");
	return 1;
}
int ClassSystem::countData()
{
	int choice;
	cout << "请选择您想要统计的成绩：" << endl;
	cout << "*************************" << endl;;
	cout << "*1、统计全体同学成绩    *" << endl;
	cout << "*2、统计遥感1701班的成绩*" << endl;
	cout << "*3、统计测绘1701班的成绩*" << endl;
	cout << "*4、统计地信1701班的成绩*" << endl;
	cout << "*5、统计全体男生的成绩  *" << endl;
	cout << "*6、统计全体女生的成绩  *" << endl;
	cout << "*7、对成绩进行排序      *" << endl;
	cout << "*************************" << endl;
	cout << "请输入您所需查询依据前的序号：";
	cin >> choice;
	switch (choice)
	{
	case 1:storeAllstudent(); break;
	case 2:storeClassYaoGan(); break;
	case 3:storeClassCeHui(); break;
	case 4:storeClassDiXin(); break;
	case 5:storeMan(); break;
	case 6:storeWoman(); break;
	case 7:sortScore(); break;
	default:cout << "查无此项" << endl; break;
	}
	
	system("pause");
	return 1;
	
}
void ClassSystem::storeAllstudent()
{
	cout << "统计全体同学成绩：" << endl;
	for (int i = 0; i < Course.numstudent; i++)
	{
		conper[i].final_score = 0.2 * conper[i].homework_score + 0.15 * conper[i].experiment_score + 0.05 * conper[i].report_score + 0.6 * conper[i].exam_score;

	}
	float highest_score = 0;//最高得分
	float lowest_score = conper[0].final_score;//最低得分
	float average_score;//平均得分
	float total_score = 0;//总分，用来求平均分
	float good_rate;//优良率
	float pass_rate;//及格率
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highest_score)
		{
			highest_score = conper[i].final_score;
		}
	}
	for (int i = 0; i <Course.numstudent; i++)
	{
		if (conper[i].final_score < lowest_score)
		{
			lowest_score = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		total_score = total_score + conper[i].final_score;
	}
	average_score = total_score / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80)
		{
			j++;
		}
	}
	good_rate = j / Course.numstudent;
	float k= 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60)
		{
			k++;
		}
	}
	pass_rate = k / Course.numstudent;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9)
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19)
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29)
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39)
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49)
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59)
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69)
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79)
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89)
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100)
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "全校最高得分：" << highest_score << endl;
	cout << "全校最低得分：" << lowest_score << endl;
	cout << "全校平均得分：" << average_score << endl;
	cout << "全校优良率：" << good_rate << endl;
	cout << "全校及格率：" << pass_rate << endl;
	cout << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	cout << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "占比：" << num1 / Course.numstudent << setw(8) << num2 / Course.numstudent << setw(8) << num3 / Course.numstudent << setw(8) << num4 / Course.numstudent << setw(8) << num5 / Course.numstudent << setw(8) << num6 / Course.numstudent << setw(8) << num7 / Course.numstudent << setw(8) << num8 / Course.numstudent << setw(8) << num9 / Course.numstudent << setw(8) << num10 / Course.numstudent << endl;
	system("pause");
}
void ClassSystem::storeClassYaoGan()
{
	cout << "统计遥感1701班的成绩：" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number=="遥感1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "遥感1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "遥感1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "遥感1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "遥感1701")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "遥感1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "遥感1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "遥感1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "遥感1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "遥感1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "遥感1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "遥感1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "遥感1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "遥感1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "遥感1701")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "遥感1701最高得分：" << highestscore << endl;
	cout << "遥感1701最低得分：" << lowestscore << endl;
	cout << "遥感1701平均得分：" << averagescore << endl;
	cout << "遥感1701优良率：" << goodrate << endl;
	cout << "遥感1701及格率：" << passrate << endl;
	cout << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	cout << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeClassCeHui()
{
	cout << "统计测绘1701班的成绩：" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number == "测绘1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "测绘1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "测绘1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "测绘1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "测绘1701")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "测绘1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "测绘1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "测绘1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "测绘1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "测绘1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "测绘1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "测绘1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "测绘1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "测绘1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "测绘1701")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "测绘1701最高得分：" << highestscore << endl;
	cout << "测绘1701最低得分：" << lowestscore << endl;
	cout << "测绘1701平均得分：" << averagescore << endl;
	cout << "测绘1701优良率：" << goodrate << endl;
	cout << "测绘1701及格率：" << passrate << endl;
	cout << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	cout << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeClassDiXin()
{

	cout << "统计地信1701班的成绩：" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number == "地信1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "地信1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "地信1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "地信1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "地信1701")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "地信1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "地信1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "地信1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "地信1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "地信1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "地信1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "地信1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "地信1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "地信1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "地信1701")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "地信1701最高得分：" << highestscore << endl;
	cout << "地信1701最低得分：" << lowestscore << endl;
	cout << "地信1701平均得分：" << averagescore << endl;
	cout << "地信1701优良率：" << goodrate << endl;
	cout << "地信1701及格率：" << passrate << endl;
	cout << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	cout << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeMan()
{
	cout << "统计全体男生的成绩：" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].sex == "男")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "男")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "男")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "男")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "男")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "男")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "男")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "男")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "男")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "男")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "男")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "男")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "男")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "男")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "男")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "男生中的最高得分：" << highestscore << endl;
	cout << "男生中的最低得分：" << lowestscore << endl;
	cout << "男生的平均得分：" << averagescore << endl;
	cout << "男生的优良率：" << goodrate << endl;
	cout << "男生的及格率：" << passrate << endl;
	cout << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	cout << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeWoman()
{
	cout << "统计全体女生的成绩：" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].sex == "女")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "女")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "女")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "女")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "女")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "女")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "女")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "女")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "女")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "女")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "女")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "女")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "女")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "女")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "女")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "女生中的最高得分：" << highestscore << endl;
	cout << "女生中的最低得分：" << lowestscore << endl;
	cout << "女生的平均得分：" << averagescore << endl;
	cout << "女生的优良率：" << goodrate << endl;
	cout << "女生的及格率：" << passrate << endl;
	cout << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	cout << "人数：" <<num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::sortScore()
{
	StudentInFor temp;
	for (int i = 0; i < Course.numstudent; i++)
	{
		conper[i].final_score = 0.2 * conper[i].homework_score + 0.15 * conper[i].experiment_score + 0.05 * conper[i].report_score + 0.6 * conper[i].exam_score;
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		for (int a = 0; a < Course.numstudent - i; a++)
		{
			if (conper[a].final_score < conper[a + 1].final_score)
			{
				temp = conper[a];
				conper[a] = conper[a + 1];
				conper[a + 1] = temp;
			}
		}
	}
	//对全部学生按成绩由高到低进行排序
	cout << "对全部学生按成绩由高到低进行排序：" << endl;
	cout << "*********************************************************成绩列表************************************************************************"
		<< endl;
	cout << "学号                 姓名              性别                班级名称           平时成绩（作业）    平时成绩（实验）       平时成绩（报告）    考试成绩         最终成绩"
		<< endl;
	for (int i = 0; i <Course.numstudent; i++)
	{
		cout << setw(20) << setiosflags(ios::left) << conper[i].student_number;
		cout << setw(20) << setiosflags(ios::left) << conper[i].name;
		cout << setw(20) << setiosflags(ios::left) << conper[i].sex;
		cout << setw(20) << setiosflags(ios::left) << conper[i].class_number;
        cout << setw(20) << setiosflags(ios::left) << conper[i].homework_score;
		cout << setw(20) << setiosflags(ios::left) << conper[i].experiment_score;
		cout << setw(20) << setiosflags(ios::left) << conper[i].report_score;
		cout << setw(20) << setiosflags(ios::left) << conper[i].exam_score;
		cout << setw(20) << setiosflags(ios::left) << conper[i].final_score;
		cout << endl;
	}
	system("pause");

}
int ClassSystem::saveScore()
{
	ofstream outfile("saveStudentScore.dat", ios::out);
	if (!outfile)
 	{
		cout << "打开文件失败，请重试!" << endl;
		return 0;
	}
	saveAll();
	outfile << endl;
	saveclassYaoGan();
	outfile << endl;
	saveclassCeHui();
	outfile << endl;
	saveclassDiXin();
	outfile << endl;
	saveMan();
	outfile << endl;
	saveWoman();
	outfile << endl;
	saveSortScore();
	cout << "保存成绩成功！";
	system("pause");
	
	return 1;
}
void ClassSystem::saveAll()
{
	ofstream outfile("saveStudentScore.dat", ios::out|ios::app);
	for (int i = 0; i < Course.numstudent; i++)
	{
		conper[i].final_score = 0.2 * conper[i].homework_score + 0.15 * conper[i].experiment_score + 0.05 * conper[i].report_score + 0.6 * conper[i].exam_score;

	}
	float highest_score = 0;//最高得分
	float lowest_score = conper[0].final_score;//最低得分
	float average_score;//平均得分
	float total_score = 0;//总分，用来求平均分
	float good_rate;//优良率
	float pass_rate;//及格率
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highest_score)
		{
			highest_score = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowest_score)
		{
			lowest_score = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		total_score = total_score + conper[i].final_score;
	}
	average_score = total_score / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80)
		{
			j++;
		}
	}
	good_rate = j / Course.numstudent;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60)
		{
			k++;
		}
	}
	pass_rate = k / Course.numstudent;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9)
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19)
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29)
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39)
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49)
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59)
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69)
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79)
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89)
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100)
		{
			num10++;
		}
	}
	outfile << setiosflags(ios::fixed) << setprecision(1);
	outfile << "全校最高得分：" << highest_score << endl;
	outfile << "全校最低得分：" << lowest_score << endl;
	outfile << "全校平均得分：" << average_score << endl;
	outfile << "全校优良率：" << good_rate << endl;
	outfile << "全校及格率：" << pass_rate << endl;
	outfile << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	outfile << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "占比：" << num1 / Course.numstudent << setw(8) << num2 / Course.numstudent << setw(8) << num3 / Course.numstudent << setw(8) << num4 / Course.numstudent << setw(8) << num5 / Course.numstudent << setw(8) << num6 / Course.numstudent << setw(8) << num7 / Course.numstudent << setw(8) << num8 / Course.numstudent << setw(8) << num9 / Course.numstudent << setw(8) << num10 / Course.numstudent << endl;
	system("pause");

}
void ClassSystem::saveclassYaoGan()
{
	ofstream outfile("saveStudentScore.dat", ios::out | ios::app);
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number == "遥感1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "遥感1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "遥感1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "遥感1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "遥感1701")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "遥感1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "遥感1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "遥感1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "遥感1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "遥感1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "遥感1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "遥感1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "遥感1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "遥感1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "遥感1701")
		{
			num10++;
		}
	}
	outfile << setiosflags(ios::fixed) << setprecision(1);
	outfile << "遥感1701最高得分：" << highestscore << endl;
	outfile << "遥感1701最低得分：" << lowestscore << endl;
	outfile << "遥感1701平均得分：" << averagescore << endl;
	outfile << "遥感1701优良率：" << goodrate << endl;
	outfile << "遥感1701及格率：" << passrate << endl;
	outfile << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	outfile << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");

}
void ClassSystem::saveclassCeHui()
{
	ofstream outfile("saveStudentScore.dat", ios::out | ios::app);
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number == "测绘1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "测绘1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "测绘1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "测绘1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "测绘1701")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "测绘1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "测绘1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "测绘1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "测绘1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "测绘1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "测绘1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "测绘1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "测绘1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "测绘1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "测绘1701")
		{
			num10++;
		}
	}
	outfile << setiosflags(ios::fixed) << setprecision(1);
	outfile << "测绘1701最高得分：" << highestscore << endl;
	outfile << "测绘1701最低得分：" << lowestscore << endl;
	outfile << "测绘1701平均得分：" << averagescore << endl;
	outfile << "测绘1701优良率：" << goodrate << endl;
	outfile << "测绘1701及格率：" << passrate << endl;
	outfile << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	outfile << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::saveclassDiXin()
{
	ofstream outfile("saveStudentScore.dat", ios::out | ios::app);
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number == "地信1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "地信1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "地信1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "地信1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "地信1701")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "地信1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "地信1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "地信1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "地信1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "地信1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "地信1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "地信1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "地信1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "地信1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "地信1701")
		{
			num10++;
		}
	}
	outfile << setiosflags(ios::fixed) << setprecision(1);
	outfile << "地信1701最高得分：" << highestscore << endl;
	outfile << "地信1701最低得分：" << lowestscore << endl;
	outfile << "地信1701平均得分：" << averagescore << endl;
	outfile << "地信1701优良率：" << goodrate << endl;
	outfile << "地信1701及格率：" << passrate << endl;
	outfile << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	outfile << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::saveMan()
{
	ofstream outfile("saveStudentScore.dat", ios::out | ios::app);
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].sex == "男")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "男")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "男")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "男")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "男")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "男")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "男")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "男")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "男")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "男")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "男")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "男")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "男")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "男")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "男")
		{
			num10++;
		}
	}
	outfile<< setiosflags(ios::fixed) << setprecision(1);
	outfile << "男生中的最高得分：" << highestscore << endl;
	outfile << "男生中的最低得分：" << lowestscore << endl;
	outfile << "男生的平均得分：" << averagescore << endl;
	outfile << "男生的优良率：" << goodrate << endl;
	outfile << "男生的及格率：" << passrate << endl;
	outfile << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	outfile << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::saveWoman()
{
	ofstream outfile("saveStudentScore.dat", ios::out | ios::app);
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].sex == "女")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "女")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "女")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "女")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "女")
		{
			j++;
		}
	}
	passrate = j / students;

	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
	float num7 = 0;
	float num8 = 0;
	float num9 = 0;
	float num10 = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "女")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "女")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "女")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "女")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "女")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "女")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "女")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "女")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "女")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "女")
		{
			num10++;
		}
	}
	outfile<< setiosflags(ios::fixed) << setprecision(1);
	outfile << "女生中的最高得分：" << highestscore << endl;
	outfile << "女生中的最低得分：" << lowestscore << endl;
	outfile << "女生的平均得分：" << averagescore << endl;
	outfile << "女生的优良率：" << goodrate << endl;
	outfile << "女生的及格率：" << passrate << endl;
	outfile << setw(10) << "0-9分" << setw(8) << "10-19分" << setw(8) << "20-29分" << setw(8) << "30-39分" << setw(8) << "40-49分" << setw(8) << "50-59分" << setw(8) << "60-69分" << setw(8) << "70-79分" << setw(8) << "80-89分" << setw(8) << "90-100分" << endl;
	outfile << "人数：" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "占比：" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::saveSortScore()
{
	ofstream outfile("saveStudentScore.dat", ios::out | ios::app);
	StudentInFor temp;
	for (int i = 0; i < Course.numstudent; i++)
	{
		conper[i].final_score = 0.2 * conper[i].homework_score + 0.15 * conper[i].experiment_score + 0.05 * conper[i].report_score + 0.6 * conper[i].exam_score;
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		for (int a = 0; a < Course.numstudent - i; a++)
		{
			if (conper[a].final_score < conper[a + 1].final_score)
			{
				temp = conper[a];
				conper[a] = conper[a + 1];
				conper[a + 1] = temp;
			}
		}
	}
	//对全部学生按成绩由高到低进行排序
	outfile << "对全部学生按成绩由高到低进行排序：" << endl;
	outfile << "*********************************************************成绩列表************************************************************************"
		<< endl;
	outfile << "学号                 姓名              性别                班级名称           平时成绩（作业）    平时成绩（实验）       平时成绩（报告）    考试成绩         最终成绩"
		<< endl;
	for (int i = 0; i <Course.numstudent; i++)
	{
		outfile << setw(20) << setiosflags(ios::left) << conper[i].student_number;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].name;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].sex;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].class_number;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].homework_score;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].experiment_score;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].report_score;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].exam_score;
		outfile << setw(20) << setiosflags(ios::left) << conper[i].final_score;
		outfile << endl;
	}
	system("pause");
}
