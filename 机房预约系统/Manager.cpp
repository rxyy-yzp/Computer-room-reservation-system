#include"Manager.h"

//默认构造
Manager::Manager()
{

}

//有参构造  管理员姓名、密码
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器，获取到文件中所有老师、学生信息
	this->initVector();

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

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员:" << this->m_Name << "登陆!" << endl;
	cout << endl;
	cout << "\t\t┌─────────────────────────────┐\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        1.添 加 账 号        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        2.查 看 账 号        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        3.查看机房信息       │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        4.清 空 预 约        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t│        0.注 销 登 陆        │\n";
	cout << "\t\t│                             │\n";
	cout << "\t\t└─────────────────────────────┘\n";
	cout << "输入您的选择: ";
}

//添加账号  
void Manager::addPerson()
{
	cout << "请输入添加账号的类型:" << endl;
	cout << "1.添加学生账号" << endl;
	cout << "2.添加教师账号" << endl;

	string fileName;//操作文件名
	string tip;//提示ID
	string errorTip;

	ofstream ofs;//文件操作对象

	int select = 0;
	while (1)
	{
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
		{
			cout << "非法输入!" << endl;
			cout << "请再次输入:";
		}
	}
	if (select == 1)//添加学生
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号:";
		errorTip = "学号重复，请重新输入!";
	}
	else if (select == 2)//添加老师
	{
		fileName = TEACHER_FILE;
		tip = "请输入教工号:";
		errorTip = "教工号重复，请重新输入!";
	}

	//利用追加方式写文件
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
	
	cout << "请设置用户名:";
	cin >> name;
	cout << "请设置密码:";
	cin >> pwd;

	//向文件添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功!" << endl;
	system("pause");
	system("cls");
	ofs.close();
	
	this->initVector();//立即更新容器
}

void printStudent(Student& s)
{
	cout << "学号: " << s.m_ID << "  姓名: " << s.m_Name << "  密码: " << s.m_Pwd << endl;
}

void printTeacher(Teacher& s)
{
	cout << "教工号: " << s.m_EmpID << "  姓名: " << s.m_Name << "  密码: " << s.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容:" << endl;
	cout << "1.查看所有学生账号信息" << endl;
	cout << "2.查看所有教师账号信息" << endl;

	int select = 0;
	while (1)
	{
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
		{
			cout << "非法输入!" << endl;
			cout << "请再次输入:";
		}
	}
	if (select == 1)//查看学生
	{
		cout << "所有学生账号信息如下:" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2)//查看老师
	{
		cout << "所有教师账号信息如下:" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
	{
		cout << "机房编号: " << it->m_ComID << "  机房最大容量: " << it->m_Max_Num << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//读取信息  学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
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
		cout << "文件读取失败" << endl;
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
		//检测学生
		for (vector<Student>::iterator it = vStu.begin();it != vStu.end();it++)
		{
			if (id == it->m_ID)
				return true;
		}
	}
	else if (type == 2)
	{
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++)
		{
			if (id == it->m_EmpID)
				return true;
		}
	}
	return false;
}