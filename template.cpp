// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


template <typename m>
m max ( m a, m b)
{
	if (a > b)
		return a;
	return b;
}
template <> int max(int a, int b)

{

	if (a > b)
		return a;
	return b;
}

/*int &  p(int a)
{
	a++;
int *p = &a;
	return *p;
}
int main()

{
	register int i=10000;
	cout << i << endl;;
	/*const int n = 5;
	int *p = new int (n);
	int (*z)[n] = new int[n][n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			z[i][j] = i + j;
	for (int i = 0;i < n;i++)
	{
		cout << endl;
		for (int j = 0;j < n;j++)
			cout << setw(3) << z[i][j];
	}
	/*int x, y, z;
	x = (y = 1, z = 4);
	cout << x << " " << y << " " << z;
		cout << endl;
	int a = 1;
	// p(a);
	cout << p(a);
	system("pause");
    return 0;

}*/
int main()
{
	cout << max(0.0, 1.1) << endl;
	system("pause");
	return 0;
}
