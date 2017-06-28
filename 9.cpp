//#include "stdafx"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;



/*void dfs(int **&matrix, int n, int i, int j,vector<int> &visited3)
{
	int count = 0;
	//static vector <int> visited3;
	if (size(visited3) == n)
		return;
	for (int f = 0;f < size(visited3);f++)
		if (visited3[f] == i)
			count++;
	if (count==0)
	visited3.insert(visited3.begin(), i);
	static vector<int> visited;
	static vector<int> visited2;
	visited.insert(visited.begin(), i);
	visited2.insert(visited2.begin(), j);
	matrix[i][j] = 2;
	for (int k = 0;k < n;k++)
	{
		if (matrix[j][k] == 1)
			for (int z = 0;z < size(visited3);z++)
				if (j == visited3[z])
					break;
		dfs(matrix, n, j, k,visited3);
	}
	int a = visited[0];
	int b = visited2[0];
	if (size(visited) > 0)
	{
		visited.erase(visited.begin());
		visited.erase(visited2.begin());
	}
	dfs(matrix, n, a, b,visited3);
}*/


static int t = 1;

void dfs(int **&matrix, int n,int i,int j,int **&f,int **&m)
{
	m[i][j] = t;
	matrix[i][j] = 2;
	for (int k = 0;k < n;k++)
	{
		if (matrix[j][k] == 1)
		{
			dfs(matrix, n, j, k, f, m);/*t++;*/
		}
			if (matrix[i][j]==2 && m[j][k]!=0 &&m[j][k] <= t)
				f[j][k] = 1;
		}
	//t++;
	}
	//t++;


bool removing(int **matrix, int n,int **f)
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			if (matrix[i][j] == 1 && matrix[i][j] != f[i][j])
				return false;
		}for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
			{
				if (f[i][j] == 1 && matrix[i][j] != f[i][j])
					return false;
			}
		return true;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество вершин графа:\n";
	cin >> n;
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = 0;
	/*for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			char symbol;
			cout << "Вершини " << i + 1 << " и " << j + 1 << " смежные ?\n";
			cin >> symbol;
			if (symbol = 'y')
				matrix[i][j] = 1;
			system("cls");
		}
	system("cls");
	int count = 0;
	vector<int >visited3;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			if (count > 0)
			{
				cout << "Это не сводимый граф!\n";
				system("pause");
				return 0;
			}
			if (size(visited3) == n)
			{
				cout << "Это  сводимый граф!\n";
				system("pause");
				return 0;
			}
			dfs(matrix, n, i, j,visited3);
			count++;
		}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(3) << matrix[i][j];
		cout << endl;
	}*/
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cout << "Введите [" << i + 1 << "," << j + 1 << "] элемент матрицы смежности графа:\n";
			cin >> matrix[i][j];
		}
	int **m = new int *[n];
	for (int i = 0;i < n;i++)
		m[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			m[i][j] = 0;
	int **f = new int *[n];
	for (int i = 0;i < n;i++)
		f[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			f[i][j] = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (matrix[i][j] == 1)
				dfs(matrix, n, i, j,f,m);
	system("cls");
	if (removing(matrix, n, f))
		cout << "Yes\n";
	else
		cout << "No\n";
	system("pause");
	return 0;
}