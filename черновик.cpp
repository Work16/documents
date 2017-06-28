// черновик.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

class complex
{
private :
	float real;
	float imagine;
public:
void	com()
	{
		real = imagine = 0;
	};
friend	complex operator +(complex,complex);
	friend complex operator -(complex,complex);
	friend complex operator *(complex,complex);
	friend complex operator /(complex,complex);
	friend void operator == (complex &, complex);
	friend complex operator ^(complex, int);
	void enter()
	{
		float a, b;
		cout << "Enter your number:\n";
		cin >> a >> b;
		real = a;
		imagine =b;
	}
	void show()
	{
		cout << real << "+ " << imagine<<"*i" << endl;
		system("pause");
	}
	~complex()
	{
		com();
}
};
complex operator +(complex a,complex b)
{
	a.real+= b.real;
	a.imagine+= b.imagine;
	return a;
}
complex operator -(complex a, complex b)
{
	//complex c;
	//c.com();
	a.real -= b.real;
	a.imagine -= b.imagine;
	return a;
}
complex operator *(complex a, complex b)
{
	complex c;
	c.com();
	c.real = a.real*b.real - a.imagine*b.imagine;
	c.imagine = a.real*b.imagine+ b.real*a.imagine;
	return c;
}
complex operator / (complex a, complex b)
{
	complex c;
	c.com();
	c.real = (a.real*b.real + a.imagine*b.imagine) / (b.real*b.real + b.imagine*b.imagine);
	c.imagine = (b.real*a.imagine - a.real*b.imagine) / (b.real*b.real + b.imagine*b.imagine);
	return c;
}
void operator == (complex &a, complex b)
{
	a.real = b.real;
	a.imagine = b.imagine;
	//return a;
}
complex operator ^(complex a, int b)
{
	complex c;
	c.com();
	c == a;
	while (b-1)
	{
		c == c*a;
		b--;
	}
	return c;
}

int main()
{
	complex a, b,c;
	c.com();
	//(a + b).show ();
	//system("pause");
	while (1)
	{
		cout << "\t\t\tComplex calcurator\t\t\t\n";
		//complex a, b;
		system("cls");
		cout << "\t\t\tComplex calcurator\t\t\t\n";
		cout << "1.Enter\n2.+\n3.-\n4.*\n5./\n6.^\n7.Exit\n";
		int f;
		cin >> f;
		system("cls");
		cout << "\t\t\tComplex calcurator\t\t\t\n";
		switch (f-1)
		{
		case 0:
		{a.enter();
		b.enter();
		break;};
		case 1:
		{
			//c ==a;
			(a+ b).show();
			//c.~complex();
			break;
		};
		case 2:
		{
			//c== a;
			(a - b).show();
			//c.~complex();
			break;
		};
		case 3:
		{
			//c ==a;
			(a*b).show();
			//c.~complex();
			break;
		};
		case 4:
		{
		//	c == a;
			(a/b).show();
			//c.~complex();
			break;
		};
		case 5:
		{
			cout << "Choose the number :\n";
			int k;
			cin >> k;
			switch (k - 1)
			{
			case 0:
			{
				cout << "Enter power:\n";
				cin >> k;
				//c == a;
				(a^k).show();
				//c.~complex();
				break;
			};
			case 1:
			{
				cout << "Enter power:\n";
				cin >> k;
				//c == b;
				(b^k).show();
				//c.~complex();
				break;
			};
			}
			break;
		};
		case 6:
		{
			a.~complex();
			b.~complex();
			exit(0);
		}
		}
	}
	system("pause");
	return 0;
}