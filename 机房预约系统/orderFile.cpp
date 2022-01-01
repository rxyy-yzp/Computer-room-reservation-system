#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;//����
	string interval;//ʱ���
	string stuID;//ѧ�����
	string stuName;//ѧ������
	string roomID;//�������
	string status;//ԤԼ״̬

	this->m_Size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuID && 
		ifs >> stuName&& ifs >> roomID && ifs >> status)
	{
		string key;
		string value;
		map<string, string>m;
		int pos = date.find(":");
		key = date.substr(0, pos);
		value = date.substr(pos + 1, date.size() - pos - 1);
		m.insert(make_pair(key, value));

		pos = interval.find(":");
		key = interval.substr(0, pos);
		value = interval.substr(pos + 1, interval.size() - pos - 1);
		m.insert(make_pair(key, value));

		pos = stuID.find(":");
		key = stuID.substr(0, pos);
		value = stuID.substr(pos + 1, stuID.size() - pos - 1);
		m.insert(make_pair(key, value));

		pos = stuName.find(":");
		key = stuName.substr(0, pos);
		value = stuName.substr(pos + 1, stuName.size() - pos - 1);
		m.insert(make_pair(key, value));

		pos = roomID.find(":");
		key = roomID.substr(0, pos);
		value = roomID.substr(pos + 1, roomID.size() - pos - 1);
		m.insert(make_pair(key, value));

		pos = status.find(":");
		key = status.substr(0, pos);
		value = status.substr(pos + 1, status.size() - pos - 1);
		m.insert(make_pair(key, value));

		//��Сmap���������map����
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
}

//����ԤԼ��¼
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;//ԤԼ��¼0
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0;i < this->m_Size;i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuID:" << this->m_orderData[i]["stuID"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomID:" << this->m_orderData[i]["roomID"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
}