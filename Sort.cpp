#include "stdafx.h"
#include <iostream>
using namespace std;

int **sort(int **matrix_copy, int n)
{
	for (int j = 0;j < n;j++)
		for (int k = 0;k < n - 1;k++)
		{
			bool check = false;
			for (int i = 0;i < n;i++)
				if (matrix_copy[i][j]<matrix_copy[i + 1][j])
				{
					swap(matrix_copy[i][j], matrix_copy[i + 1][j]); 
					check = true;
				}
			if (!check)
				break;
			}
	return 0;
}