#ifndef CLASSSYSTEM_H
#define CLASSSYSTEM_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <strstream>
#include <stdlib.h>
#define MAXPERSON 100
using namespace std;

struct StudentInFor//结构体类型，描述学生
{
	string student_number;//学号
	string name;//姓名
	string sex;//性别
	string class_number;//班级名称
	float homework_score;//平时成绩（作业）
	float experiment_score;//平时成绩（实验）
	float report_score;//平时成绩（报告）
	float exam_score;//考试成绩
	float final_score;//最终成绩
};
struct course
{
	string coursename; //课程名称
	string coursenum;  //课程编号
	string department; //开课单位
	string teacher;     //授课教师
	int numstudent;     //选课人数
};
class ClassSystem
{
public:
	void operation();

private:
	int readData();//成绩读入函数
	int readData_file();//成绩文件读入函数
	int readData_input();//成绩控制台输入函数
	int displayData();//成绩展示函数
	int searchData();//成绩查询函数
	int changeData();//成绩修改函数
	int addData();//成绩补录函数
	int deleteData();//成绩删除函数
	int storeData();//成绩储存函数
	int countData();//成绩统计函数
	void searchNumber();//按学号查询的函数
	void searchName();//按姓名查询的函数
	void searchSex();//按性别查询的函数
	void searchClass();//按班级查询的函数
	void deleteNumber();//按学号删除的函数
	void deleteName();//按姓名删除的函数
	void deleteSex();//按性别删除的函数
	void deleteClass();//按班级删除的函数
	void storeAllstudent();//统计全体同学成绩的函数
	void storeClassYaoGan();//统计遥感1701班的成绩的函数
	void storeClassCeHui();//统计测绘1701班的成绩的函数
	void storeClassDiXin();//统计地信1701班的成绩的函数
	void storeMan();//统计全体男生的成绩的函数
	void storeWoman();//统计全体女生的成绩的函数
	void sortScore();//对成绩排序的函数
	int saveScore();//保存函数
	void saveAll();//保存所统计的全部学生成绩的函数
	void saveclassYaoGan();//保存所统计的遥感1701的学生成绩的函数
	void saveclassCeHui();//保存所统计的测绘1701的学生成绩的函数
	void saveclassDiXin();//保存所统计的地信1701的学生成绩的函数
	void saveMan();//保存男生的成绩的函数
	void saveWoman();//保存女生的成绩的函数
	void saveSortScore();//保存成绩排序的函数
	bool flag_data = false;
	StudentInFor conper[MAXPERSON];
	int num_person = 0;
	int beExisting(string pno);
	course Course;
};
#endif
