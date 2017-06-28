// Лабораторна робота №3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>
using namespace std;


void wegh(int*, bool*, int*&, int **, int, int,int);
int min_index(int *, int, bool*);
int *Dijkstra(int *, bool*, int*&, int**, int);

//functions for testing 
bool  test_min_index(int *wage,int n,bool *used)
{
	if (min_index(wage, n, used) != 0)
	{
		cout << " Problems with min_index function\n";
		system("pause");
		return 0;
	}
	return 1;
}
bool test_wegh(int *wage,int *ancestors,int**matrix,bool *used)
{
	const int n = 4;
	int wage2[n] = { 0,1,3,8 };
	wegh(wage, used, ancestors, matrix, 0, 1, n);
	for (int i = 0;i < n;i++)
		if (i == 1 && wage[i] != wage2[i] && ancestors[i] != 0)
		{
			cout << "Problem with wegh function\n";
			system("pause");
			return 0;
		}
		
	return 1;
}
bool test_Dijkstra(int *wage,bool *used,int *ancestors,int**matrix)
{
	const int n = 4;
	for (int i = 0;i < n;i++)
	{
	used[i] = 0;
		}
	int wage1[n] = { 0,1,3,3 };
	for (int i = 0;i < n;i++)
		if (Dijkstra(wage, used, ancestors, matrix, n)[i] != wage1[i])
		{
			cout << "Problem with Dijkstra function\n";
			system("pause");
			return 0;
		}
	return 1;
}
//main function for testing 
 bool test()
{
	const int n = 4;
	bool used[n] = { 0, 1, 0 };
	int wage[n] = { 0,INT_MAX,1,INT_MAX };
	if (!test_min_index(wage, n, used))
		return 0;
	int *ancestors =new int [n ];
	for (int i = 0;i < n;i++)
	{
		wage[i] = 0;
		ancestors[i] = 0;
		if (i!=0)
		wage[i] = INT_MAX;
	}
	int **matrix = new int*[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (i == 0 && j == 1)
				matrix[i][j] = 1;
			else if (i == 0 && j == 2)
				matrix[i][j] = 3;
			else if (i == 1 && j == 3)
				matrix[i][j] = 2;
			else
				matrix[i][j] = 0;
			if (!test_wegh(wage, ancestors, matrix, used))
				return 0;;
			if (!test_Dijkstra(wage, used, ancestors, matrix))
				return 0;
			return 1;
}
//function for counting and choosing the wage of the j top
void wegh(int *wage, bool *used, int*&ancestors, int **matrix,int n,int i,int j)
{
	if (used[j] == false && matrix[i][j] != 0)
	{
		if (wage[i] + matrix[i][j] <= wage[j])
		{
			ancestors[j] = i;
			wage[j] = wage[i] + matrix[i][j];
		}
	/*	else
			wage[j] = wage[j];*/
	}
}

//function for finding index of the minimal value from wages of the tops except wich is used
int min_index(int *wage, int n,bool *used)
{
	int k =INT_MAX;
	int k_index=-1;
	for (int i = 0;i < n;i++)
		if (used[i] == false && wage[i] < k)
		{
			k = wage[i];
			k_index = i;
		}
	//if (k == INT_MAX)return -1;
	return k_index;
}

//main function of the algoriphm
int *Dijkstra(int *wage, bool *used, int*&ancestors, int **matrix,int n)
{
	int index = 0;
	vector<thread> threads;
	while (index>=0)
		{
			used[index] = true;
			for (int j = 0;j < n;j++)
				threads.push_back(thread{ wegh, wage, used, ref(ancestors), matrix, n, index, j });
			for (auto &t:threads)
			t.join();
			index = min_index(wage, n, used);
			threads.erase(threads.begin(), threads.end());
		}
	return wage;
}
//threads function for showing the way from j top to first top
void outhelp(int *ancestors, int n, int *wage, int j)
{
	cout << "Way from " << j + 1 << " top  to first top:\n";
	while (j)
	{
		cout << ancestors[j] << " ";
		j = ancestors[j];
	}
	cout << "\nThe wage of the way is " << wage[j] << endl;;
}
//function for showing ways and its wages
void output(int *ancestors,int n,int *wage)
{
	vector<thread>threads;
	for (int i = 1;i < n;i++)
	{
			threads.push_back(thread{ outhelp,ancestors, n,wage, i });
		for (auto &t : threads)
			t.join();
		threads.erase(threads.begin(), threads.end());
	} 
}
 

int main()
{
	if (test())
	{int n;
	cout << "Enter amount of the tops of the graph :\n";
	cin >> n;
	int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cout << "Enter the wage of the rib beetween" << i + 1 << " and" << j + 1 << "tops:\n";
			cin >> matrix[i][j];
		}
	system("cls");
	bool *used = new bool[n];
	int *ancestors = new int[n];
	for (int i = 0;i < n;i++)
	{
		used[i] = false;
		ancestors[i] = 0;
	}
	int *wage = new int[n];
	wage[0] = 0;
	used[0] = true;
	for (int i = 1;i < n;i++)
		wage[i] = INT_MAX;
	wage = Dijkstra(wage, used, ancestors, matrix, n);
	output(ancestors, n, wage);
	delete[] wage;
	delete[] ancestors;
	for (int i = 0;i < n;i++)
		delete[] matrix[i];
	delete[] matrix;
}
	system("pause");
    return 0;
}

