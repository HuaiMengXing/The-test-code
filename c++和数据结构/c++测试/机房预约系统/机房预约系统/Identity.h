#pragma once
#include<iostream>
using namespace std;

class Identity
{
public:

	//�����˵� ���麯��(���������д���ຯ����
	virtual void operMenu() = 0;

	//����
	string m_Name;
	//����
	string m_Pwd;

};