#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;

class Teacher:public Identity
{
public:

	Teacher();

	Teacher(string empId,string name,string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	~Teacher();

	//ְ�����
	int m_EmpId;

};