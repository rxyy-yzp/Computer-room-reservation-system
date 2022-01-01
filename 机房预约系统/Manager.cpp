#include"Manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���  ����Ա����������
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ����������ȡ���ļ���������ʦ��ѧ����Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComID && ifs >> com.m_Max_Num)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա:" << this->m_Name << "��½!" << endl;
	cout << endl;
	cout << "\t\t��������������������������������������������������������������\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        1.�� �� �� ��        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        2.�� �� �� ��        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        3.�鿴������Ϣ       ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        4.�� �� Ԥ Լ        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        0.ע �� �� ½        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��������������������������������������������������������������\n";
	cout << "��������ѡ��: ";
}

//����˺�  
void Manager::addPerson()
{
	cout << "����������˺ŵ�����:" << endl;
	cout << "1.���ѧ���˺�" << endl;
	cout << "2.��ӽ�ʦ�˺�" << endl;

	string fileName;//�����ļ���
	string tip;//��ʾID
	string errorTip;

	ofstream ofs;//�ļ���������

	int select = 0;
	while (1)
	{
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
		{
			cout << "�Ƿ�����!" << endl;
			cout << "���ٴ�����:";
		}
	}
	if (select == 1)//���ѧ��
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�������������!";
	}
	else if (select == 2)//�����ʦ
	{
		fileName = TEACHER_FILE;
		tip = "������̹���:";
		errorTip = "�̹����ظ�������������!";
	}

	//����׷�ӷ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip;

	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
			cout << tip;
		}
		else
			break;
	}
	
	cout << "�������û���:";
	cin >> name;
	cout << "����������:";
	cin >> pwd;

	//���ļ��������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�!" << endl;
	system("pause");
	system("cls");
	ofs.close();
	
	this->initVector();//������������
}

void printStudent(Student& s)
{
	cout << "ѧ��: " << s.m_ID << "  ����: " << s.m_Name << "  ����: " << s.m_Pwd << endl;
}

void printTeacher(Teacher& s)
{
	cout << "�̹���: " << s.m_EmpID << "  ����: " << s.m_Name << "  ����: " << s.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����:" << endl;
	cout << "1.�鿴����ѧ���˺���Ϣ" << endl;
	cout << "2.�鿴���н�ʦ�˺���Ϣ" << endl;

	int select = 0;
	while (1)
	{
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
		{
			cout << "�Ƿ�����!" << endl;
			cout << "���ٴ�����:";
		}
	}
	if (select == 1)//�鿴ѧ��
	{
		cout << "����ѧ���˺���Ϣ����:" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2)//�鿴��ʦ
	{
		cout << "���н�ʦ�˺���Ϣ����:" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ����:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
	{
		cout << "�������: " << it->m_ComID << "  �����������: " << it->m_Max_Num << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ  ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_ID && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpID && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin();it != vStu.end();it++)
		{
			if (id == it->m_ID)
				return true;
		}
	}
	else if (type == 2)
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++)
		{
			if (id == it->m_EmpID)
				return true;
		}
	}
	return false;
}