#include<iostream>
#include<string>
#include<map>
#include<climits>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <time.h>
using namespace std;

#define N 4

void print(int b[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << b[i][j] << " ";

		cout << endl;
	}
	cout << "====================" << endl;
}


bool IsSafe(int b[N][N], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (b[i][col] == 1)
			return false;
	}
	for (int i = 0; i < col; i++)
	{
		if (b[row][i] == 1)
			return false;
	}
	for (int i = row, j = col; i >= 0, j >= 0; i--, j--)
	{
		if (b[i][j] == 1)
			return false;
	}
	for (int i = row, j = col; i < N, j >= 0; i++, j--)
	{
		if (b[i][j] == 1)
			return false;
	}
	return true;
}


bool Nq(int b[N][N], int col)
{

	if (col == N)
	{
		print(b);
		return true;
	}

	for (int row = 0; row < N; row++)
	{
		if (IsSafe(b, row, col))
		{
			b[row][col] = 1;

			bool ret = Nq(b, col + 1);
			if (ret)
			{

			}
			//return true;

			b[row][col] = 0;
		}
	}
	return false;
}



int main()
{

	int b[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			b[i][j] = 0;
	}

	bool n = Nq(b, 0);

	return 0;


}
