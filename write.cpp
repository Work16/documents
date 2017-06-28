#include <stdafx.h>
#include <iostream>
using namespace std;
void  write(int ** &matrix_include, int n)
{
	char symbol;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{ 
			if (j != i)
			{
				cout << "Введите ""y"" если  " << i + 1 << " елемент больше " << j + 1 << " или ""n"" меньше и ""s"" в ином случае:\n";
				cin >> symbol;
				system("cls");
				if (symbol == 'y')
					matrix_include[i][j] = 1;
				else if (symbol == 'n')
					matrix_include[j][i] = 1;
				else
				{
					matrix_include[i][j] = 1;
					matrix_include[j][i] = 1;
				}
			}

		}
}