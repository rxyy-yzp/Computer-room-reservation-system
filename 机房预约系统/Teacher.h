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
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� (ְ���š�����������)
	Teacher(int empID, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpID; //��ʦ���
};