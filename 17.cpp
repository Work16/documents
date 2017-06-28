// 17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct list
{
	int val;
	list *next;
};

void add(list *&beg, int v)
{
	if (beg)
	{
		list *temp = new list;
		temp->val = v;
		temp->next = beg;
		beg = temp;
	}
	else
	{
		beg = new list;
		beg->val = v;
		beg->next = nullptr;
	}
}

int ** list_matrix(list **beg, int ** matrix, int n)
{
	for (int i = 0;i < n;i++)
	{
		while (beg[i])
		{
			matrix[i][beg[i]->val] = 1;
			beg[i] = beg[i]->next;
		}
	}
	return matrix;
}

int ** dos(int **matrix, int **matrix1, int n)
{
	int **matrix2 = new int *[n];
	for (int i = 0;i < n;i++)
		matrix2[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix2[i][j] = matrix[i][j];
	int **matrix3 = new int *[n];
	for (int i = 0;i < n;i++)
		matrix3[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix3[i][j] =matrix[i][j];
	for (int k = 0;k < n;k++)
	{
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
				matrix1[i][j] = matrix1[i][j] || matrix3[i][j];
		}
		int f = 0;
		for (int i = 0;i < n;i++)
		{
			for (int l = 0;l < n;l++)
			{
				f = 0;
				for (int j = 0;j < n;j++)
				{
					f += matrix2[i][j] & matrix[j][l];
				}
				if (f > 0)
					f = 1;
				matrix3[i][l] |= f;
			}
		}
		/*for (int i = n;i < n;i++)
			for (int j = 0;j < n;j++)
				cout << matrix3[i][j] << " ";*/
		//cout << "**************\n";
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				matrix2[i][j] = matrix3[i][j];
	}
	return matrix1;
}

int ** power(int **matrix, int n)
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (matrix[i][j] == 1 && matrix[j][i] == 0)
				matrix[i][j] = 0;
	return matrix;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите количество вершин:\n";
	cin >> n;
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = 0;
	list **beg = new list *[n];
	for (int i = 0;i < n;i++)
		beg[i] = nullptr;
	for (int i = 0;i < n;i++)
	{
		int a;
		cout << "¬ведите с " << i + 1 << " смежные вершины:\n";
		cin >> a;
		while (0<=(a - 1 ) && (a-1)<= n)
		{
			add(beg[i], a - 1);
			cin >> a;
		}
	}
	matrix=list_matrix(beg, matrix, n); 
	int **matrix1 = new int *[n];
	for (int i = 0;i < n;i++)
		matrix1[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix1[i][j] = matrix[i][j];
	matrix1 = dos(matrix, matrix1, n);
	matrix1 = power(matrix1, n);
	for (int i = 0;i < n;i++)
	{
		cout << endl;
		for (int j = 0;j < n;j++) 
			cout << setw(3) << matrix1[i][j];
	}
	cout << endl;
	system("pause");
    return 0;
}

