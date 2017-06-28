// laba1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<iomanip>
#include <vector>
using namespace std;
vector <double>frank(double**, int, vector<double>, vector<double>);
double ** symplecs(double **, int);
int min(double **, int);
double ** rewriting(double**, int, int, int);
double lam_function(int, vector<double>, vector<double>, vector<double>);

bool test_min(double**matrix,int n)
{
	if (min(matrix, n) != 0)
	{
		cout << "Problem with min function\n";
		system("pause");
		return 0;
	}
	return 1;
}
bool test_symplecs(double **matrix,int n)
{
	matrix[2][0] = -2;matrix[2][1] = -4;
	matrix = symplecs(matrix, n);
	if (round(matrix[0][2]*10)/10!=6.4 ||round(matrix[1][2]*10)/10!= 0.8||matrix[2][2]!=16)
	{
		cout << "Problem with symplecs function\n";
			system("pause");
			return 0;
	}
	return 1;
}
bool test_frank(double **matrix, int n, vector<double> fun, vector<double>point)
{
	point = frank(matrix, n, fun, point);
	if (round(point[0]*100)/100 != 2.18 || round(point[1]*100)/100 != 0.27)
	{
		cout << "Problem with frank function\n";
		system("pause");
		return 0;
	}
	return 1;
}
bool test_rewriting(double **matrix, int min_i, int min_j, int n)
{
	matrix = rewriting(matrix, 1, 1, n);
	if (matrix[0][0] != 5 || matrix[0][1] != 0 || matrix[0][2] != 32||
		matrix[1][0] != -2 || matrix[1][1] != 1 || matrix[1][2] != -12 ||
		round(-matrix[2][0]*100)/100 != 13.82 ||matrix[2][1] != 0 || round(-matrix[2][2]*100)/100 != 44.73)
	{
		cout << "Problem with rewriting function\n";
		system("pause");
		return 0;
	}
	return 1;
}
bool test_lam_function(int n, vector<double>fun, vector<double>point, vector<double>z)
{
	if (round(lam_function( n,fun,point,z)*100)/100 != -0.17)
	{
		cout << "Problem with lam_function!\n";
		system("pause");
		return 0;
	}
	return 1;
}
bool test()
{
	 int n = 2;
	double **matrix=new double *[n+1];
	for (int i = 0;i < n+1;i++)
		matrix[i] = new double[n+1];
	matrix[0][0] = 1;matrix[0][1] = 2;matrix[0][2] = 8;
	matrix[1][0] = 2;matrix[1][1] = -1;matrix[1][2] = 12;
	matrix[2][0] = 0;	matrix[2][1] = 0;matrix[2][2] = 0;
	if (!test_min(matrix, n)) return 0;
	if (!test_symplecs(matrix, n))return 0;
	vector <double>point;
	for (int i = 0;i < n;i++)
		point.push_back(0);
	vector<double>fun(n+n);
	fun[0] = 2;fun[1] = 4;fun[2] = -1;fun[3] = -2;
	if (!test_frank(matrix, n, fun, point))return 0;
	if (!test_rewriting(matrix, 1, 1, n))return 0;
	vector<double>z;
	z.push_back(6.4);
	z.push_back(0.8);
	if (!test_lam_function(n, fun, point, z))return 0;
	return 1;
}

//function for finding solve column
int min(double ** matrix, int n)
{
	double i =5646;
	int z = 0;
	for (int j = 0;j< n;j++)
		if (matrix[n][j]<i && matrix[n][j]<0)
		{
			z = j;
			i = matrix[n][j];
		}
	return z;
}
double eps = 0.001;

 double pre = 0;
 //function for rewriting symplex table
 double ** rewriting(double **matrix ,int min_i,int min_j,int n)
 {
	 double **copy = new double *[n + 1];
	 for (int i = 0;i < n + 1;i++)
		 copy[i] = new double[n + 1];
	 for (int i = 0;i < n + 1;i++)
		 for (int j = 0;j < n + 1;j++)
		 {
			 if (i == n && j == n)
				 copy[i][j] = 0;
			 if (i == min_i)
			 {
				 if (j == min_j)
					 copy[i][j] = 1 ;
				 else
					 copy[i][j] = matrix[i][j] / matrix[min_i][min_j];
			 }
			 else
			 {
				 if (j == min_j)
					 copy[i][j] = 0;
				 else
					 copy[i][j] = matrix[i][j] - (matrix[i][min_j] * matrix[min_i][j]) / matrix[min_i][min_j];
			 }
		 }
	 return copy;
 }
 //realization of the table simplex algoriphm
double ** symplecs(double **matrix, int n)
{
	static int f = 0;f++;
	int min_j = min(matrix, n );
	vector<double> min(n);
	for (int i = 0;i < n;i++)
		min[i]=matrix[i][n] / matrix[i][min_j];
	double  z = 1894789;
	int min_i = 0;
	for (int i = 0;i < n;i++)
		if (min[i] < z && matrix[i][n]>0)
		{
			min_i = i;
			z = min[i];
		}
	if (z == 1894789)
	{
		cout << "–ешений не существует!\n";
		system("pause");
     	}
	min.clear();
	matrix = rewriting(matrix, min_i, min_j,n);
	int count = 0;
	for (int i = 0;i < n ;i++)
	{
		if (matrix[n][i] < 0)
			count++;
	}
	//min.erase(min.begin(), size(min));
	
	if (count == 0)return matrix;
	else  return  symplecs(matrix, n);
}
//function for counting step of the point int Frank-Wolf method 
double lam_function(int n,vector<double>fun,vector<double>point,vector<double>z)
{
	vector<double> L;
	for (int i = 0;i < n;i++)
	{
		L.push_back(point[i]);
		L.push_back(z[i] - point[i]);
	}
	vector<double>res;
	int j = 0;
	for (int i = 0;i < n;i++)
	{
		res.push_back(L[j + 1]);
		j += 2;
	}
	j = 0;
	for (int i = n;i < 2 * n;i++)
	{
		res.push_back(fun[i] * L[j] * L[j]);
		res.push_back(2 * fun[i] * L[j] * L[j + 1]);
		res.push_back(fun[i] * L[j + 1] * L[j + 1]);
		j += 2;
	}
	double count1 = 0, count2 = 0;
	j = 0;
	for (int i = 0;i < n;i++)
		count1 += res[i];
	for (int i = n;i < size(res);i++)
	{
		if (j == 3)
			j = 0;
		//	j++;
		if (j == 1)
			count1 += res[i];
		if (j == 2)
			count2 += res[i];
		j++;
	}
	res.clear();
	z.clear();
	return count1 / count2;
}
//realization of the Frank-Wolf method
vector<double>frank(double **matrix, int n, vector<double> fun,vector<double>point)
{
	vector <double>grad;
	for (int i = 0;i < n;i++)
		grad.push_back(fun[i] + 2 * fun[2 * i]*point[i]);
	vector<double>newpoint(n);
	vector<double>z(n);
	for (int j = 0;j < n;j++)
		matrix[n][j] = -grad[j];
	matrix[n][n] = 0;
	double **copy = new double *[n + 1];
	for (int i = 0;i < n + 1;i++)
		copy[i] = new double[n + 1];
	for (int i = 0;i < n + 1;i++)
		for (int j = 0;j < n + 1;j++)
			copy[i][j] = matrix[i][j];
	copy = symplecs(matrix, n);
	for (int i = 0;i < n;i++)
		z[i]=copy[i][n];
	double lam = lam_function(n, fun, point, z);
	for (int i = 0;i < n;i++)
		newpoint[i]=point[i] + fabs(lam)*(z[i] - point[i]);
	double now = 0;
	for (int i = 0;i < n;i++)
		now += fun[i] * newpoint[i];
	int j = 0;
	for (int i = n;i < 2 * n;i++ && j++)
	now+=fun[ i] * newpoint[j] * newpoint[j];
	if (fabs(now) -fabs( pre) < eps)
	{
		pre = now;
		return newpoint;
	}
	else
	{
		pre = now;
		return frank(matrix, n, fun, newpoint);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	if (test())
	{
	cout << "¬ведите количество переменных:\n";
	int n;
	cin >> n;
	vector <double> function;
	for (int i = 0;i < 2 * n;i++)
		function.push_back(0);
	for (int i = 0;i < n;i++)
	{
		cout << "¬ведите коэфицыент " << i + 1 << " переменной:\n";
		cin >> function[i];
	}
	int j = 0;
	for (int i = n;i < 2 * n;i++)
	{
		cout << "¬ведите значение коефицыент при квадрате " << j + 1 << " переменной:\n";
		cin >> function[i];
		j++;
	}
	//cout << "¬ведите значение свободного члена:\n";
	//cin >> function[n];
	system("cls");
	double **matrix = new double *[n + 1];
	for (int i = 0;i < n + 1;i++)
		matrix[i] = new  double[n + 1];
	for (int i = 0;i < n + 1;i++)
		for (int j = 0;j < n;j++)
			matrix[i][j] = 0;
	cout << "¬ведите матрицу ограничений:\n";
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n + 1;j++)
			cin >> matrix[i][j];
	vector<double>point;
	for (int i = 0;i < n;i++)
		point.push_back(0);
	vector<double>result = frank(matrix, n, function, point);
	system("cls");
	for (int i = 0;i <size(result);i++)
		cout << result[i] << " ";
	cout << endl << pre << endl;
}
	system("pause");
    return 0;
}

