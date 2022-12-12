// Kangmin Kim
// CS 2336
// Lab 35
#include <d_matrix.h>

using namespace std;

bool isIdentityMatrix(const matrix<int>& mat){
	int i,j;
	int count = 0;
	int decount = 0;
	int n = mat.rows();
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{	
			if(i == j && mat[i][j] == 1)
				count++;
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = n - 1; j >= 0; j--)
		{
			if(i != j && mat[i][j] == 0)
			decount++;
		}
	}
	
	if((n == count) && (n*(n-1) == decount))
		return true;
	else
		return false;
}