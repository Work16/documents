#include "stdafx.h"
#include <iostream>
using namespace std;

int **creating(int **matrix,int n)
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cout << "¬ведите [" << i + 1 << ";" << j + 1 << "] элемент матрицы:\n";
			cin >> matrix[i][j];
			//matrix[i][j] = rand()%10;
		}
	return matrix;
}