// lablab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class HashEntry {
private:
	int key;
	int value;
public:
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}
};

const int TABLE_SIZE = 128;

class HashMap {
private:
	HashEntry **table;
public:
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}
	int hash_function(int world)
	{
		return world % TABLE_SIZE;
	}
	
	void get(int key) {
		int hash = hash_function(key);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = hash_function(hash+1);
		if (table[hash] == NULL)
			//return -1;
			cout << "Error\n";
		else
			cout << table[hash]->getValue() << endl;
			//return table[hash]->getValue();
			while (table[hash] != NULL && table[hash]->getKey() == key)
			{
				cout << table[hash]->getValue()<<endl;
				hash = hash_function(hash+1);
			}
	}

	void  put(int key, int value) {
		int hash = hash_function(key);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = hash_function(hash+1);
		/*if (table[hash] != NULL)
			delete table[hash];*/
		while (table[hash]!=NULL)
			hash = hash_function(hash+1);
		table[hash] = new HashEntry(key, value);
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}
};


int main()
{
	HashMap obj;
	obj.put(0, 58);
	obj.put(20,67);
	obj.put(20, 3);
	obj.put(526, 5);
	 obj.get(20);
	 cout << "************\n";
	 obj.get(526);
	 cout << "**************\n";
	 obj.get(0);
	system("pause");
    return 0;
}

