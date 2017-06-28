#include "stdafx.h"
#include <iostream>
using namespace std;

int ** copy(int **matrix, int n, int value)
{
	int **matrix_copy = new int *[n];
	for (int i = 0;i < n;i++)
		matrix_copy[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix_copy[i][j] = matrix[i][j];
	return matrix_copy;
}