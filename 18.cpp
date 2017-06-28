// 18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
/*// i and j -coordinate of the first point
void dfs(int *&matrix_c, int **&matrix, int n, int i, int j ,int &k,int &l,int &c,int&h)
{
	//do
	//
				matrix_c[0] = i;
				matrix_c[1] = j;
				c = 2;
		matrix[k][l] = 0;
		//????matrix[l][k] = 0;
		matrix_c[c] = l;
		c++;
		for (int f = 0;f < n;f++)
		{
			if (matrix[l][f] == 1 )
			{
				h = 0;
				dfs(matrix_c, matrix, n, i, j, l, f, c,h);
				if ((matrix[l][f] == 2 )&& (h <2))

					{
						h++;
						dfs(matrix_c, matrix, n, i, j, l, f, c, h);
					}
					}
		}

		/*if (i!=k && j!=l)
		for (int z = 0;z < n;z++)
			matrix_c[z] = 0;
		c = -1;
		return;
	//} while (k != i && l != j);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите количество вершин графа:\n";
	int n;
	cin >> n;
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = 0;
	int **matrix_c = new int *[n];
	for (int i = 0;i < n;i++)
		matrix_c[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix_c[i][j] = 0;
	int count = 0,c=0;
	for (int i = 0;i < n;i++)
	{
		system("cls");
		for (int j = 0;j < n;j++)
		{
			if (i != j)
			{
				cout << "явл€ютс€ ли вершины " << i + 1 << "и " << j + 1 << "смежными?\n";
				int a;
				cin >> a;
				if (a == 1)
				{
					matrix[i][j] = 1;
					matrix[j][i] = 1;
				}
			}
		}
	} int h = 0;

	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (matrix[i][j] == 1)
			{
				dfs(matrix_c[count], matrix, n, i, j, i, j,c,h);
				if (c!=-1)
					count++;h = 0;
			}
	system("cls");
	for (int i = 0;i < count;i++)
	{
		cout << endl;
		for (int j = 0;j < n;j++)
			cout << setw(3) << matrix_c[i][j]+1;
	}
	cout << endl;
	system("pause");
    return 0;
}*/










int main()
{
	int count = 0;
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите количество вершин графа:\n";
	cin >> n;
	bool **table = new bool *[n];
	for (int i = 0;i < n;i++)
		table[i] = new bool[n*n];
	bool **table2 = new bool *[n];
	for (int i = 0;i < n;i++)
		table2[i] = new bool[n*n];
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n*n;j++)
		{
			cout << "явл€ютс€ " << i + 1 << "вершина и (" <<( j / n)+1 << "," << (j%n)+1<< ") ребро инциндентными:\n";
			bool symbol;
			cin >> symbol;
			if (symbol)
			{
				table[i][j] = 1;
				count++;
			}
		}
	}
	int g = count / 2 - n + 1;
	bool **matrix = new bool *[g];
	for (int i = 0;i < g;i++)
		matrix[i] = new bool[n + (n*n)];

	system("pause");
	return 0;
}