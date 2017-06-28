// 15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;


struct list
{
	int val;
	int level;
	list *next;
};


void add(list *&beg, int v, int l)
{
	if (beg)
	{
		list *temp = new list;
		temp->val = v;
		temp->level = -1;
		temp->next = beg;
		beg = temp;
	}
	else
	{
		beg = new list;
		beg->val = v;
		beg->level = 0;
		beg->next = nullptr;
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
/*vector<int>quee;
void wave(list **&beg,int n,int f,int k,int **matrix)
{
	//static vector <int> quee;
	//for (int i = 0;i < n;i++)
	//{
	static int count = 0;
		list *temp = beg[k];
		while (temp)
		{
			if (matrix[k][temp->val] = -1)
				//	return;
			{
				matrix[k][temp->val] = f;
				//temp->level = f;
				count++;
				quee.push_back(temp->val);
			}
			temp = temp->next;
		}
		if (size(quee) == 0)
				return;
			int a = quee[0];
			if (count > 0)
				count--;
			if (count == 0)
				f++;
			quee.erase(quee.begin());
			wave(beg, n, f, a,matrix);
}


void show(list **beg, int i)
{}*/
vector<int>quee;
void sort(list **beg, int **&matrix, int n, int ver,int i)
{
	quee.push_back(i);
     while (beg[i])

}
int main()
{
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите количество вершин графа:\n";
	cin >> n;
	list **p = new list *[n];
	for (int i = 0;i < n;i++)
		p[i] = nullptr;
	for (int i = 0;i < n;i++)
	{
		int a;
		cout << "¬ведите смежные с " << i + 1 << "вершины:";
		cin >> a;
		while (n >= a && a > 0)
		{
			add(p[i], a - 1, 0);
			cout << "¬ведите смежные с " << i + 1 << "вершины:";
			cin >> a;
			}
	}
	/*int **matrix = new int *[n];
	for (int i = 0;i < n;i++)
		matrix[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = -1;
	wave(p, n, 0, 0,matrix);
//	show(p, 1);
	for (int i = 0;i < n;i++)
	{
		cout << endl;
		for (int j = 0;j < n;j++)
			cout << setw(3) << matrix[i][j];
	}*/
	cout << "¬ведите вершину:\n";
	int ver;
	cin >> ver;
	system("pause");
    return 0;
}



