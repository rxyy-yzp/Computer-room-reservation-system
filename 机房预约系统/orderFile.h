#pragma once
#include"iostream"
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"
#include<algorithm>
#include<map>

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������ key:��¼���� value:�����ֵ����Ϣ
	map<int, map<string, string>>m_orderData;
};

