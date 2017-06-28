// Лабораторна робота №5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*class Hashtable
{
	int * head;//array of the heads
	int *next;//array of the & ont the next element
	int *keys;//array of the keys (could be another type)
	int head_amount;//amount of the heads
	int cnt = 1;//& for inputting next element
	Hashtable(int head_amount, int maxsize)
	{
		this->head_amount = head_amount;
		head = new int[head_amount];
		next = new int[maxsize + 1];
		keys = new int[maxsize + 1];
	}
	//hash-function(should be rewriting for another types
	int hash(int x)
	{
		return (x >> 15) ^ x;
	}
	int  index(int hash)
	{
		return fabs(hash %head_amount);
	}
	//function for checking table on the having element(x)
	bool contains(int x)
	{

	}
};*/
class iteam
{
private:
	int value;
	int key;
public:
	iteam()
	{

	}
	iteam(int key)
	{
		this->key = key;
	}
	int getkey()
	{
		return key;
	}
	int hetvalue()
	{
		return value;
	}
};
class Hashtable
{
private :
	iteam *table;
	int count;
	int size;
public:
	Hashtable(int size)
	{
		this->size = size;
		table = new iteam [size];
	}

};
int main()
{
    return 0;
}

