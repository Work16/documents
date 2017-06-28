// 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


struct list
{
	int val;
	int j;
	list *next;
};

struct all
{
	list *val;
	all *next;
};


void builder(list *&beg, int z, int i)
{
	if (beg)
	{
		list *temp = beg;
		while (temp->next)
			temp = temp->next;
		temp->next = new list;
		temp->next->j = i;
		temp->next->val = z;
		temp->next->next = NULL;
		//beg = temp;
	}
	else
	{
		beg = new list;
		beg->val = z;
		beg->j = i;
		beg->next = NULL;
	}
	//return beg;
}
/*void builder_2(all *&beg, int z, int i, bool flag)
{
	if (!flag)
	{
		beg->val = builder(beg->val, z, i);
		beg->next = nullptr;
		}
	else
	{
		all *temp = beg;
		//temp = temp->next;
	temp->val=	builder(temp->val, z, i);
	temp->next = beg;
	beg = temp;
	}
}*/
void search(list **beg, int &i, int &j, int n)
{
	int max = -1564;
	for (int f = 0;f < n;f++)
	{
		list*beg1 = beg[f];
		while (beg1)
		{
			if (beg1->val > max)
			{
				max = beg1->val;
				i = f;
				j = beg1->j;
			}
			beg1 = beg1->next;
		}
	}
}
void print(list **beg, int t,int i,int n)
{
	for (int f = 0;f < n;f++)
	{
		if (f != i)
			while (beg[f])
			{
				if ((beg[f]->j) != t)
					cout << setw(3) << beg[f]->val;
				beg[f] = beg[f]->next;
			}
		cout << endl;
	}
}

int main()
{
	const int n = 3;
	list **l = new list *[n];
	for (int i = 0;i < n;i++)
		l[i] = NULL;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			int a;
			cin >> a;
			builder(l[i], a, j);
		}
	system("cls");
	int z = 0, x = 0;
	list **t = l;
	search(t, z, x, n);
	print(l, x, z, n);
	//builder_2(l, 0, 0, 1);
	//cout << l->val << endl;
	cout << endl;
	system("pause");
    return 0;
}

