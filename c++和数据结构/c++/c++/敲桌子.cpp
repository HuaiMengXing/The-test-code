#include"swap.h"
void qiaozhuozi()
{
	int i = 0;
	for ( i = 0; i < 100; i++)
	{
		if (i % 7 == 0 || i % 10 == 7 || i % 7 == 0)
		{
			cout << "ÇÃ×À×Ó" << endl;
		}
		else
			cout << i << endl;
	}
}