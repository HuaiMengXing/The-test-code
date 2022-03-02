#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Worker
{
public:
	virtual string getDeptName() = 0;//岗位名称
	int m_ID=0;//职工编号
	string m_Name;
	string m_Sex;
	int m_DeptID=0;//部门编号
	Worker* next;
private:

};
