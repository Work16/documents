// 13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip> 
using namespace std;

extern int ** creating(int **,int );
int *  search (int *a,int **matrix,int n)
{
	int count_i = 0, count_j = 0, z = 0;
	for (int k = 0;k < n;k++)
	{
		count_i = 0;
		for (int i = 0;i < n;i++)
		{
			count_j = 1;
			count_i++;
			if (count_i + k < n)
			{
				count_j++;
				for (int j = 0;j < n;j++)
				{
					if (count_j + j > (n - 1))
						break;
					else
					{
						if (a[0] < matrix[k][j] + matrix[k + count_i][j] + matrix[k][j + count_j] + matrix[k + count_i][j + count_j])
						{
							a[0] = matrix[k][j] + matrix[k + count_i][j] + matrix[k][j + count_j] + matrix[k + count_i][j + count_j];
							a[1] = k;
							a[2] = j;
							a[3] = count_i;
							a[4] = count_j;
						}
					}
				}
			}
		}
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите размерность матрици :\n";
	cin >> n;
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	matrix =creating(matrix, n);
	int f=5;
	int *a = new int[f];
	a[0] = -15978334;
	for (int i = 1;i < n;i++)
		a[i] = 0;
	
	/*for (int i = 0;i < n;i++)
	{
		count_i = 0;
		if (count_i < n - i)
		{
			count_i++;
			for (int k = 0;k < n;k++)
		
				if (count_j+1 < n)
				{
					count_j++;
					for (j = 0;j < n;j++)
					{
						if (a[0] < matrix[i][j] + matrix[i + count_i][j] + matrix[i][j + count_j] + matrix[i + count_i][j + count_j])
						{
							a[0] = matrix[i][j] + matrix[i + count_i][j] + matrix[i][j + count_j] + matrix[i + count_i][j + count_j];
							a[1] = i;
							a[2] = j;
							a[3] = count_i;
							a[4] = count_j;
						}
					}
				
				}
			}
		}*/
	a=search(a, matrix, n);
	system("cls");
	for (int i = 0;i < n;i++)
	{
	  cout << endl;
		for (int j = 0;j < n;j++)
			cout <<setw(3)<< matrix[i][j];
	}
	cout <<endl<<"***" <<endl;
	for (int i = 0;i < 5;i++)
		cout << a[i] << endl;
	system("pause");
    return 0;
}
