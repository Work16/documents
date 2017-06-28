// Лабораторна робота №1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;




//functions for simplex method 

//function for table rewritng 
/*double ** rewriting(double **table, int size1, int size2,int solution_i,int solution_j)
{
	double  **copy = new double *[size1];
	for (int i = 0;i < size1;i++)
		copy[i] =  new double [size2];
	for (int i = 0;i < size1;i++)
		for (int j = 0;j < size2;j++)
		{
			if (i == solution_i)
			{
				if (j == solution_j)
				copy[i][j] = 1/table[solution_i][solution_j];
				else
					copy[i][j] = table[i][j] / table[solution_i][solution_j];
			}
			else if (j == solution_j)
				copy[i][j] = (-1)*table[i][j] / table[solution_i][solution_j];
			else
				copy[i][j] = table[i][j] - (table[i][solution_j] * table[solution_i][j]) / table[solution_i][solution_j];
	}
	return copy;
}
// function for finding index of the minimal element int the array
int min_index(double *aray,int size)
{
	double  j = INT_MAX;
	int j_index = 0;
	for (int i = 0;i < size;i++)
		if (j>aray[i])
		{
			j = aray[i];
			j_index = i;
		}
	return j_index;
}

//main function in the simplex metod
static int f = 0;
double **simplex( double **table,int size1,int size2)
{
	f++;
	int  solution_j = min_index(table[size1-1],size2-1);
	double*correlation=new double(size1);
	for (int i = 0;i <size1;i++)
	{
		correlation[i] = table[i][size2-1] / table[i][solution_j];
	}
	int solution_i = min_index(correlation,size1-1);
	table = rewriting(table, size1, size2, solution_i, solution_j);
	for (int i = 0;i < size2-1;i++)
		if (table[size1-1][i] < 0)
			return simplex(table, size1, size2);
	return table;*/
//}
//------------------------------------------------------------------------------------------
//the main method
//function for table rewritng 
/*double ** rewriting(double **table, int size1, int size2, int solution_i, int solution_j)
{
	double  **copy = new double *[size1];
	for (int i = 0;i < size1;i++)
		copy[i] = new double[size2];
	for (int i = 0;i < size1;i++)
		for (int j = 0;j < size2;j++)
		{
			if (i == solution_i)
			{
				///	if (j == solution_j)
						//copy[i][j] = pow(table[solution_i][solution_j], -1);
					//else
				copy[i][j] = table[i][j] / table[solution_i][solution_j];
			}
			else if (j == solution_j)
				copy[i][j] = 0;
				//(-1)*table[i][j] / table[solution_i][solution_j];
			else
				copy[i][j] = table[i][j] - (table[i][solution_j] * table[solution_i][j]) / table[solution_i][solution_j];
		}
	return copy;
}
// function for finding index of the minimal element int the array
int min_index(double *aray, int size)
{
	double  j = INT_MAX;
	int j_index = -1;
	for (int i = 0;i < size;i++)
		if (aray[i]!=0 && j>aray[i])
		{
			j = aray[i];
			j_index = i;
		}
	return j_index;
}
int max(double *aray, int size)
{
	double h = -1;
	int h_index = -1;
	for (int i = 0;i < size;i++)
	{
		if (aray[i]<0&&fabs(aray[i]) > h)
		{
			h = fabs(aray[i]);
			h_index = i;
		}
	}
	return h_index;
}
//main function in the simplex metod
static int f = 0;
double **simplex(double **table, int size1, int size2)
{
	f++;
	int  solution_j = max(table[size1 - 1], size2 - 1);
	if (solution_j == -1)
		return table;
	double*correlation = new double(size1-1);
	for (int i = 0;i <size1-1;i++)
	{
		if (table[i][size2 - 1] <= 0)
			correlation [i]= 0;
		else
		correlation[i] = fabs(table[i][size2 - 1] / table[i][solution_j]);
	}
	int solution_i = min_index(correlation, size1 - 1);
	if (solution_i==-1)
	{
		cout << "Problem with i\n";
		system("pause");
	}
	table = rewriting(table, size1, size2, solution_i, solution_j);
	for (int i = 0;i < size2 - 1;i++)
		if (table[size1 - 1][i] > 0)
			return simplex(table, size1, size2);
	return table;
}*/
//--------------------------------------------------------------------------------------------

bool check(double **aray, int size1, int size2)
{
	int k = 0;
	for (int i = 0;i < size1;i++)
		if(aray[i][size2-1]<0)
			k++;
	if (k > 0)return 1;
	else return 0;
}
int max_i_index(double **aray, int size1, int size2)
{
	double k = -1;
	int k_index = 0;
	for (int i = 0;i < size1;i++)
		if (aray[i][size2 - 1]<0 && fabs(aray[i][size2 - 1])>k)
		{
			k = aray[i][size2 - 1];
			k_index = i;
		}
	return k_index;
}

int max_j_index(double **aray, int solution_i, int size2)
{
	double k = -1;
	int k_index = 0;
	for (int i = 0;i < size2;i++)
		if (aray[solution_i][i]<0 && fabs(aray[solution_i][i])>k)
		{
			k = aray[solution_i][i];
			k_index = i;
		}
	return k_index;
}

int min_index(double *aray, int size)
{
	int k_index = -1;
	double k = INT_MAX;
	for (int i = 0;i < size;i++)
		if (i!=0)
		if (aray[i] != -INT_MAX && aray[i] < k)
		{
			k = aray[i];
			k_index = i;
		}
	return k_index;
}
double **rewtitng(double **aray, int size1, int size2, int solution_i, int solution_j)
{
	double **copy = new double *[size1];
	for (int i = 0;i < size1;i++)
		copy[i] = new double[size2];
	for (int i = 0;i < size1;i++)
		for (int j = 0;j < size2;j++)
		{
			if (i == solution_i)
			{
				if (j == solution_j)
					copy[i][j] = 1 / aray[i][j];
				else
					copy[i][j] = aray[i][j] / aray[solution_i][solution_j];
			}
			else if (j == solution_j)
			{
				copy[i][j] = (-1)*aray[i][j] / aray[solution_i][solution_j];
			}
			else {
				copy[i][j] = aray[i][j] - (aray[solution_i][j] * aray[i][solution_j]) / aray[solution_i][solution_j];
			}
		}
	return copy;
}
double **symplecs(double**table, int size1, int size2)
{
	while  (check(table, size1, size2))
	{
		int solution_i = max_i_index(table, size1, size2);
		int solution_j= max_j_index(table, solution_i, size2);
		if (solution_i == -1)
		{
			cout << "It is imposible task!!!\n";
			system("pause");
			return 0;
		}
		table = rewtitng(table, size1, size2, solution_i, solution_j);
	}
	for (int i = 0;i < size2-1;i++)
		if (table[0][i] < 0)
		{
			int solution_j = max_j_index(table, 0, size2-1);
			double *help = new double [size1];
			for (int i = 0;i < size1;i++)
			{
				if (table[i][size2 - 1] < 0 )
					help[i] = -INT_MAX;
				else
					help[i] = table[i][size2 - 1] / table[i][solution_j];
          }
			int solution_i = min_index(help, size1);

			table = rewtitng(table, size1, size2, solution_i, solution_j);
           i = 0;
		}
	return table;
}



int main()
{
	int n = 2;
	double** table=new double *[n+1];
	for (int i = 0;i < n +1;i++)
		table[i] = new double[n + 1];
	for (int i = 0;i < n + 1;i++)
		for (int j = 0;j <  n+1;j++)
			cin >> table[i][j];
	system("cls");
	table = symplecs(table, n + 1, n + 1);
	//cout << f << endl;
	for (int i = 0;i < n +1;i++)
		cout << table[i][n] << " ";
	cout << endl;
	system("pause");
    return 0;
}

