// The problem about nuts and bolts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void quickSort(vector<int> &massive, int start, int n,int p) {
	// Input - massiv massive[], massive[n] - the last element.

	int i = start, j = n - 1;
	//int  p;

	//p = massive[(start + n) / 2];		// midle element

										// procedure division
	do {
		while (massive[i] < p) i++;
		while (massive[j] > p) j--;

		if (i <= j) {
			swap(massive[i], massive[j]);
			i++; j--;
		}
	} while (i <= j);


	//recursive calls, if you have something to sort
	//if (j >start) quickSort(massive, start, j,p);
	//if (n > i) quickSort(massive, i, n,p);
}

void func(vector<int>&bolts, vector<int>&nuts, int n)
{
	for (int i = 0;i < n;i++)
	{
		quickSort(bolts, 0, n, nuts[i]);
		quickSort(nuts, 0, n, bolts[i]);
	}
}

void read(vector<int>&bolts,vector<int >&nuts,int &n)
{
	ifstream in("3.1.txt");
	if (!in.is_open())
	{
		cout << "File could not be opened!\n";
		system("pause");
		exit(1);
	}
	in >> n;
	int  z;
	//in >> z;
	for (int i = 0;i < n;i++)
	{
		in >> z;
		bolts.push_back(z);
	}
	for (int i = 0;i < n;i++)
	{
		in >> z;
		nuts.push_back(z);
	}
	in.close();
}

int main()
{
	vector<int>bolts;
	vector<int>nuts;
	int n = 0;
	read(bolts, nuts,n);
	func(bolts, nuts, size(nuts));
	for (int i = 0;i < size(bolts);i++)
		cout << bolts[i] << " ";
	cout << endl;
	for (int i = 0;i < size(bolts);i++)
		cout << nuts[i] << " ";
	cout << endl;
	system("pause");
    return 0;
}

