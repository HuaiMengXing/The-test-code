#pragma once
#include"Point.h"
#include<iostream>
#include<ctime>
#include<string>
using namespace std;
class Circle
{
public:
	void setR(int r);
	int getR();
	void setCenter(Point center);
	Point getCenter();
	~Circle()
	{
		cout << "aaaaa" << endl;
	}
private:
	int R;
	Point Center;
};
