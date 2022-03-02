#include"swap.h"
void caishuzi()
{
	int num = rand() % 101,num1;
	cout << "\t*******************" << endl;
	cout << "\t  猜数字游戏开始" << endl;
	cout << "\t*******************" << endl;
	cout << "请输入你所猜的数字:";
	cin >> num1;
	while (num1!=num)
	{
		if (num1>num)
		{
			cout << "你猜的结果过大，请重新猜：";
			cin >> num1;
		}
		if (num1 < num)
		{
			cout << "你猜的结果过小，请重新猜：";
			cin >> num1;
		}
	}
	cout << "恭喜你猜对了" << endl;
	system("pause");
}
void px()
{
	int a[10], i, j, term;
	cout << "请输入10个数字" << endl;
	for (i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				term = a[j];
				a[j] = a[j + 1];
				a[j + 1] = term;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
}