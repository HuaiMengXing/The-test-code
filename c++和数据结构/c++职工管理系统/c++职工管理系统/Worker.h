#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Worker
{
public:
	virtual string getDeptName() = 0;//��λ����
	int m_ID=0;//ְ�����
	string m_Name;
	string m_Sex;
	int m_DeptID=0;//���ű��
	Worker* next;
private:

};
