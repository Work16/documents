// 32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;





int main()
{
	cout << "Enter your string:\n";
	string str1,str2;
      cin>>str1;
	  cout << "Enter your  second string:\n";
	  cin >> str2;
	  vector <char> s1;
	  vector<char>s2;
	  vector<int > p1;
	  vector<int>p2;
	  vector<char>res1;
	  vector<int>res2;
	  int count = 0;
	  for (int i = 0;i < size(str1);i++)
	  {
		  count = 0;
		  for (int j = 0;j < size(s1);j++)
			  if (s1[j] == str1[i])
			  {
				  count++;
				  p1[j]++;
			  }
		  if (count == 0)
		  {
			  s1.push_back(str1[i]);
			  p1.push_back(1);
		  }
	  }
	  for (int i = 0;i < size(str2);i++)
	  {
		  count = 0;
		  for (int j = 0;j < size(s2);j++)
			  if (s2[j] == str2[i])
			  {
				  count++;
				  p2[j]++;
			  }
		  if (count == 0)
		  {
			  s2.push_back(str2[i]);
			  p2.push_back(1);
		  }
	  }
	  for (int i = 0;i < size(s1);i++)
	  {
		  for (int j = 0;j < size(s2);j++)
		  {
			  if (s1[i] == s2[j])
			  {
				  res1.push_back(s1[i]);
				  if (p1[i] > p2[j])
					  res2.push_back(p2[j]);
				  else
					  res2.push_back(p1[i]);
			  }
		  }
	  }
	  cout << endl << endl << endl;
	  for (int i = 0;i < size(res1);i++)
	  {
		  for (int j = 0;j <res2[i];j++)
			  cout << res1[i];
	  }
	  cout << endl;
	system("pause");
    return 0;
}

