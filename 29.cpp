// 29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int  count(vector<char>result)
{
	int j = 0;
	vector<int> numbers;
	for (int i = 0;i < size(result);i++)
	{
		if (result[i] == '+')
		{
			numbers[j -2] = numbers[j - 2] + numbers[j-1];
			numbers.erase(numbers.begin()+j-1);
			j--;
		}
		else if (result[i] == '-')
		{
			numbers[j - 2] = numbers[j - 2] - numbers[j-1];
			numbers.erase(numbers.begin()+j-1);
			j--;
		}
		else if (result[i] == '*')
		{
			numbers[j - 2] = numbers[j - 2] * numbers[j-1];
			numbers.erase(numbers.begin()+j-1);
			j--;
		}
			else if (result[i] == '/')
		{
			if (numbers[j - 2] == 0)
			{
				cout << "Не определенность!\n";
				system("pause");
				return -1;
			}
			numbers[j - 2] = numbers[j - 2] / numbers[j-1];
			numbers.erase(numbers.begin()+j-1);
			j--;
		}
			else
			{
				numbers.push_back(result[i]-'0');
				j++;
			}
	}
	return numbers[0];
}

void sss( vector<char> &result, vector<char>&stack, char symbol)
{
	//stack.push_back(symbol);
	if (!stack.empty())
		if (symbol == '+' || symbol == '-')
		{
			for (int i =0;i<size(stack);i++)
			{
		       	result.push_back(stack[i]);
				//stack.erase(stack.end()-i);
				//i = size(stack);
			}
			stack.erase(stack.begin(),stack.end());
		}
		else
		{
			for (int i = 0;i <size(stack);i++)
			{
				if (stack[i] == '*' || stack[i] == '/')
				{
					result.push_back( stack[i]);
					stack.erase(stack.begin()+i);
					//i = size(stack);
					//i = 0;
				}
			}
			//stack.erase(stack.begin(),stack.end());
		}
	//else
		//j++;
	stack.insert(stack.begin(),symbol);
}
int main()
{
	/*char str[50];
	ifstream in;
	in.open("29.txt");
	/*if (in.is_open())
		cout << 5;
	else
		while (in.get(str))
			cout << str;
	in.close();
	in >> str;
	cout << str;*/
	string str;
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	//char buff[50]; // буфер промежуточного хранения считываемого из файла текста
	/*ofstream p("29.txt");
	p << "2+3*100/10";
	p.close*/
	ifstream fin("29.txt"); // открыли файл для чтения

/*	fin >> buff; // считали первое слово из файла
	//cout << buff<<endl ; // напечатали это слово*/

	fin >> str; // считали строку из файла
	fin.close(); // закрываем файл
	vector<char> stack;
	vector<char>  result;
	for (int i = 0;i < size(str);i++)
	{
 		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			sss(result, stack, str[i]);
		}
		else
		{
			result.push_back( str[i]);
		}
	}
	for (int i = size(stack)-1 ;i >= 0;i--)
		result.push_back(stack[i]);
	cout << str << "\n*****************\n";
	stack.erase(stack.begin(), stack.end());

	for (int i = 0;i < size(result);i++)
		cout << result[i];
	cout <<"="<<count(result)<< endl;
	system("pause");
    return 0;
}

