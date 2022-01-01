#include"Teacher.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造 (职工号、姓名、密码)
Teacher::Teacher(int empID, string name, string pwd)
{
	this->m_EmpID = empID;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师:" << this->m_Name << "登陆!" << endl;
	cout << endl;
	cout << "\t\t┌─────────────────────────────┐\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        1.查看所有预约       │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        2.审 核 预 约        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        0.注 销 登 陆        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t└─────────────────────────────┘\n";
	cout << "输入您的选择: ";
}

//查看所有预约
void Teacher::showAllOrder()
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

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "待审核的预约记录如下:" << endl;
	for (int i = 0;i < of.m_Size;i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ".";
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
	}
	cout << "请输入想审核的记录，输入0返回" << endl;
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
				cout << "请输入审核结果:" << endl;
				cout << "1.通过  2.驳回" << endl;
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
				cout << "审核完毕!" << endl;
				break;
			}
		}
		cout << "非法输入!" << endl;
		cout << "请再次输入:";
	}
	system("pause");
	system("cls");
}