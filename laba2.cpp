// laba2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <unordered_set>
using namespace std;
const int siz = 200;
string k[siz][2];
//unordered_set< string> m;

struct MyHashFunction { // hashing functor
	size_t  operator() (string k) {
		// return a hash value you compute based on  k
		return size(k);
	}
};

struct MyEqualityDefinition { // equality functor
	bool operator() (string l, string r) {
		// return true if l and r are equal according to you
	}
};
struct s
{
	string key;
	string value;
};

typedef std::unordered_set<s, MyHashFunction, MyEqualityDefinition> m;
class HashMap
{
private:
	string key;
	string value;
	int koef;
public:
	//string k[siz][2];
	void  set()
	{
		for (int i = 0;i < siz;i++)
			for (int j = 0;i < 2;j++)
				k[i][j] = "-1";
		//return k;
	}
  size_t hash_function(string key)
	{
		return size(key);
	}
	//unordered_set<s> m;
	void add(s l)
	{
		/*if (k[hashfun(key)][1] == "0")
		{
			k[hashfun(key)][1] = value;
			k[hashfun(key)][2] = key;
		}
		else
		{
			int i = 0;
			while (k[hashfun(key) + i][1] == "0")
				i++;
			k[hashfun(key) + i][1] = value;
			k[hashfun(key) + i][2] = key;
		}
		//return k;*/
		int f = hashfun(key);
		int z = 0;
		auto t = m.begin();
		for (int j = 0;j < hashfun(key);j++)
			t++;
			m.insert(pair<string,string>(l.key,l.value),MyHashFunction());
	}
	void del(string key,string value)
	{
		/*if (k[hashfun(key)][2] == key)
		{
			k[hashfun(key)][1] = "0";
			k[hashfun(key)][2] = "0";
		}
		else
		{
			int i = 0;
			while (k[hashfun(key) + i][2] != key)
				i++;
			k[hashfun(key) + i][1] = "0";
			k[hashfun(key) + i][2] = "0";
		}*/
		m.erase(MyHashFunction());
	}
	int sear(string key)
	{
		/*if (k[hashfun(key)][2] == key)
			return k[hashfun(key)][1];
		else
		{
			int i = 0;
			while (i + hashfun(key) < siz && k[hashfun(key) + i][2] == key)
				i++;
			if (i + hashfun(key) < siz) return "Error";
			else return k[i + hashfun(key)][2];
		}
	}*/
		auto t = m.begin();
		int f = hashfun(key);
		for (int i = 0;i < hashfun(key);i++)
			t++;
		cout << (*t).first << " " << (*t).second.c_str();
		system("pause");
		return 0;
	}
};
	int main()
	{
		HashMap obj;
		string ky = "apple";
		string val = "Marina";
	//	obj.set();
		obj.add("a0", "b");
		obj.add(ky, val);
		//obj.del(ky);
	//	string result = obj.sear(ky);
			//cout << result.c_str() << endl;
		system("pause");
		return 0;
	}
