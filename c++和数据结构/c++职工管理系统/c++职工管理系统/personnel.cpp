#include"personnel.h"
//Ա��
Employee::Employee(int id,string name,string sex,int did)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = did;
	m_Sex = sex;
}

string Employee::getDeptName()//��ȡ��λ����
{
	return string("Ա��");
}

//����
Manager::Manager(int id, string name, string sex, int did)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = did;
	m_Sex = sex;
}

string Manager::getDeptName()//��λ����
{
	return string("����");
}

//�ܲ�
Boss::Boss(int id, string name, string sex, int did)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = did;
	m_Sex = sex;
}

string Boss::getDeptName()//��λ����
{
	return string("�ܲ�");
}