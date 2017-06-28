// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;




int main()
{ 
	const int n = 20000;
	double x=0.5, y = 1,sum=0;
	int count = 0;
	//x*x+y
	for (int i = 1;i < n + 1;i++)
	{
		/*double a = x*(rand()%9+1)*0.1;
		double b = y*(rand() %9+1)*0.1 ;
	//	if (0.5 <= a && 1 >= b >= 0)
			sum += a*a + b*b;
		//else
		//	i--;
	}*/
		x = 0.5+(1 % i)*0.15;
		if (1 >= x >= 0.5)
		{
			y = 1 % i*0.12;
			if (2*x-1>= y >= 0)
			{
				sum += x*x + y*y;
				count++;
			}
		}
	}
	cout <</*count<<endl<< sum<<endl<<*/(0.5*sum)/n<<endl;
	system("pause");
    return 0;
}

