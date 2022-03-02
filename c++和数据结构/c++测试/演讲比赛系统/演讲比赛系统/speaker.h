#pragma once
#include<iostream>
using namespace std;

//选手类
class Speaker
{
public:
	Speaker();
	~Speaker();
	string m_Name;
	double m_Score[2]={0};//有可能有两次分数
};
