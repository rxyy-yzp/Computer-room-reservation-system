#include"iostream"
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else//ע��
		{
			delete student;//���ٶ�������
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)//�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			tea->validOrder();
		}
		else//ע��
		{
			delete teacher;//���ٶ�������
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա���Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ��
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴������Ϣ
		{
			cout << "�鿴������Ϣ" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else//ע��
		{
			delete manager;//���ٶ�������
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//����ָ�룬ָ���������
	
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������!" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "������ѧ��:";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "������̹���:";
		cin >> id;
	}
	cout << "�������û���:";
	cin >> name;
	cout << "����������:";
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fID;//���ļ��л�ȡ��ID
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fID;//���ļ��л�ȡ��ID
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ����Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա����Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��½ʧ��!" << endl;
	system("pause");
	system("cls");
	return;
}

int main() 
{
	int select = 0;//���ڽ����û�ѡ��
	while (true)
	{
		cout << "==============  ��ӭ�������ʵ�����ػ���ԤԼϵͳ  ==============" << endl;
		cout << endl;
		cout << "\t\t��������������������������������������������������������������\n";
		cout << "\t\t��                             ��\n";
		cout << "\t\t��          1.ѧ    ��         ��\n";
		cout << "\t\t��                             ��\n";
		cout << "\t\t��          2.��    ʦ         ��\n";
		cout << "\t\t��                             ��\n";
		cout << "\t\t��          3.�� �� Ա         ��\n";
		cout << "\t\t��                             ��\n";
		cout << "\t\t��          0.��    ��         ��\n";
		cout << "\t\t��                             ��\n";
		cout << "\t\t��������������������������������������������������������������\n";
		cout << "��������ѡ��: ";
		cin >> select; //�û�����ѡ��
		
		switch (select)
		{
		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�ϵͳ
			cout << endl << "�ᵱ�پ�����һ����ɽС!" << endl;
			cout << endl << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}