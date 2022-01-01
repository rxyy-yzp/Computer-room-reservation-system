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
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器 key:记录条数 value:具体键值对信息
	map<int, map<string, string>>m_orderData;
};

