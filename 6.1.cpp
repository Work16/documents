// 6.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include <iostream>
using namespace std;

int *typo(int *massive, int n, int m, int s, int k)
{
	int i = -1;
	int h = s;
	while (k > 0)
	{
		s = h;
		while (s > 0)
		{
			i++;
			if (i == n + m)
				i = 0;
			s--;
		}
		if (i != 0)
			massive[i] = 2;
		k--;
	}
	return massive;
}
int * right_choice(int *massive,int n,int l,int m )
{
	int z = n - l;
	for (int i = 0;i < n + m;i++)
	{
		if (massive[i] == 0)
		{
			if (l - 1 > 0)
			{
				massive[i] = 1;
				l--;
			}
			else if (m > 0)
			{
				massive[i] = -1;m--;
			}
		}
		else if (massive[i] == 2)
		{
			if (z > 0)
			{
				massive[i] = 1;
				z--;
			}
			else if (m > 0)
			{
				massive[i] = -1; m--;
			}
		}
	}
	return massive;
}
bool prov(int *massive, int n, int m)
{
	for (int i = 0;i < n + m;i++)
		if (massive[i] == 2)
			return false;
	return true;
}


int main()
{
	setlocale(LC_ALL, "Russian");
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
	int *massive = new int [n + m];
	for (int i = 0;i < n + m;i++)
		massive[i] = 0;
	massive[0] = 1;
	massive = typo(massive, n, m, s, k);
	massive = right_choice(massive, n, l, m);
	system("cls");
	if (prov(massive, n, m))
		for (int i = 0;i < n + m;i++)
			if (massive[i] == 1)
				cout << "Герб\n";
			else
				cout << "Решка\n";
	else
		cout << "Такая последовательность не существует \n";
	system("pause");
    return 0;
}

