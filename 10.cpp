// 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct list
{
	int val;
	bool flag;
	list *next;
};
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
void add(list *&beg, int v)
{
	if (beg)
	{
		list *temp = beg;
		while (temp->next)
			temp = temp->next;
		temp->next = new list;
		temp->next->flag = false;
		temp->next->val = v;
		temp->next->next = nullptr;
	}
	else
	{
		beg = new list;
		beg->flag = false;
		beg->val = v;
		beg->next=nullptr;
	}
}
void print(list *beg)
{
	while (beg)
	{
		cout << beg->val << " ";
		beg = beg->next;
	}
}
vector<int>  eyler(list **beg, int n, vector<int > z,bool **&matrix,int j)
{
	int count=0;
	//for (int i = 0;i < n;i++)
	//{
		if (beg[j])
		{
			while (beg[j])
			{
				if (beg[j]->val)
					if (matrix[j][beg[j]->val] == 0)
					{
						//beg[i]->flag = true;
						matrix[j][beg[j]->val] = matrix[beg[j]->val][j] = 1;
						z.push_back(j);
						count++;
						return	eyler(beg, n, z, matrix, beg[j]->val);
					}
				//if (!beg[j]) break;
				if (count > 0)
					z.push_back(j);
				beg[j] = beg[j]->next;
			}
			z.push_back(j);
		}
		for (int i = 0;i < n;i++)
		{while (beg[i])
		{
			if (beg[i]->val)
				if (matrix[i][beg[i]->val] == 0)
				{
					//beg[i]->flag = true;
					matrix[i][beg[i]->val] = matrix[beg[i]->val][i] = 1;
					z.push_back(i);
					count++;
					return	eyler(beg, n, z, matrix, beg[i]->val);
				}
			//if (!beg[j]) break;
			if (count > 0)
				z.push_back(i);
			beg[i] = beg[i]->next;
		}
		//z.push_back(i);
		
	}
	return z;
	/*int count = 0,k;
	for (int i = 0;i < n;i++)
	{
		while (count)
		{
			count = 0;
			for (int j = 0;j < n;j++)
			{
				for (int k = i;k < n;k++)
				if (matrix[k][j] == 1)
				{
					matrix[k][j] = 0;
					matrix[j][k] = 0;
					//eyler(matrix, n, z);
					k = j;
					count++;
				}
			}
		}
		z.push_back(i);
	}*/
}
int main()
{
	/*ofstream out;
	out.open("10.txt");
	for (int i = 0;i < 10;i++)
		out << i;
	//print(p);
	cout << endl;*/
	/*ifstream in;
	int f;
	in.open("10.txt");
	for (int i = 0;i < 10;i++)
	{
		in >> f;
		cout << f;
		//f = 0;
	}*/
	int n;
	setlocale(LC_ALL, "Russian") ;
	cout << "¬ведите количество вершин графа:\n";
	cin >> n;
	list **p = new list *[n];
	for (int i = 0;i < n;i++)
		p[i] = nullptr;
	for (int i = 0;i < n;i++)
	{
		int a;
		cout << "¬ведите с " << i + 1 << " смежные вершины:\n";
		cin >> a;
		while (0 <= (a - 1) && (a - 1) <= n)
		{
			add(p[i], a - 1);
			cin >> a;
		}
	}
	bool **matrix = new bool *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new bool;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = 0;
	//matrix=list_matrix(p, matrix, n);
	vector<int> z;
	z=eyler(p, n, z,matrix,0);
		system("cls");
	for (int i = 0;i < size(z);i++)
		cout << z[i]+1 << " ";
	cout << endl;
	system("pause");
    return 0;
}

