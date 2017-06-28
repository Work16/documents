// 24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main()
{
	int count = 0;
	string str;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите строку :\n";
	cin >> str;
	vector <char> tipo;
	vector <int> tipe;
	/*for (int i = 0;i < size(tipo);i++)
	{
		tipo[i] = ' ';
		tipe[i] = 0;
	}*/
	for (int i = 0;i < size(str);i++)
	{
		count = 0;
		for (int j = 0;j < size(tipo);j++)
		{
			if (str[i] == tipo[j])
			{
				tipe[j]++;count++;
			}
		}
			if (count == 0)
			{
				tipo.push_back(str[i]);
				tipe.push_back(1);
			}
	}
	for (int i = 0;i < size(tipe)-1;i++)
	{
		for (int j = 0;j < size(tipe);j++)
			if (tipe[j] >tipe[i])
			{
				swap(tipe[j], tipe[i]);
				swap(tipo[j], tipo[i]);
			}
	}
	/*cout << endl;int j;for (int i = 0;i < size(tipo);i++)
		cout << tipo[i] << " " << tipe[i] << endl;
	cout << "*****";*/
	int j;
	for (int i = 0;i < size(str);i++)
	{
		j= 0;
		while (tipo[j] != str[i])
		{
			cout << 1;
			j++;
		}
		cout << 0;
	}
	cout << endl;
	/*for (int i = 0;i < size(tipo);i++)
		cout << tipo[i] << " " << tipe[i] << endl;*/
		system("pause");
    return 0;
}

