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

class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造 参数：学号、姓名、密码
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_ID;

	//机房信息容器
	vector<ComputerRoom>vCom;
};
