// 36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <iostream>
//using namespace std;
#include<iostream>
int find(int n, int k) {
	if (n <= (k + 1)) return (n - 1);
	//if (n <= 0) return 0;
	for (int i = 1;(i <= k);i++)
		if (!find(n - i, i + 1)) return i;
	//return 0;

}

int main()
{
	int n, k;
	std::cout << "enter n and k:";
	std::cin >> n >> k;
	std::cout << "result is: " << find(n, k) << '\n';
	/*n -= find(n, k);
	while (n>0)
	{
		std::cout << "enter k:";
		std::cin >> k;
		n -= k;
		std::cout << "result is: " << find(n, k) << '\n';
		n -= find(n, k);
		//k = find(n, k) + 1;
	}
	std::cout << "You won\n";*/
	system("pause");
	return 0;
}


/*int result(int n, int a)
{
	if (n == 2) return 1;
	else if ((n - a - 1 > 1))return 1;
	//else if ((n - a -1 )== 1) return  a + 1;
	else if ((n - a-1) ==1) return  a;
	else
		return result(n, a - 1);
}

int main()
{
	int n;
	cout << "Enter amount:\n";
	cin >> n;
	int i = 0;
	int a;
	while (n>0)
	{
		if (n <= 0)
			break;
		if (i == 0)
		{
			cout << "k=" << rand() % n << endl;
			cout << endl << result(n, rand()%n);
			n = n - result(n, rand()%n);
		}
		else
		{
			cout << endl << result(n, a);
			n = n - result(n, a);
		}
		cout << "\nEnter your way:\n";
		cin >> a;
		n = n - a;
		i++;
	}
	system("pause");
    return 0;
}*/

