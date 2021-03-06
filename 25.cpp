// 25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <algorithm>
#include <array>
#include <string>
using namespace std;

string palindrome(const string& s) {
	if (s.size() == 0 || s.size() == 1) {
		return s;
	}
	if (s.front() == s.back()) {
		return s.front() + palindrome(s.substr(1, s.size() - 2)) + s.back();
	}
	array<string, 3> branches;
	branches[0] = palindrome(s.substr(1));
	branches[1] = palindrome(s.substr(0, s.size() - 1));
	branches[2] = palindrome(s.substr(1, s.size() - 2));

	return *std::max_element(branches.begin(), branches.end(), []
		(const string& a, const string& b) {
		return a.size() < b.size();
	});
}

int main()
{
	string target{ "12343271" };
	cout<< palindrome(target) << endl;
	system("pause");
	return 0;
}
