#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;

class Student:public Identity
{
public:
	Student();

	Student(string id,string name, string pwd);

	~Student();

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
	int m_Id;

private:

};