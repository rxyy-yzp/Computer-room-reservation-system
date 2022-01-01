#include"Teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι��� (ְ���š�����������)
Teacher::Teacher(int empID, string name, string pwd)
{
	this->m_EmpID = empID;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ:" << this->m_Name << "��½!" << endl;
	cout << endl;
	cout << "\t\t��������������������������������������������������������������\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        1.�鿴����ԤԼ       ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        2.�� �� Ԥ Լ        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        0.ע �� �� ½        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��������������������������������������������������������������\n";
	cout << "��������ѡ��: ";
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_Size;i++)
	{
		cout << i + 1 << ".";
		cout << "ѧ��: " << of.m_orderData[i]["stuID"];
		cout << "  ����: " << setw(8) << std::left << of.m_orderData[i]["stuName"];
		string tempday;
		if (of.m_orderData[i]["date"] == "1")
		{
			tempday = "һ";
		}
		else if (of.m_orderData[i]["date"] == "2")
		{
			tempday = "��";
		}
		else if (of.m_orderData[i]["date"] == "3")
		{
			tempday = "��";
		}
		else if (of.m_orderData[i]["date"] == "4")
		{
			tempday = "��";
		}
		else if (of.m_orderData[i]["date"] == "5")
		{
			tempday = "��";
		}
		cout << "ԤԼ����: ��" << tempday;
		cout << "  ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");

		string temproom;
		if (of.m_orderData[i]["roomID"] == "1")
		{
			temproom = "�ۺϽ�ѧ1��¥404";
		}
		else if (of.m_orderData[i]["roomID"] == "2")
		{
			temproom = "�ۺϽ�ѧ1��¥406";
		}
		else if (of.m_orderData[i]["roomID"] == "3")
		{
			temproom = "�ۺϽ�ѧ1��¥411";
		}
		else if (of.m_orderData[i]["roomID"] == "4")
		{
			temproom = "�ۺϽ�ѧ2��¥B601";
		}
		else if (of.m_orderData[i]["roomID"] == "5")
		{
			temproom = "�ۺϽ�ѧ2��¥B603";
		}
		else if (of.m_orderData[i]["roomID"] == "6")
		{
			temproom = "�ۺϽ�ѧ2��¥B606";
		}
		cout << "  ������: " << setw(18) << std::left << temproom;
		string status = "  ״̬: ";
		//1.�����  2.��ԤԼ  3.ԤԼʧ��  0.ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "3")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "����˵�ԤԼ��¼����:" << endl;
	for (int i = 0;i < of.m_Size;i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ".";
			cout << "ѧ��: " << of.m_orderData[i]["stuID"];
			cout << "  ����: " << setw(8) << std::left << of.m_orderData[i]["stuName"];
			string tempday;
			if (of.m_orderData[i]["date"] == "1")
			{
				tempday = "һ";
			}
			else if (of.m_orderData[i]["date"] == "2")
			{
				tempday = "��";
			}
			else if (of.m_orderData[i]["date"] == "3")
			{
				tempday = "��";
			}
			else if (of.m_orderData[i]["date"] == "4")
			{
				tempday = "��";
			}
			else if (of.m_orderData[i]["date"] == "5")
			{
				tempday = "��";
			}
			cout << "ԤԼ����: ��" << tempday;
			cout << "  ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");

			string temproom;
			if (of.m_orderData[i]["roomID"] == "1")
			{
				temproom = "�ۺϽ�ѧ1��¥404";
			}
			else if (of.m_orderData[i]["roomID"] == "2")
			{
				temproom = "�ۺϽ�ѧ1��¥406";
			}
			else if (of.m_orderData[i]["roomID"] == "3")
			{
				temproom = "�ۺϽ�ѧ1��¥411";
			}
			else if (of.m_orderData[i]["roomID"] == "4")
			{
				temproom = "�ۺϽ�ѧ2��¥B601";
			}
			else if (of.m_orderData[i]["roomID"] == "5")
			{
				temproom = "�ۺϽ�ѧ2��¥B603";
			}
			else if (of.m_orderData[i]["roomID"] == "6")
			{
				temproom = "�ۺϽ�ѧ2��¥B606";
			}
			cout << "  ������: " << setw(18) << std::left << temproom;
			string status = "  ״̬: ";
			//1.�����  2.��ԤԼ  3.ԤԼʧ��  0.ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "3")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;

		}
	}
	cout << "����������˵ļ�¼������0����" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��:" << endl;
				cout << "1.ͨ��  2.����" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "3";
				}
				of.updateOrder();
				cout << "������!" << endl;
				break;
			}
		}
		cout << "�Ƿ�����!" << endl;
		cout << "���ٴ�����:";
	}
	system("pause");
	system("cls");
}