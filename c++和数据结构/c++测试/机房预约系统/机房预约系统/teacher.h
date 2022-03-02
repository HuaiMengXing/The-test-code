#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;

class Teacher:public Identity
{
public:

	Teacher();

	Teacher(string empId,string name,string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	~Teacher();

	//职工编号
	int m_EmpId;

};