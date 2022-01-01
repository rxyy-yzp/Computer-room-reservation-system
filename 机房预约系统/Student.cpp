#include"Student.h"

//默认构造
Student::Student()
{

}

//有参构造 参数：学号、姓名、密码
Student::Student(int id, string name, string pwd)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComID && ifs >> com.m_Max_Num)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生:" << this->m_Name << "登陆!" << endl;
	cout << endl;
	cout << "\t\t┌─────────────────────────────┐\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        1.申 请 预 约        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        2.查看自身预约       │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        3.查看所有预约       │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        4.取 消 预 约        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        0.注 销 登 陆        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t└─────────────────────────────┘\n";
	cout << "输入您的选择: ";
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五" << endl;
	cout << "请输入申请预约的时间:" << endl;
	cout << "1.周一  2.周二  3.周三  4.周四  5.周五" << endl;
	int date = 0;//日期
	int interval = 0;//时间段
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
			cout << "非法输入!" << endl;
			cout << "请再次输入:";
		}
	}
	cout << endl << "请输入申请预约的时间段:";
	cout << "1.上午  2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "非法输入!" << endl;
			cout << "请再次输入:";
		}
	}
	cout << endl << "请选择机房:" << endl;;
	for (int i = 0;i < vCom.size();i++)
	{
		cout << i + 1 << "." << vCom[i].m_ComID << "  机房容量为: " << vCom[i].m_Max_Num << endl;
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
			cout << "非法输入!" << endl;
			cout << "请再次输入:";
		}
	}
	cout << "预约信息已发送! 请等待审核!" << endl;

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

//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_Size;i++)
	{
		if (this->m_ID == atoi(of.m_orderData[i]["stuID"].c_str()))//找到自身预约
		{
			string tempday;
			if (of.m_orderData[i]["date"] == "1")
			{
				tempday = "一";
			}
			else if (of.m_orderData[i]["date"] == "2")
			{
				tempday = "二";
			}
			else if (of.m_orderData[i]["date"] == "3")
			{
				tempday = "三";
			}
			else if (of.m_orderData[i]["date"] == "4")
			{
				tempday = "四";
			}
			else if (of.m_orderData[i]["date"] == "5")
			{
				tempday = "五";
			}
			cout << "预约日期: 周" << tempday;
			cout << "  时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");

			string temproom;
			if (of.m_orderData[i]["roomID"] == "1")
			{
				temproom = "综合教学1号楼404";
			}
			else if (of.m_orderData[i]["roomID"] == "2")
			{
				temproom = "综合教学1号楼406";
			}
			else if (of.m_orderData[i]["roomID"] == "3")
			{
				temproom = "综合教学1号楼411";
			}
			else if (of.m_orderData[i]["roomID"] == "4")
			{
				temproom = "综合教学2号楼B601";
			}
			else if (of.m_orderData[i]["roomID"] == "5")
			{
				temproom = "综合教学2号楼B603";
			}
			else if (of.m_orderData[i]["roomID"] == "6")
			{
				temproom = "综合教学2号楼B606";
			}
			cout << "  机房号: " << setw(18) << std::left << temproom;
			string status = "  状态: ";
			//1.审核中  2.已预约  3.预约失败  0.取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if(of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if(of.m_orderData[i]["status"] == "3")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_Size;i++)
	{
		cout << i + 1 << ".";
		cout << "学号: " << of.m_orderData[i]["stuID"];
		cout << "  姓名: " << setw(8) << std::left << of.m_orderData[i]["stuName"];
		string tempday;
		if (of.m_orderData[i]["date"] == "1")
		{
			tempday = "一";
		}
		else if (of.m_orderData[i]["date"] == "2")
		{
			tempday = "二";
		}
		else if (of.m_orderData[i]["date"] == "3")
		{
			tempday = "三";
		}
		else if (of.m_orderData[i]["date"] == "4")
		{
			tempday = "四";
		}
		else if (of.m_orderData[i]["date"] == "5")
		{
			tempday = "五";
		}
		cout << "预约日期: 周" << tempday;
		cout << "  时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");

		string temproom;
		if (of.m_orderData[i]["roomID"] == "1")
		{
			temproom = "综合教学1号楼404";
		}
		else if (of.m_orderData[i]["roomID"] == "2")
		{
			temproom = "综合教学1号楼406";
		}
		else if (of.m_orderData[i]["roomID"] == "3")
		{
			temproom = "综合教学1号楼411";
		}
		else if (of.m_orderData[i]["roomID"] == "4")
		{
			temproom = "综合教学2号楼B601";
		}
		else if (of.m_orderData[i]["roomID"] == "5")
		{
			temproom = "综合教学2号楼B603";
		}
		else if (of.m_orderData[i]["roomID"] == "6")
		{
			temproom = "综合教学2号楼B606";
		}
		cout << "  机房号: " << setw(18) << std::left << temproom;
		string status = "  状态: ";
		//1.审核中  2.已预约  3.预约失败  0.取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "3")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入需要取消的记录" << endl;
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
					tempday = "一";
				}
				else if (of.m_orderData[i]["date"] == "2")
				{
					tempday = "二";
				}
				else if (of.m_orderData[i]["date"] == "3")
				{
					tempday = "三";
				}
				else if (of.m_orderData[i]["date"] == "4")
				{
					tempday = "四";
				}
				else if (of.m_orderData[i]["date"] == "5")
				{
					tempday = "五";
				}
				cout << "预约日期: 周" << tempday;
				cout << "  时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");

				string temproom;
				if (of.m_orderData[i]["roomID"] == "1")
				{
					temproom = "综合教学1号楼404";
				}
				else if (of.m_orderData[i]["roomID"] == "2")
				{
					temproom = "综合教学1号楼406";
				}
				else if (of.m_orderData[i]["roomID"] == "3")
				{
					temproom = "综合教学1号楼411";
				}
				else if (of.m_orderData[i]["roomID"] == "4")
				{
					temproom = "综合教学2号楼B601";
				}
				else if (of.m_orderData[i]["roomID"] == "5")
				{
					temproom = "综合教学2号楼B603";
				}
				else if (of.m_orderData[i]["roomID"] == "6")
				{
					temproom = "综合教学2号楼B606";
				}
				cout << "  机房号: " << setw(18) << std::left << temproom;
				string status = "  状态: ";
				//1.审核中  2.已预约  3.预约失败  0.取消预约
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				else if (of.m_orderData[i]["status"] == "3")
				{
					status += "预约失败，审核未通过";
				}
				else
				{
					status += "预约已取消";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入想取消的记录，输入0返回" << endl;
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
				cout << "预约已取消" << endl;
				break;
			}
		}
		cout << "非法输入!" << endl;
		cout << "请再次输入:";
	}
	system("pause");
	system("cls");
}