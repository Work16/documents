// 33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int n = 2;
int matrix[n][n];
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
void bez( int &u, int &v,int a ,int b)
{
	int c[n][n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			c[i][j] = 0;
	if (a%b == 0)
	{
		u = matrix[1][0];
		v = matrix[1][1];
		return;
	}
	int f[n][n];
	f[0][0] = 0;
	f[0][1] = f[1][0] = 1;
	f[1][1] =- a / b;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			for (int k = 0;k < n;k++)
				c[i][j] += matrix[i][k] * f[k][j];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = c[i][j];
	bez(u,v,b, a / b);
}

int main()
{
	int x, y, c;
	cout << "Enter coefficients:\n";
	cin >> x >> y >> c;
	int znam = gcd(x, y);
	if (c%znam != 0)
	{
		cout << "Уравнение не имеет решения!\n";
		system("pause");
		return 0;
	}
	int  u = 0, v = 0, x0 = x / znam, y0 = y / znam, c0 = c / znam;
  matrix[0][0] = matrix[1][1] = 1;
  matrix[1][0] = matrix[0][1] = 0;
  bez(u, v, x, y);
  cout << "x=" << c0*u << "+n*" << y / znam << endl;
  cout << "y=" << c0*v << "-n*" << x / znam << endl;
	system("pause");
    return 0;
}

