#include"personnel.h"
//员工
Employee::Employee(int id,string name,string sex,int did)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = did;
	m_Sex = sex;
}

string Employee::getDeptName()//获取岗位名称
{
	return string("员工");
}

//经理
Manager::Manager(int id, string name, string sex, int did)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = did;
	m_Sex = sex;
}

string Manager::getDeptName()//岗位名称
{
	return string("经理");
}

//总裁
Boss::Boss(int id, string name, string sex, int did)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = did;
	m_Sex = sex;
}

string Boss::getDeptName()//岗位名称
{
	return string("总裁");
}