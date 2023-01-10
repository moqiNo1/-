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

struct StudentInFor//�ṹ�����ͣ�����ѧ��
{
	string student_number;//ѧ��
	string name;//����
	string sex;//�Ա�
	string class_number;//�༶����
	float homework_score;//ƽʱ�ɼ�����ҵ��
	float experiment_score;//ƽʱ�ɼ���ʵ�飩
	float report_score;//ƽʱ�ɼ������棩
	float exam_score;//���Գɼ�
	float final_score;//���ճɼ�
};
struct course
{
	string coursename; //�γ�����
	string coursenum;  //�γ̱��
	string department; //���ε�λ
	string teacher;     //�ڿν�ʦ
	int numstudent;     //ѡ������
};
class ClassSystem
{
public:
	void operation();

private:
	int readData();//�ɼ����뺯��
	int readData_file();//�ɼ��ļ����뺯��
	int readData_input();//�ɼ�����̨���뺯��
	int displayData();//�ɼ�չʾ����
	int searchData();//�ɼ���ѯ����
	int changeData();//�ɼ��޸ĺ���
	int addData();//�ɼ���¼����
	int deleteData();//�ɼ�ɾ������
	int storeData();//�ɼ����溯��
	int countData();//�ɼ�ͳ�ƺ���
	void searchNumber();//��ѧ�Ų�ѯ�ĺ���
	void searchName();//��������ѯ�ĺ���
	void searchSex();//���Ա��ѯ�ĺ���
	void searchClass();//���༶��ѯ�ĺ���
	void deleteNumber();//��ѧ��ɾ���ĺ���
	void deleteName();//������ɾ���ĺ���
	void deleteSex();//���Ա�ɾ���ĺ���
	void deleteClass();//���༶ɾ���ĺ���
	void storeAllstudent();//ͳ��ȫ��ͬѧ�ɼ��ĺ���
	void storeClassYaoGan();//ͳ��ң��1701��ĳɼ��ĺ���
	void storeClassCeHui();//ͳ�Ʋ��1701��ĳɼ��ĺ���
	void storeClassDiXin();//ͳ�Ƶ���1701��ĳɼ��ĺ���
	void storeMan();//ͳ��ȫ�������ĳɼ��ĺ���
	void storeWoman();//ͳ��ȫ��Ů���ĳɼ��ĺ���
	void sortScore();//�Գɼ�����ĺ���
	int saveScore();//���溯��
	void saveAll();//������ͳ�Ƶ�ȫ��ѧ���ɼ��ĺ���
	void saveclassYaoGan();//������ͳ�Ƶ�ң��1701��ѧ���ɼ��ĺ���
	void saveclassCeHui();//������ͳ�ƵĲ��1701��ѧ���ɼ��ĺ���
	void saveclassDiXin();//������ͳ�Ƶĵ���1701��ѧ���ɼ��ĺ���
	void saveMan();//���������ĳɼ��ĺ���
	void saveWoman();//����Ů���ĳɼ��ĺ���
	void saveSortScore();//����ɼ�����ĺ���
	bool flag_data = false;
	StudentInFor conper[MAXPERSON];
	int num_person = 0;
	int beExisting(string pno);
	course Course;
};
#endif
