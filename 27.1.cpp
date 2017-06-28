// 27.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int>result;
vector <bool>used;
void numeration(int **&matrix, int n,int f)
{
	if (f == 0)
		return;
	int z;
	int count = 0;
	for (int j = 0;j < n;j++)
	{
		count = 0;
		for (int i = 0;i < n;i++)
			if (matrix[i][j] == 0)
				count++;
		if (count == n)
		{
			if (used[j] == false)
			{
				used[j] = true;
				z = j;
				result.push_back(j);
				break;
			}
		}
	}
	for (int i = 0;i < n;i++)
		matrix[z][i] = 0;
	numeration(matrix, n, f - 1);

}


int main()
{
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество вершин графа:\n";
	cin >> n;
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cout << "Введите [" << i + 1 << "," << j + 1 << "] элемент матрици смежности :";
			cin >> matrix[i][j];
		}
	for (int i = 0;i < n;i++)
		used.push_back(false);
	numeration(matrix, n, n);
	for (int i = 0;i < size(result);i++)
		cout << i << "-" << result[i] << endl;
	system("pause");
    return 0;
}

