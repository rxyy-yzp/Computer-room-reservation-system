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
	//Ĭ�Ϲ���
	Student();

	//�вι��� ������ѧ�š�����������
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_ID;

	//������Ϣ����
	vector<ComputerRoom>vCom;
};
