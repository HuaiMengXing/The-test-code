#pragma once
#include"Worker.h"

class Employee:public Worker
{
public:
	Employee(int id, string name,string sex, int did);
	virtual string getDeptName();//��λ����
private:

};

class Manager:public Worker
{
public:
	Manager(int id, string name, string sex, int did);
	virtual string getDeptName();//��λ����
private:

};

class Boss :public Worker
{
public:
	Boss(int id, string name, string sex, int did);
	virtual string getDeptName();//��λ����
private:

};