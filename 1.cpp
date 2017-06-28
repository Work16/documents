// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <iomanip>
using namespace std;




int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m, f;
	cout << "¬ведите размеры пр€моугольника:\n";
	cin >> n >> m;
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[m];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			matrix[i][j] = -1;
	cout << "¬ведите количество пр€моугольников:\n";
	cin >> f;
	int count = 0;
	for (int i = 0;i < f;i++)
	{for (int j = 0;j < 4;j++)
		{
			int a, b;
			cout << "¬ведите " << j + 1 << " координату " << i + 1 << "пр€моугольника:\n";
			cin >> a >> b;
			for (int i = 0;i < m;i++)
				matrix[a - 1][i] += 1;
			for (int j = 0;j < n;j++)
				matrix[j][b - 1] += 1;
		}
	system("cls");
}
	for (int i = 0;i < n;i++)
	{
		cout << endl;
		for (int j = 0;j < m;j++)
			cout << setw(3) << matrix[i][j];
	}
	cout << endl<<count <<endl;
	system("pause");
    return 0;
}

