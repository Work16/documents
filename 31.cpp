// 31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

long long  fact(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 1;
	else return x*fact(x - 1);
}

int main()
{
	long float z, s = 0, h = 2, k = 0;
	int i = 0;
	float eps = 0.1;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите ваше значение:\n";
	cin >> z;
	while ((-45>z)|| (z>45))
	{
		while (z > 45)
			z = z - 180;
		while (-45 > z )
			z = z + 180;
	}
	//long double s = 1, f = 0;
	while (h>eps)
	{
		/*double f = 0, s = 0;
		l *=z;
		i++;
		f = s;
		for (int j = 2*i-1;j < 2 * i;j++)
			if (j>0)
		factorial =factorial* j;
		s += pow((-1), i)*(l / factorial);
		h = s - f;
		z = s;*/
	long  float 	f = s;
		k = ((pow((-1), i)*pow(z, 2 * i)));
		for (int j = 1;j <= 2 * i;j++)
			k /= j;
     	//cout <<fact(2*i)<<' '<< s<<endl;
		i++;
		s += k;
		if (i != 1)
			h = fabs(s-f);
	}
	cout << "¬аш результат:" << s<< endl;
	system("pause");
    return 0;
}

