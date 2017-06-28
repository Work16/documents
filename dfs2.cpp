#include <stdafx.h>
#include <iostream>
using namespace std;

void  dfs2(int **&p, int n, int i,int j)
{
	p[i][j] = 0;
	for (int f = 0;f < n;f++)
		if (p[j][f] == 1)
			dfs2(p, n, j, f);
}