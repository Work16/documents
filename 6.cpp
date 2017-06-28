// 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct list
{
	int indicator;
	list *next;
};

void builder(list *&beg, int m)
{
	while (m)
	{
		if (beg)
		{
			list *temp=new list;
			temp->indicator = -1;
			temp->next = beg;
			beg->next = temp;
		}
		else
		{
			beg = new list;
			beg->indicator = -1;
			beg->next = beg;
		}
		m--;
	}
	 
}
void print(list *beg, int m)
{
	if (beg)
	while (m)
	{
		if (beg->indicator == 1)
			cout << "Герб\n";
		else if (beg->indicator == -1)
			cout << "Решка\n";
		else
			cout << ":)";
		beg = beg->next;
		m--;
	}
}

/*int amount(list *beg)
{
	int z = 0;
	while (beg)
	{
		z++;
		beg = beg->next;
	}
	return z;
}

void work(list *&beg, int m, int l, int s, int k)
{
	int count = 0, many = amount(beg), f = l - many;
	list *temp = beg;
	temp->indicator = 1;
	temp = temp->next;
	while (k)
	{
		count = 0;
		while (count != s)
		{
			temp = temp->next;
			count++;
		}
		temp->indicator = 0;
		k--;
	}
	temp = beg;
	if (f > 0)
	{
		while (f && temp)
		{
			if (temp->indicator != 0)
			{
				temp->indicator = 1;
				temp = temp->next;
				f--;
			}
			else
				temp = temp->next;
         }
	}
	

}*/
list *move(list *beg, int z)
{
	while (z > 0)
	{
	beg = beg->next;z--;
	}
	return beg;
}
void work(list *&beg, int n, int m, int l, int s, int k)
{
	int z = s;
	list *temp = beg;
	beg->indicator = 1;
	beg = temp->next;
	while (k > 0)
	{
		beg = move(beg, z);
		beg->indicator = 2;
		k--;
	}
	//print(beg,n+m);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	list *p=NULL;
	int m, l, s, k, n;
	cout << "Введите количество монет Г:\n";
	cin >> n;
	cout << "Введите количество монет Р:\n";
	cin >> m;
	cout << "Введите шаг:\n";
	cin >> s;
	cout << "Ведите количество шагов:\n";
	cin >> k;
	cout << "Введите количество гербов:\n";
	cin >> l;
	builder(p, m);
	//work(p, m, l, s, k);
	print(p, m+n);
	system("pause");
    return 0;
}

