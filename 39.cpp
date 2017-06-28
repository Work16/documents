// 39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void dfs(int **, int, int, int,int &);
bool prov(int **matrix, int n)
{
	int count = 0,z=0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{ 
			if (matrix[i][j] == 1)
				dfs(matrix, n, i, j,z);
			if (z >1)
				count++;
		}
	}
	if (count > 2)
		return false;
	else
		return true;
}

void dfs(int **matrix, int n,int i,int j,int &z)
{
	z++;
	matrix[i][j] = 0;
	for (int f = 0;f < n;f++)
		if (matrix[j][f] == 1)
			dfs(matrix, n, j, f,z);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество людей:\n";
	int n;
	cin >> n;
	cout << "Введите матрицу знакомств:\n";
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			if (i != j)
			{
				cout << "Введите [" << i + 1 << "," << j + 1 << "] элемент матрици:\n";
				cin >> matrix[i][j];
			}
		}
	system("cls");
	if (prov(matrix, n))
		cout << "Возможно\n";
	else
		cout << "НЕвозможно\n";
	system("pause");
    return 0;
}

