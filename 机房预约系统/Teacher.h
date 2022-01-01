#pragma once
#include"iostream"
using namespace std;
#include"Identity.h"
#include<string>
#include<vector>
#include"ComputerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
#include<iomanip>

class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造 (职工号、姓名、密码)
	Teacher(int empID, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	int m_EmpID; //教师编号
};