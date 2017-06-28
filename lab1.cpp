// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Header.h"
using namespace std;


//extern void write(vector<int>, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите количество переменных:";
	cin >> n;
	vector<int>comb(2 * n);
	write(comb, n);
	system("pause");
    return 0;
}

