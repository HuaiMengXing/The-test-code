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
	int m_Id;

private:

};