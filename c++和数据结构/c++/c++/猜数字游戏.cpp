#include"swap.h"
void caishuzi()
{
	int num = rand() % 101,num1;
	cout << "\t*******************" << endl;
	cout << "\t  ��������Ϸ��ʼ" << endl;
	cout << "\t*******************" << endl;
	cout << "�����������µ�����:";
	cin >> num1;
	while (num1!=num)
	{
		if (num1>num)
		{
			cout << "��µĽ�����������²£�";
			cin >> num1;
		}
		if (num1 < num)
		{
			cout << "��µĽ����С�������²£�";
			cin >> num1;
		}
	}
	cout << "��ϲ��¶���" << endl;
	system("pause");
}
void px()
{
	int a[10], i, j, term;
	cout << "������10������" << endl;
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