// 35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


extern void write(int **&, int);
extern bool dfs(int **, int,int,int,int,int,int);
extern int** copy(int **, int);
extern void dfs2(int **&, int, int,int);

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество сравниваемых параметров:\n";
	int n;
	cin >> n;
	int **matrix_include = new int *[n];
	for (int i = 0;i < n;i++)
		matrix_include[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix_include[i][j] = 0;
	write(matrix_include, n);
	int **matrix =new  int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	matrix = copy(matrix_include, n);
	int count = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (matrix[i][j] == 1)
			{
				dfs2(matrix, n, i, j);
				count++;
			}
	if (count > 0)
	{
		cout << "Нельзя сформировать возрастающию последовательность!\n";
		system("pause");
		return 0;
	}
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (!dfs(matrix_include, n, i, j, -1, -1,0))
			{
				cout << "Нельзя сформировать возрастающию последовательность!\n";
				system("pause");
				return 0;
			}
	cout << "Можно сформировать возрастающию последовательность!\n";
	system("pause");
	return 0;
}
