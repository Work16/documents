// 27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
vector <bool>visited;
void dfs(int **&matrix, int n,int i,int j,vector<int>&stack)
{
	int count = 0;
	for (int f = 0;f<size(stack);f++)
		if (stack[f] == i)
			count++;
	visited[i] = true;
	if (count==0)
	stack.push_back(i);
	matrix[i][j] = 0;
	for (int k = 0;k < n;k++)
		if (matrix[j][k]==1 && visited[j]==false)
			dfs(matrix, n, j, k, stack);
}


int main()
{
	int n ;
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
	system("cls");
	for (int i = 0;i < n;i++)
		visited.push_back(false);
	vector <int>stack;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (matrix[i][j]==1 )
				dfs(matrix, n,i , j, stack);
	cout << "M-нумерация графа:\n";
	for (int i = 0;i < size(stack);i++)
		cout << i << "-" << stack[i] << endl;
	cout << endl;
	system("pause");
	return 0;
}

