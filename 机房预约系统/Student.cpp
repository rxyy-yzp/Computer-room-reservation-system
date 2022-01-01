#include"Student.h"

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι��� ������ѧ�š�����������
Student::Student(int id, string name, string pwd)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

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

//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ��:" << this->m_Name << "��½!" << endl;
	cout << endl;
	cout << "\t\t��������������������������������������������������������������\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        1.�� �� Ԥ Լ        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        2.�鿴����ԤԼ       ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        3.�鿴����ԤԼ       ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        4.ȡ �� Ԥ Լ        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��        0.ע �� �� ½        ��\n";
	cout << "\t\t��                             ��\n";
	cout << "\t\t��������������������������������������������������������������\n";
	cout << "��������ѡ��: ";
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ��:" << endl;
	cout << "1.��һ  2.�ܶ�  3.����  4.����  5.����" << endl;
	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "�Ƿ�����!" << endl;
			cout << "���ٴ�����:";
		}
	}
	cout << endl << "����������ԤԼ��ʱ���:";
	cout << "1.����  2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "�Ƿ�����!" << endl;
			cout << "���ٴ�����:";
		}
	}
	cout << endl << "��ѡ�����:" << endl;;
	for (int i = 0;i < vCom.size();i++)
	{
		cout << i + 1 << "." << vCom[i].m_ComID << "  ��������Ϊ: " << vCom[i].m_Max_Num << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 6)
		{
			break;
		}
		else
		{
			cout << "�Ƿ�����!" << endl;
			cout << "���ٴ�����:";
		}
	}
	cout << "ԤԼ��Ϣ�ѷ���! ��ȴ����!" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuID:" << this->m_ID << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomID:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showMyOrder()
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
		if (this->m_ID == atoi(of.m_orderData[i]["stuID"].c_str()))//�ҵ�����ԤԼ
		{
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
			else if(of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if(of.m_orderData[i]["status"] == "3")
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
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
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

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ������������Ҫȡ���ļ�¼" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0;i < of.m_Size;i++)
	{
		if (this->m_ID == atoi(of.m_orderData[i]["stuID"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ".";
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
	}
	cout << "��������ȡ���ļ�¼������0����" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "ԤԼ��ȡ��" << endl;
				break;
			}
		}
		cout << "�Ƿ�����!" << endl;
		cout << "���ٴ�����:";
	}
	system("pause");
	system("cls");
}