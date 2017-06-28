// 14.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int * sort(int *a, int n)
{
	if (n == 1)
		return a;
	for (int i = n-1;i >= 0;i--)
	{
		if ((i - 1) / 2 >= 0 && (i - 1) / 2 < n && (i - 1) % 2 == 0)
		{
			if (a[(i - 1) / 2] < a[i])
				swap(a[(i - 1) / 2], a[i]);
		}
		else	if (i / 2 >= 0 && i / 2 < n && i % 2 == 0)
		{
			if (a[i / 2] < a[i])
				swap(a[i / 2], a[i]);
		}
	}
	swap(a[0], a[n-1]);
	return sort(a, n - 1);
		
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество элементов масива:\n";
	int n;
	cin >> n;
	int *a = new int [n];
	for (int i = 0;i < n;i++)
	{
		cout << "Введите " << i + 1 << " значение масива:\n";
		cin >> a[i];
	}
	sort(a, n);
	cout << "********************\n";
	for (int i = 0;i < n;i++)
		cout << a[i] << "  ";
	cout << endl;
	system("pause");
    return 0;
}

