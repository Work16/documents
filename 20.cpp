// 0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>
using namespace std;








bitset<11>  plu(bitset<10> a,bitset<10> b)
{
	bitset<11>result;
	for (int i = 0;i < 11;i++)
	{
		if (i < 10)
		{
			if (a[i] == 0 && b[i] == 0 && result[i] == 0)
				result[i] = 0;
			else if ((a[i] == 1 && b[i] == 0 && result[i] == 0) || (a[i] == 0 && b[i] == 1 && result[i] == 0)||(a[i]==0 && b[i]==0 && result[i]==1))
				result[i] = 1;
			else if ((a[i] == 1 && b[i] == 1 && result[i] == 0) || (a[i] == 0 && b[i] == 1 && result[i] == 1) || (a[i] == 1 && b[i] == 0 && result[i] == 1))
			{
				result[i] = 0;
				result[i+1] = 1;
			}
			else
			{
				result[i] = 1;
				result[i+1] = 1;
			}
		}
	}
	return result;
}
/*bitset<11> minus(bitset<10>a, bitset<10>b)
{
	bitset <11>result;
	for (int i = 0;i < 11;i++)
	{
		if (i < 10)
		{
			if ((a[i] == 0 && b[i] == 0 && result[i] == 0))
				result[i] = 0;
			else if (a[i] == 1 && b[i] == 0 && result[i] == 0)
				result[i] = 1;
			else if (a[i] == 0 && b[i] == 1 && result[i] == 0)
			{
				result[i] = 0;
				result[i + 1] = 1;
			}
			else if (a[i] == 1 && b[i] == 1 && result[i] == 0)
				result[i] = 0;
			//else if (a[])

		}
	}
}
/*bitset <11> minu(bitset<10>a, bitset<10>b)
{
	bitset <11>result;
	bitset<11>result2 = (bitset<11>)0;
	bitset<10> t = (bitset<10>)1;
	result2 = plu(a, t);
	for (int i = 0;i < 10;i++)
	{
		if (result2[i] == 0) result2[i] = 1;
		else if (result2[i] == 1)result2[i] = 0;
	/*	if (b[i] == 0) b[i] = 1;
		else if (b[i] == 1) b[i] = 0;
	/*}
//	int naumber = result2.to_ulong;
	bitset<10>result3 = (bitset<10>)result2.to_ulong();
	result = plu(result3, b);
//	bitset<11>result2 = (bitset<11>)0;
/*for (int i = 0;i < 11;i++)
		if (result[i] == 0)result[i] = 1;
		else if (result[i] == 1) result[i] = 0;
	for (int i = 0;i < 11;i++)
	{
			if (result[i] == 0 && t[i] == 0 && result2[i] == 0)
				result2[i] = 0;
			else if ((result[i] == 1 && t[i] == 0 && result2[i] == 0) || (result[i] == 0 && t[i] == 1 && result2[i] == 0) || (result[i] == 0 && t[i] == 0 && result2[i] == 1))
				result2[i] = 1;
			else if ((result[i] == 1 && t[i] == 1 && result2[i] == 0) || (result[i] == 0 && t[i] == 1 && result2[i] == 1) || (result[i] == 1 && t[i] == 0 && result2[i] == 1))
			{
				result2[i] = 0;
				result2[i + 1] = 1;
			}
			else
			{
				result2[i] = 1;
				result2[i + 1] = 1;
			}
	}

for (int i = 0;i < 11;i++)
			if (result[i] == 0)result[i] = 1;
			else if (result[i] == 1) result[i] = 0;
		
		return result;
}*/

bitset<11>minu(bitset<10>a, bitset<10>b,bool &flag)
{
	bitset<10>t = a;
	bitset<11>result = (bitset<11>)0;
/*	for (int i = 0;i < 10;i++)
		if (a[i] == 0)a[i] = 1;
		else a[i] = 0;*/
	if (a.to_ulong() > b.to_ulong())
		a = ~a;
	else
	{
		b = ~b;
		flag = true;
	}

		result = plu(a, b);
		for (int i = 0;i < 10;i++)
			if (result[i] == 0)result[i] = 1;
			else result[i] = 0;
		//result = ~result;
		//if (result[0]==0)
			/*if (b.to_ulong() > t.to_ulong())
			{
				for (int i = 0;i < b.t;i + o_ulong();i++)
					result = plu((bitset<10>)1, (bitset<10>)result.to_ulong());
				if (result[10] == 0)
					flag = true;
			}
			//if (flag) return ~result;*/
			return result;
}
bitset <11> mnoz(bitset<10>a, bitset<10>b)
{
	bitset<10>c = a;
	bool flag = false, fl = false;
	int count=0;
	if (b[0] == 1)fl = true;
	while (b!=(bitset<10>)0 && b!=(bitset<10>)1)
	{
		//b = b >> 1;
		//fl = false;
		bitset<11>r;
		/*for (int i = 0;i < 10;i++)
			a[i] = a[i++];
		a[10] = 0;*/
		a = a << 1;
		b = b >> 1;
		//b = b >> 1;
		//r = minu(b, (bitset<10>)2,flag);
		//b = (bitset<10>)r.to_ulong();
		//b = b >> 1;
		//int count = 0;
		count  ++;
		/*for (int i = 0;i < 9;i++)
			if (b[i] == 1)count++;
		if (count == 0 && (b[9] == 0 || b[9] == 1))
			fl = false;*/
	}
	//for (int i = 0;i < 10;i++)
		if (fl)
		{
			//int f = a.to_ulong();
			//bitset<11>k = minu(b, (bitset<10>)1,flag);
			bitset<11>f= plu(a,c);
			return f;
			//plu((bitset<10>)f.to_ulong(), a);
			//break;
		}
	return (bitset<11>)a.to_ulong();
}
bitset <11> del(bitset<10>a, bitset<10>b)
{
	bool flag = false, fl = true;
	while (b!=(bitset<10>)0 && b!=(bitset<10>)1)
	{
		//fl = false;
		//bitset<11>r;
		/*for (int i = 0;i < 10;i++)
		a[i] = a[i++];
		a[10] = 0;*/
		a = a >> 1;
		b = b >> 1;
	//	r = minu(b, (bitset<10>)2, flag);
		//b = (bitset<10>)r.to_ulong();
		/*int count = 0;
		count = 0;
		for (int i = 0;i < 9;i++)
			if (b[i] == 1)count++;
		if (count == 0 && (b[9] == 0 || b[9] == 1))
			fl = false;*/
	}
	return (bitset<11>)a.to_ulong();
}

int main()
{
	bool flag=false;
	int number = 2;
	bitset<10> a = (bitset<10>)31;
	bitset <10> b = (bitset<10>)4;
	bitset<11> result=(bitset<11>)0 ;
	//plu(a, b, result);
	result= plu(a, b);
	//a = plus(a, b);
	/*for (int i = 0;i <11;i++)
		cout << result[i];*/
	if (flag == true)
		cout << "-";
	cout  << a.to_ulong()<<"+" << b.to_ulong()<<"="<< result.to_ulong()<< endl;
	system("pause");
    return 0;
}

