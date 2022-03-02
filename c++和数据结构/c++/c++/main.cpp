#include"swap.h"
#include"Point.h"
#include"circle.h"
class pos
{
public:
	int* pp(int a)
	{
		int* b = new int (a + a);
		cout << "aaaa" << endl;
		return b;
	}
	pos()
	{
		cout << "aaaaa" << endl;
	};
	pos(int a)
	{
		cout << "aaab" << endl;
	};
	~pos()
	{
		cout << "aaac" << endl;
	};

private:

};

void isInCircle(Circle &c, Point &p)
{
	int dis=
	(c.getCenter().getX() - p.getX())* (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDis = c.getR() * c.getR();
	if (dis==rDis)
	{
		cout << "点在圆上" << endl;
	}
	else if (dis>rDis)
	{
		cout << "外面" << endl;
	}
	else
	{
		cout << "里面" << endl;
	}
}

int main()
{
	
	pos p1(10);
	pos p2;
	int* u=p2.pp(10);
	cout << *u << endl;
	cout << *u << endl;
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);
	Point p;
	p.setX(10);
	p.setY(10);
	isInCircle(c, p);
	cout << *u << endl;
	cout << *u << endl;
	/*srand((unsigned int)time(NULL));
	int i=0;
	cout << "\t**********************************************" << endl;
	cout << "\t 1-水仙花数字  2-猜数字游戏 3-敲桌子 4-排序   " << endl;
	cout << "\t**********************************************" << endl;
	
	do
	{
		cout << "请选择：";
		cin >> i;
		switch (i)
		{
		case 1:shuixianhua(); break;
		case 2:caishuzi(); break;
		case 3:qiaozhuozi(); break;
		case 4:px(); break;
		default:
			cout << "输入错误";
			break;
		}
	} while (i != 8);
	return 0;*/
}