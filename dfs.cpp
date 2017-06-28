#include <stdafx.h>
#include <iostream>
using namespace std;

bool  dfs(int ** matrix_include, int n,int i,int j,int k,int z,int count)
{
	if (i == k && j == z)
		return false;
		if(matrix_include[i][j]==0)
		return true;
		if (k>=0 && z>=0)
			if (matrix_include[k][z] == 0)
				return true;
		if (!count)
		{
				for (int p = 0;p < n;p++)
					if (matrix_include[j][p] == 1)
						dfs(matrix_include, n, i, j, j, p, count+1);
		}
		else
		{
				for (int p = 0;p < n;p++)
					if (matrix_include[z][p] == 1)
						dfs(matrix_include, n, i, j, z, p, count+1);
		}
	return true;
}