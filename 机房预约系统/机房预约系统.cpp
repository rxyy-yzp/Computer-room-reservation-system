#include"iostream"
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)//申请预约
		{
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			cout << "查看自身预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else//注销
		{
			delete student;//销毁堆区对象
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)//查看所有预约
		{
			cout << "查看所有预约" << endl;
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			cout << "审核预约" << endl;
			tea->validOrder();
		}
		else//注销
		{
			delete teacher;//销毁堆区对象
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员的子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针转为子类指针
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房信息
		{
			cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else//注销
		{
			delete manager;//销毁堆区对象
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//父类指针，指向子类对象
	
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入学号:";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入教工号:";
		cin >> id;
	}
	cout << "请输入用户名:";
	cin >> name;
	cout << "请输入密码:";
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fID;//从文件中获取的ID
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fID;//从文件中获取的ID
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登陆失败!" << endl;
	system("pause");
	system("cls");
	return;
}

int main() 
{
	int select = 0;//用于接收用户选择
	while (true)
	{
		cout << "==============  欢迎进入寰宇实践基地机房预约系统  ==============" << endl;
		cout << endl;
		cout << "\t\t┌─────────────────────────────┐\n";
		cout << "\t\t│                             │\n";
		cout << "\t\t│          1.学    生         │\n";
		cout << "\t\t│                             │\n";
		cout << "\t\t│          2.教    师         │\n";
		cout << "\t\t│                             │\n";
		cout << "\t\t│          3.管 理 员         │\n";
		cout << "\t\t│                             │\n";
		cout << "\t\t│          0.退    出         │\n";
		cout << "\t\t│                             │\n";
		cout << "\t\t└─────────────────────────────┘\n";
		cout << "输入您的选择: ";
		cin >> select; //用户输入选择
		
		switch (select)
		{
		case 1:  //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //教师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			cout << endl << "会当临绝顶，一览众山小!" << endl;
			cout << endl << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}