#include<stdio.h>
#include"string.h"
#include"stdlib.h"
#include"math.h"
#include<iostream>
using namespace std;

typedef struct add
{
	int a;
	struct add* next;
}*Tree;

int main()
{
	Tree t=(Tree)malloc(sizeof(int));
	if (t==NULL)
	{
		return 0;
	}
	cin >> t->a;
	//if (t==NULL)
	//{
	//	return 0;
	//}
	cout << t->a << endl;
	free(t);


	/*char T[11] = { "0abacababa" };
	int next[10]={0};
	int i=1, k=0;
	next[1] = 0;
	while (i<9)
	{
		if (k == 0 || T[i] == T[k])
		{
			++i;
			++k;
			next[i] = k;
		}
		else
			k = next[k];

	}
	for ( i = 1; i < 10; i++)
	{
		printf("%d", next[i]);
	}*/
	return 0;
}