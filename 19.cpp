// 19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Prima(int **matrix, int n, int i, int **&newmatrix)
{
	static int count = 0;
	count++;
	if (count == n - 1)
		return;
	int max = -1, max_j;
	for (int f = 0;f < n;f++)
		if (matrix[i][f]>max)
		{
			max = matrix[i][f];
			max_j = f;
		}
	newmatrix[max_j][i] = matrix[max_j][i];
	newmatrix[i][max_j] = matrix[i][max_j];
	Prima(matrix, n, max_j, newmatrix);
}


int main()
{
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество вершин графа:\n";
	cin >> n;
	system("cls");
	int **wage = new int *[n];
	for (int i = 0;i < n;i++)
		wage[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cout << "Введите вес ребра между " << i + 1 << " и " << j + 1 << "вершинами:\n";
			cin >> wage[i][j];
			system("cls");
		}
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = 0;

	system("pause");
    return 0;
}

