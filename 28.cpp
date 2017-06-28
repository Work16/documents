// 28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct list
{
	double val;
	list *next;
};

void add(list *&beg, double  value)
{
	if (beg)
	{
		if (value < beg->val)
		{
			list *temp = new list;
			temp->next = beg;
			temp->val = value;
			beg = temp;
			return;
		}
		list *temp = beg;
		while (temp->next && temp->next->val<value)
			temp = temp->next;
		if (temp->next )
		{
			list *z = new list;
			z->val = value;
			list *f = temp->next;
			temp->next = z;
			z->next = f;
			return;
		}
		else
		{
			temp->next = new list;
			temp->next->val = value;
			temp->next->next = NULL;
		}

	}
	else
	{
		beg = new list;
		beg->next = NULL;
		beg->val = value;
	}
}

void print(list *beg)
{
	while (beg)
	{
		cout << beg->val << endl;
		beg = beg->next;
	}
}

double * rewriting(list **massive,  double *a, int b)
{
	static int j = 0;
	for (int i = 0;i < b;i++)
	{
		while (massive[i])
		{
			a[j] = massive[i]->val;
			massive[i] = massive[i]->next;
			j++;
		}
	}
	return a;

}


int main()
{
	const int  b = 10;
	double  a[b] = { 0.23,0.35,0.69,0.75,0.1,0.6,0.45,0.5,0.2,0.8 };
	for (int i = 0;i < b;i++)
		cout << a[i] << endl;
	list **massive = new list *[b];
	for (int i = 0;i < b;i++)
		massive[i] = NULL;
	int c = 1 % b;
	for (int i = 0;i < b;i++)
	{
		add(massive[c], a[i]);
	}
	rewriting(massive,  a, b);
	cout << "\n**************\n";
	for (int i = 0;i < b;i++)
		cout << a[i] << endl;
	system("pause");
    return 0;
}

