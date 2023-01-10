#include "ClassSystem.h"
void ClassSystem::operation()
{
	char choice;
	bool flag_oper = true;
	while (flag_oper)
	{
		system("cls");
		cout << "**************************************************************" << endl;
		cout << "*                   �γ̳ɼ����������ϵͳ                   *" << endl;
		cout << "**************************************************************" << endl;
		cout << "*                      1:����γ̳ɼ�                        *" << endl;
		cout << "*                      2:���ѧ���ɼ�                        *" << endl;
		cout << "*                      3:��ѯѧ���ɼ�                        *" << endl;
		cout << "*                      4:�޸�ѧ���ɼ�                        *" << endl;
		cout << "*                      5:��¼ѧ���ɼ�                        *" << endl;
		cout << "*                      6:ɾ��ѧ���ɼ�                        *" << endl;
		cout << "*                      7:�����޸ĳɼ�                        *" << endl;
		cout << "*                      8:ͳ�ƿγ̳ɼ�                        *" << endl;
		cout << "*                      9:����ͳ������                        *" << endl;
		cout << "*                      0:�˳�����ϵͳ                        *" << endl;
		cout << "**************************************************************" << endl;
		cout << "����������ѡ��";
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
		default:cout << "�޴�ѡ�����������" << endl; system("pause"); break;
		}

	}

}
int ClassSystem::readData()
{
	char choice;
	int flag_read;
	cout << "1.�ļ���ȡ" << endl << "2.����̨����" << endl;
	cout << "����������ѡ��1��2��:";
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
		cout << "�Ѿ��������ݣ������ظ�����" << endl;
		system("pause");
		return 0;
	}
	if (!infile)
	{
		cerr << "��ǰ����Ŀ¼�²�����StudentScore.dat�ļ�����ʧ�ܣ�����" << endl;
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
			cerr << "���������������ܳ���" << MAXPERSON << endl;
			break;
		}
	}
	flag_data = true;
	infile.close();
	cout << "������" << num_person << "������" << endl;
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
	cout << "������γ����ƣ�"; cin >> Course.coursename;
	cout << "������γ̱�ţ�"; cin >> Course.coursenum;
	cout << "�����뿪�ε�λ��"; cin >> Course.department;
	cout << "�������ڿν�ʦ��"; cin >> Course.teacher;
	cout << "������ѡ������:"; cin >> Course.numstudent;
	string temp;
	StudentInFor stu;
	int i = 0;
	for (; i < Course.numstudent; i++)
	{
		cout << "�������" << i + 1 << "��ѧ����ѧ��:";
		cin >> stu.student_number;
		cout << "�������" << i + 1 << "��ѧ��������:";
		cin >> stu.name;
		cout << "�������" << i + 1 << "��ѧ�����Ա�:";
		cin >> stu.sex;
		cout << "�������" << i + 1 << "��ѧ���İ༶����:";
		cin >> stu.class_number;
		cout << "�������" << i + 1 << "��ѧ����ƽʱ�ɼ�����ҵ��:";
		cin >> stu.homework_score;
		cout << "�������" << i + 1 << "��ѧ����ƽʱ�ɼ���ʵ�飩:";
		cin >> stu.experiment_score;
		cout << "�������" << i + 1 << "��ѧ����ƽʱ�ɼ������棩:";
		cin >> stu.report_score;
		cout << "�������" << i + 1 << "��ѧ���Ŀ��Գɼ�:";
		cin >> stu.exam_score;
	}
	while (i = Course.numstudent)
	{
		cout << "�Ƿ���ֹ���루��/�񣩣�" << endl;
		cin >> temp;
		if (temp == "��")break;
	}

	cout << "�����룺" << Course.numstudent << "���˳ɼ�" << endl;
	system("pause");
	return 1;




}
int ClassSystem::displayData()
{
		if ((!flag_data) || (!num_person))

		{
			cout << "û�ж������ݣ����ȶ������ݣ�" << endl;
			system("pause");
			return 0;
		}
		cout << "�γ����ƣ�" << Course.coursename << endl;
		cout << "�γ̱�ţ�" << Course.coursenum << endl;
		cout << "���ε�λ��" << Course.department << endl;
		cout << "�ڿν�ʦ��" << Course.teacher << endl;
		cout << "ѡ��������" << Course.numstudent << endl;
		cout << endl;
		cout<<setfill('*')<< resetiosflags(ios::left) << setiosflags(ios::right);
		cout << setw(89) << "�ɼ��б�" << setw(89) << '*' << endl;
		cout << setfill(' ') << resetiosflags(ios::right) << setiosflags(ios::left);
		cout << setiosflags(ios::left);
		cout << setw(20) << "ѧ��" << setw(20) << "����" << setw(20) << "�Ա�" << setw(20) << " �༶���� " << setw(20) << "ƽʱ�ɼ�����ҵ)" << setw(20) << "ƽʱ�ɼ���ʵ�飩" << setw(20) << "ƽʱ�ɼ������棩" << setw(20) << "���Գɼ�" << setw(20) << "���ճɼ�" << endl;
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
	cout << "��ѡ������Ҫ�Ĳ�ѯ���ݣ�" << endl;
	cout << "***************" << endl;;
	cout << "*1����ѧ�Ų�ѯ*" << endl;
	cout << "*2����������ѯ*" << endl;
	cout << "*3�����Ա��ѯ*" << endl;
	cout << "*4�����༶��ѯ*" << endl;
	cout << "***************" << endl;
	cout << "�������������ѯ����ǰ����ţ�";
	cin >> choice;
	switch (choice)
	{
	case 1:searchNumber(); break;
	case 2:searchName(); break;
	case 3:searchSex(); break;
	case 4:searchClass(); break;
	default:cout << "���޴���" << endl; break;
	}
	system("pause");
	return 1;

}
void ClassSystem::searchNumber()
{
	string search_number;
	cout << "����������Ҫ��ѯ��ѧ��" << endl;
	cin >> search_number;
	bool flag_search = false;
	for (int i = 0; i < num_person; i++)
		if (conper[i].student_number == search_number)
		{   
			cout << setiosflags(ios::left);

			cout << setw(20) << "ѧ��" << setw(20) << "����" << setw(20) << "�Ա�" << setw(20) << " �༶���� " << setw(20) << "ƽʱ�ɼ�����ҵ)" << setw(20) << "ƽʱ�ɼ���ʵ�飩" << setw(20) << "ƽʱ�ɼ������棩" << setw(20) << "���Գɼ�" << setw(20) << "���ճɼ�" << endl;
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
		cout << "�Ҳ�����ѧ����Ϣ" << endl;
	

}
void ClassSystem::searchName()
{
	string search_name;
	cout << "����������Ҫ��ѯ������"<< endl;
	cin >> search_name;
	bool flag_search = false;
	for (int i = 0; i < num_person; i++)
		if (conper[i].name== search_name)
		{
			cout << setiosflags(ios::left);
			cout << setw(20) << "ѧ��" << setw(20) << "����" << setw(20) << "�Ա�" << setw(20) << " �༶���� " << setw(20) << "ƽʱ�ɼ�����ҵ)" << setw(20) << "ƽʱ�ɼ���ʵ�飩" << setw(20) << "ƽʱ�ɼ������棩" << setw(20) << "���Գɼ�" << setw(20) << "���ճɼ�" << endl;
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
		cout << "�Ҳ�����ѧ����Ϣ" << endl;
}
void ClassSystem::searchSex()
{
	string search_sex;
	cout << "����������Ҫ��ѯ���Ա�"<< endl;
	cin >> search_sex;
	bool flag_search = false;
	cout << setiosflags(ios::left);
	cout << setw(20) << "ѧ��" << setw(20) << "����" << setw(20) << "�Ա�" << setw(20) << " �༶���� " << setw(20) << "ƽʱ�ɼ�����ҵ)" << setw(20) << "ƽʱ�ɼ���ʵ�飩" << setw(20) << "ƽʱ�ɼ������棩" << setw(20) << "���Գɼ�" << setw(20) << "���ճɼ�" << endl;
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
		cout << "�Ҳ�����ѧ����Ϣ" << endl;
}
void ClassSystem::searchClass()
{
	string search_class_number;
	cout << "����������Ҫ��ѯ�İ༶����" << endl;
	cin >> search_class_number;
	bool flag_search = false;
	cout << setiosflags(ios::left);
	cout << setw(20) << "ѧ��" << setw(20) << "����" << setw(20) << "�Ա�" << setw(20) << " �༶���� " << setw(20) << "ƽʱ�ɼ�����ҵ)" << setw(20) << "ƽʱ�ɼ���ʵ�飩" << setw(20) << "ƽʱ�ɼ������棩" << setw(20) << "���Գɼ�" << setw(20) << "���ճɼ�" << endl;
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
		cout << "�Ҳ�����ѧ����Ϣ" << endl;
}
int ClassSystem::changeData()
{
	string change_num;
	cout << "��������Ҫ�޸ĳɼ���ѧ����ѧ�ţ�" << endl;
	cin >> change_num;
	bool flag_search = false;
	for (int i = 0; i < num_person; i++)
	{if (conper[i].student_number == change_num)
		{
			cout << setiosflags(ios::left);
			cout << setw(20) << "ѧ��" << setw(20) << "����" << setw(20) << "�Ա�" << setw(20) << " �༶���� " << setw(20) << "ƽʱ�ɼ�����ҵ)" << setw(20) << "ƽʱ�ɼ���ʵ�飩" << setw(20) << "ƽʱ�ɼ������棩" << setw(20) << "���Գɼ�" << setw(20) << "���ճɼ�" << endl;
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
			cout << "*********��ѡ������Ҫ�޸ĵ�����**********" << endl;
			cout << "*****************************************" << endl;
			cout << "*             1.ѧ��                    *" << endl;
			cout << "*             2.����                    *" << endl;
			cout << "*             3.�Ա�                    *" << endl;
			cout << "*             4.�༶����                *" << endl;
			cout << "*             5.ƽʱ�ɼ�����ҵ��        *" << endl;
			cout << "*             6.ƽʱ�ɼ���ʵ�飩        *" << endl;
			cout << "*             7.ƽʱ�ɼ������棩        *" << endl;
			cout << "*             8.���Գɼ�                *" << endl;
			cout << "*****************************************" << endl;
			cout << endl;
			cout << "��������Ҫ�޸ĵ����ݱ��" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{string changednum;
			cout << "�������޸ĺ��ѧ��:";
			cin >> changednum;
			conper[i].student_number = changednum;
			}
			break;
			case 2:
			{	string changedname;
			cout << "�������޸ĺ������:";
			cin >> changedname;
			conper[i].name = changedname;
			}
			break;
			case 3:
			{	string changedsex;
			cout << "�������޸ĺ���Ա�:";
			cin >> changedsex;
			conper[i].sex = changedsex;
			}
			break;
			case 4:
			{	string changedclassname;
			cout << "�������޸ĺ�İ༶";
			cin >> changedclassname;
			conper[i].class_number = changedclassname;
			}
			break;
			case 5:
			{	float changedhomework_score;
			cout << "�������޸ĺ��ƽʱ�ɼ�����ҵ��:";
			cin >> changedhomework_score;
			conper[i].homework_score = changedhomework_score;
			}
			break;
			case 6:
			{	float changedexperiment_score;
			cout << "�������޸ĺ��ƽʱ�ɼ���ʵ�飩:";
			cin >> changedexperiment_score;
			conper[i].experiment_score = changedexperiment_score;
			}
			break;
			case 7:
			{	float changedreport_score;
			cout << "�������޸ĺ��ƽʱ�ɼ������棩:";
			cin >> changedreport_score;
			conper[i].report_score = changedreport_score;
			}
			break;
			case 8:
			{	float changedexam_score;
			cout << "�������޸ĺ�Ŀ��Գɼ�:";
			cin >> changedexam_score;
			conper[i].exam_score = changedexam_score;
			}
			break;
			default:cout << "���������룡";
				break;
			}
	}
			break;
		}
	if (flag_search == false)

		cout << "�Ҳ�����ѧ����Ϣ" << endl;
	
	system("pause");
	return 1;
}
int ClassSystem::addData()
{
	if ((!flag_data) || (!num_person))

	{
		cout << "û�ж������ݣ����ȶ������ݣ�" << endl;
		system("pause");
		return 0;
	}
	if (num_person == MAXPERSON)
	{
		cout << "�ѳ�������������޷���¼��" << endl;
		system("pause");
		return 0;
	}
	StudentInFor temp;
	cout << "�����벹¼ѧ����ѧ��" << endl;
	cin >> temp.student_number;
	for (int i = 0; i < num_person; i++)
	{
		if (temp.student_number == conper[i].student_number)
		{
			cout << "�Ѵ��ڸ�ͬѧ�����ܲ�¼��" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "����:";cin >> temp.name;
	cout << "�Ա�:";cin >> temp.sex;
	cout << "�༶����:"; cin >> temp.class_number;
	cout << "ƽʱ�ɼ�����ҵ����"; cin >> temp.homework_score;
	cout << "ƽʱ�ɼ���ʵ�飩��"; cin >> temp.experiment_score;
	cout << "ƽʱ�ɼ������棩��"; cin >> temp.report_score;
	cout << "���Գɼ���"; cin >> temp.exam_score;
	temp.final_score = temp.homework_score * 0.2 + temp.experiment_score * 0.15 + temp.report_score * 0.05 + temp.exam_score * 0.6;
	cout << "���ճɼ���" << temp.final_score;
	conper[num_person]=temp;
	num_person = num_person + 1;
	system("pause");
	return 1;
}
int ClassSystem::deleteData()
{
	cout << "**************************" << endl;
	cout << "*      1.����ѧ��ɾ��    *" << endl;
	cout << "*      2.��������ɾ��    *" << endl;
	cout << "*      3.�����Ա�ɾ��    *" << endl;
	cout << "*      4.���ݰ༶ɾ��    *" << endl;
	cout << "**************************" << endl;
	cout << "��������Ҫɾ�������ݱ��: ";
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
	default:cout << "û�и�ѡ����������룡" << endl;
		break;
	}
	return 1;
}
void ClassSystem::deleteNumber()
{
	string delete_number;
	cout << "����������ɾ����ѧ���ɼ���ѧ��ѧ��" << endl;
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
			cout << "ɾ���ɹ�!" << endl;
			break;
		}

		if (flag_delete = false)

			cout << "�Ҳ�����ѧ����Ϣ" << endl;
	}
	system("pause");
	
}
void ClassSystem::deleteName()
{
	string delete_name;
	cout << "����������ɾ����ѧ���ɼ���ѧ������" << endl;
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
			cout << "ɾ���ɹ�!" << endl;
		    break;
		}

		if (flag_delete = false)

			cout << "�Ҳ�����ѧ����Ϣ" << endl;
	}
	system("pause");

}
void ClassSystem::deleteSex()
{
	string delete_sex;
	cout << "����������ɾ����ѧ���ɼ���ѧ���Ա�" << endl;
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
			cout << "ɾ���ɹ�!" << endl;

		}
		if (f)
			j--;
	}
		if (flag_delete = false)
			cout << "�Ҳ�����ѧ����Ϣ" << endl;
	
	system("pause");
}
void ClassSystem::deleteClass()
{
	string delete_class_num;
	cout << "����������ɾ����ѧ���ɼ���ѧ���༶����" << endl;
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
			cout << "ɾ���ɹ�!" << endl;

		}
		if (f)
			j--;
	}
	if (flag_delete = false)
		cout << "�Ҳ�����ѧ����Ϣ" << endl;

	system("pause");
}
int ClassSystem::storeData()
{
	ofstream outfile("StudentScore.dat",ios::out);
	if (!outfile)
	{
		cerr << "��ǰ����Ŀ¼�²�����StudentScore.dat�ļ�������ʧ�ܣ�����" << endl;
		outfile.close();
		system("pause");
		return 0;
	}

	outfile << "�γ����ƣ�     " << Course.coursename<< endl;
	outfile << "�γ̱�ţ�     " << Course.coursenum << endl;
	outfile << "���ε�λ��     " << Course.department << endl;
	outfile << "�ڿν�ʦ��     " << Course.teacher << endl;
	outfile << "ѡ��������     " << Course.numstudent << endl;
	outfile << "**********************************************************************�ɼ��б�************************************************************************" << endl;
	outfile << setiosflags(ios::left);
	outfile << setw(20) << "ѧ��" << setw(20) << "����" << setw(20) << "�Ա�" << setw(20) << " �༶���� " << setw(20) << "ƽʱ�ɼ�����ҵ��" << setw(20) << "ƽʱ�ɼ���ʵ�飩" << setw(20) << "ƽʱ�ɼ������棩" << setw(20) << "���Գɼ�" << endl;
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

	cout << "�����" << num_person << "������" << endl;
	outfile.close();
	system("pause");
	return 1;
}
int ClassSystem::countData()
{
	int choice;
	cout << "��ѡ������Ҫͳ�Ƶĳɼ���" << endl;
	cout << "*************************" << endl;;
	cout << "*1��ͳ��ȫ��ͬѧ�ɼ�    *" << endl;
	cout << "*2��ͳ��ң��1701��ĳɼ�*" << endl;
	cout << "*3��ͳ�Ʋ��1701��ĳɼ�*" << endl;
	cout << "*4��ͳ�Ƶ���1701��ĳɼ�*" << endl;
	cout << "*5��ͳ��ȫ�������ĳɼ�  *" << endl;
	cout << "*6��ͳ��ȫ��Ů���ĳɼ�  *" << endl;
	cout << "*7���Գɼ���������      *" << endl;
	cout << "*************************" << endl;
	cout << "�������������ѯ����ǰ����ţ�";
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
	default:cout << "���޴���" << endl; break;
	}
	
	system("pause");
	return 1;
	
}
void ClassSystem::storeAllstudent()
{
	cout << "ͳ��ȫ��ͬѧ�ɼ���" << endl;
	for (int i = 0; i < Course.numstudent; i++)
	{
		conper[i].final_score = 0.2 * conper[i].homework_score + 0.15 * conper[i].experiment_score + 0.05 * conper[i].report_score + 0.6 * conper[i].exam_score;

	}
	float highest_score = 0;//��ߵ÷�
	float lowest_score = conper[0].final_score;//��͵÷�
	float average_score;//ƽ���÷�
	float total_score = 0;//�ܷ֣�������ƽ����
	float good_rate;//������
	float pass_rate;//������
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
	cout << "ȫУ��ߵ÷֣�" << highest_score << endl;
	cout << "ȫУ��͵÷֣�" << lowest_score << endl;
	cout << "ȫУƽ���÷֣�" << average_score << endl;
	cout << "ȫУ�����ʣ�" << good_rate << endl;
	cout << "ȫУ�����ʣ�" << pass_rate << endl;
	cout << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	cout << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "ռ�ȣ�" << num1 / Course.numstudent << setw(8) << num2 / Course.numstudent << setw(8) << num3 / Course.numstudent << setw(8) << num4 / Course.numstudent << setw(8) << num5 / Course.numstudent << setw(8) << num6 / Course.numstudent << setw(8) << num7 / Course.numstudent << setw(8) << num8 / Course.numstudent << setw(8) << num9 / Course.numstudent << setw(8) << num10 / Course.numstudent << endl;
	system("pause");
}
void ClassSystem::storeClassYaoGan()
{
	cout << "ͳ��ң��1701��ĳɼ���" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number=="ң��1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "ң��1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "ң��1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "ң��1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "ң��1701")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "ң��1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "ң��1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "ң��1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "ң��1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "ң��1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "ң��1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "ң��1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "ң��1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "ң��1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "ң��1701")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "ң��1701��ߵ÷֣�" << highestscore << endl;
	cout << "ң��1701��͵÷֣�" << lowestscore << endl;
	cout << "ң��1701ƽ���÷֣�" << averagescore << endl;
	cout << "ң��1701�����ʣ�" << goodrate << endl;
	cout << "ң��1701�����ʣ�" << passrate << endl;
	cout << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	cout << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeClassCeHui()
{
	cout << "ͳ�Ʋ��1701��ĳɼ���" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number == "���1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "���1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "���1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "���1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "���1701")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "���1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "���1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "���1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "���1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "���1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "���1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "���1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "���1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "���1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "���1701")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "���1701��ߵ÷֣�" << highestscore << endl;
	cout << "���1701��͵÷֣�" << lowestscore << endl;
	cout << "���1701ƽ���÷֣�" << averagescore << endl;
	cout << "���1701�����ʣ�" << goodrate << endl;
	cout << "���1701�����ʣ�" << passrate << endl;
	cout << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	cout << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeClassDiXin()
{

	cout << "ͳ�Ƶ���1701��ĳɼ���" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].class_number == "����1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "����1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "����1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "����1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "����1701")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "����1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "����1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "����1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "����1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "����1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "����1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "����1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "����1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "����1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "����1701")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "����1701��ߵ÷֣�" << highestscore << endl;
	cout << "����1701��͵÷֣�" << lowestscore << endl;
	cout << "����1701ƽ���÷֣�" << averagescore << endl;
	cout << "����1701�����ʣ�" << goodrate << endl;
	cout << "����1701�����ʣ�" << passrate << endl;
	cout << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	cout << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeMan()
{
	cout << "ͳ��ȫ�������ĳɼ���" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].sex == "��")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "��")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "��")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "��")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "��")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "��")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "��")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "��")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "��")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "��")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "��")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "��")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "��")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "��")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "��")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "�����е���ߵ÷֣�" << highestscore << endl;
	cout << "�����е���͵÷֣�" << lowestscore << endl;
	cout << "������ƽ���÷֣�" << averagescore << endl;
	cout << "�����������ʣ�" << goodrate << endl;
	cout << "�����ļ����ʣ�" << passrate << endl;
	cout << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	cout << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
	system("pause");
}
void ClassSystem::storeWoman()
{
	cout << "ͳ��ȫ��Ů���ĳɼ���" << endl;;
	float highestscore = 0;
	float lowestscore = 100;
	float averagescore;
	float totalscore = 0;
	float goodrate;
	float passrate;
	float students = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > highestscore && conper[i].sex == "Ů")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "Ů")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "Ů")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "Ů")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "Ů")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "Ů")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "Ů")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "Ů")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "Ů")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "Ů")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "Ů")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "Ů")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "Ů")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "Ů")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "Ů")
		{
			num10++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << "Ů���е���ߵ÷֣�" << highestscore << endl;
	cout << "Ů���е���͵÷֣�" << lowestscore << endl;
	cout << "Ů����ƽ���÷֣�" << averagescore << endl;
	cout << "Ů���������ʣ�" << goodrate << endl;
	cout << "Ů���ļ����ʣ�" << passrate << endl;
	cout << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	cout << "������" <<num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	cout << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
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
	//��ȫ��ѧ�����ɼ��ɸߵ��ͽ�������
	cout << "��ȫ��ѧ�����ɼ��ɸߵ��ͽ�������" << endl;
	cout << "*********************************************************�ɼ��б�************************************************************************"
		<< endl;
	cout << "ѧ��                 ����              �Ա�                �༶����           ƽʱ�ɼ�����ҵ��    ƽʱ�ɼ���ʵ�飩       ƽʱ�ɼ������棩    ���Գɼ�         ���ճɼ�"
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
		cout << "���ļ�ʧ�ܣ�������!" << endl;
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
	cout << "����ɼ��ɹ���";
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
	float highest_score = 0;//��ߵ÷�
	float lowest_score = conper[0].final_score;//��͵÷�
	float average_score;//ƽ���÷�
	float total_score = 0;//�ܷ֣�������ƽ����
	float good_rate;//������
	float pass_rate;//������
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
	outfile << "ȫУ��ߵ÷֣�" << highest_score << endl;
	outfile << "ȫУ��͵÷֣�" << lowest_score << endl;
	outfile << "ȫУƽ���÷֣�" << average_score << endl;
	outfile << "ȫУ�����ʣ�" << good_rate << endl;
	outfile << "ȫУ�����ʣ�" << pass_rate << endl;
	outfile << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	outfile << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "ռ�ȣ�" << num1 / Course.numstudent << setw(8) << num2 / Course.numstudent << setw(8) << num3 / Course.numstudent << setw(8) << num4 / Course.numstudent << setw(8) << num5 / Course.numstudent << setw(8) << num6 / Course.numstudent << setw(8) << num7 / Course.numstudent << setw(8) << num8 / Course.numstudent << setw(8) << num9 / Course.numstudent << setw(8) << num10 / Course.numstudent << endl;
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
		if (conper[i].final_score > highestscore && conper[i].class_number == "ң��1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "ң��1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "ң��1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "ң��1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "ң��1701")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "ң��1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "ң��1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "ң��1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "ң��1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "ң��1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "ң��1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "ң��1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "ң��1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "ң��1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "ң��1701")
		{
			num10++;
		}
	}
	outfile << setiosflags(ios::fixed) << setprecision(1);
	outfile << "ң��1701��ߵ÷֣�" << highestscore << endl;
	outfile << "ң��1701��͵÷֣�" << lowestscore << endl;
	outfile << "ң��1701ƽ���÷֣�" << averagescore << endl;
	outfile << "ң��1701�����ʣ�" << goodrate << endl;
	outfile << "ң��1701�����ʣ�" << passrate << endl;
	outfile << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	outfile << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
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
		if (conper[i].final_score > highestscore && conper[i].class_number == "���1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "���1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "���1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "���1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "���1701")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "���1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "���1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "���1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "���1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "���1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "���1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "���1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "���1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "���1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "���1701")
		{
			num10++;
		}
	}
	outfile << setiosflags(ios::fixed) << setprecision(1);
	outfile << "���1701��ߵ÷֣�" << highestscore << endl;
	outfile << "���1701��͵÷֣�" << lowestscore << endl;
	outfile << "���1701ƽ���÷֣�" << averagescore << endl;
	outfile << "���1701�����ʣ�" << goodrate << endl;
	outfile << "���1701�����ʣ�" << passrate << endl;
	outfile << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	outfile << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
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
		if (conper[i].final_score > highestscore && conper[i].class_number == "����1701")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].class_number == "����1701")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].class_number == "����1701")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].class_number == "����1701")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].class_number == "����1701")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].class_number == "����1701")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].class_number == "����1701")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].class_number == "����1701")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].class_number == "����1701")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].class_number == "����1701")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].class_number == "����1701")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].class_number == "����1701")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].class_number == "����1701")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].class_number == "����1701")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].class_number == "����1701")
		{
			num10++;
		}
	}
	outfile << setiosflags(ios::fixed) << setprecision(1);
	outfile << "����1701��ߵ÷֣�" << highestscore << endl;
	outfile << "����1701��͵÷֣�" << lowestscore << endl;
	outfile << "����1701ƽ���÷֣�" << averagescore << endl;
	outfile << "����1701�����ʣ�" << goodrate << endl;
	outfile << "����1701�����ʣ�" << passrate << endl;
	outfile << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	outfile << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
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
		if (conper[i].final_score > highestscore && conper[i].sex == "��")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "��")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "��")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "��")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "��")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "��")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "��")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "��")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "��")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "��")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "��")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "��")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "��")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "��")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "��")
		{
			num10++;
		}
	}
	outfile<< setiosflags(ios::fixed) << setprecision(1);
	outfile << "�����е���ߵ÷֣�" << highestscore << endl;
	outfile << "�����е���͵÷֣�" << lowestscore << endl;
	outfile << "������ƽ���÷֣�" << averagescore << endl;
	outfile << "�����������ʣ�" << goodrate << endl;
	outfile << "�����ļ����ʣ�" << passrate << endl;
	outfile << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	outfile << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
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
		if (conper[i].final_score > highestscore && conper[i].sex == "Ů")
		{
			highestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score < lowestscore && conper[i].sex == "Ů")
		{
			lowestscore = conper[i].final_score;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].sex == "Ů")
		{
			totalscore = totalscore + conper[i].final_score;
			students++;
		}
	}
	averagescore = totalscore / students;;
	float k = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 80 && conper[i].sex == "Ů")
		{
			k++;
		}
	}
	goodrate = k / Course.numstudent;
	float j = 0;
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (conper[i].final_score > 60 && conper[i].sex == "Ů")
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
		if (0 <= conper[i].final_score && conper[i].final_score <= 9 && conper[i].sex == "Ů")
		{
			num1++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (9 < conper[i].final_score && conper[i].final_score <= 19 && conper[i].sex == "Ů")
		{
			num2++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (19 < conper[i].final_score && conper[i].final_score <= 29 && conper[i].sex == "Ů")
		{
			num3++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (29 < conper[i].final_score && conper[i].final_score <= 39 && conper[i].sex == "Ů")
		{
			num4++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (39 < conper[i].final_score && conper[i].final_score <= 49 && conper[i].sex == "Ů")
		{
			num5++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (49 < conper[i].final_score && conper[i].final_score <= 59 && conper[i].sex == "Ů")
		{
			num6++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (59 < conper[i].final_score && conper[i].final_score <= 69 && conper[i].sex == "Ů")
		{
			num7++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (69 < conper[i].final_score && conper[i].final_score <= 79 && conper[i].sex == "Ů")
		{
			num8++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (79 < conper[i].final_score && conper[i].final_score <= 89 && conper[i].sex == "Ů")
		{
			num9++;
		}
	}
	for (int i = 0; i < Course.numstudent; i++)
	{
		if (89 < conper[i].final_score && conper[i].final_score <= 100 && conper[i].sex == "Ů")
		{
			num10++;
		}
	}
	outfile<< setiosflags(ios::fixed) << setprecision(1);
	outfile << "Ů���е���ߵ÷֣�" << highestscore << endl;
	outfile << "Ů���е���͵÷֣�" << lowestscore << endl;
	outfile << "Ů����ƽ���÷֣�" << averagescore << endl;
	outfile << "Ů���������ʣ�" << goodrate << endl;
	outfile << "Ů���ļ����ʣ�" << passrate << endl;
	outfile << setw(10) << "0-9��" << setw(8) << "10-19��" << setw(8) << "20-29��" << setw(8) << "30-39��" << setw(8) << "40-49��" << setw(8) << "50-59��" << setw(8) << "60-69��" << setw(8) << "70-79��" << setw(8) << "80-89��" << setw(8) << "90-100��" << endl;
	outfile << "������" << num1 << setw(8) << num2 << setw(8) << num3 << setw(8) << num4 << setw(8) << num5 << setw(8) << num6 << setw(8) << num7 << setw(8) << num8 << setw(8) << num9 << setw(8) << num10 << endl;
	outfile << "ռ�ȣ�" << num1 / students << setw(8) << num2 / students << setw(8) << num3 / students << setw(8) << num4 / students << setw(8) << num5 / students << setw(8) << num6 / students << setw(8) << num7 / students << setw(8) << num8 / students << setw(8) << num9 / students << setw(8) << num10 / students << endl;
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
	//��ȫ��ѧ�����ɼ��ɸߵ��ͽ�������
	outfile << "��ȫ��ѧ�����ɼ��ɸߵ��ͽ�������" << endl;
	outfile << "*********************************************************�ɼ��б�************************************************************************"
		<< endl;
	outfile << "ѧ��                 ����              �Ա�                �༶����           ƽʱ�ɼ�����ҵ��    ƽʱ�ɼ���ʵ�飩       ƽʱ�ɼ������棩    ���Գɼ�         ���ճɼ�"
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
