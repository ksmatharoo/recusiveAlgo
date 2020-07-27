#include<iostream>
#include<time.h>
#include<vector>
#include<map>
using namespace std;
///// sudoko solver /////////////////
#define s_r 9
#define s_c 9

void printsudo(int mat[s_r][s_c])
{
	for (int i = 0; i < s_r; i++)
	{
		for (int j = 0; j < s_c; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

bool checkin3x3box(int m[s_r][s_c], int row, int col, int element)
{
	int xstart = 0;
	int ystart = 0;

	//fisrt vertical 3 boxs
	if (row >= 0 && row <= 2 && col >= 0 && col <= 2)
	{
		xstart = 0;
		ystart = 0;
	}
	else if (row >= 3 && row <= 5 && col >= 0 && col <= 2)
	{
		xstart = 3;
		ystart = 0;
	}
	else if (row >= 6 && row <= 8 && col >= 0 && col <= 2)
	{
		xstart = 6;
		ystart = 0;
	}

	//second vertical 3 boxs
	if (row >= 0 && row <= 2 && col >= 3 && col <= 5)
	{
		xstart = 0;
		ystart = 3;
	}
	else if (row >= 3 && row <= 5 && col >= 3 && col <= 5)
	{
		xstart = 3;
		ystart = 3;
	}
	else if (row >= 6 && row <= 8 && col >= 3 && col <= 5)
	{
		xstart = 6;
		ystart = 3;
	}
	//third vertical 3 boxs
	if (row >= 0 && row <= 2 && col >= 6 && col <= 8)
	{
		xstart = 0;
		ystart = 6;
	}
	else if (row >= 3 && row <= 5 && col >= 6 && col <= 8)
	{
		xstart = 3;
		ystart = 6;
	}
	else if (row >= 6 && row <= 8 && col >= 6 && col <= 8)
	{
		xstart = 6;
		ystart = 6;
	}

	for (int i = xstart; i < (xstart + 3); i++)
	{
		for (int j = ystart; j < (ystart + 3); j++)
		{
			if (m[i][j] == element)
				return false;
		}
	}
	return true;
}

bool IsSafeMove(int m[s_r][s_c], int row, int col, int element)
{
	for (int i = 0; i < s_r; i++)
	{
		if (m[i][col] == element)
			return false;
	}
	for (int j = 0; j < s_c; j++)
	{
		if (m[row][j] == element)
			return false;
	}
	return checkin3x3box(m, row, col, element);
	return true;
}

void fillSudoko(int mat[s_r][s_c], int row, int col)
{
	if (row == 0 && col == s_c)
	{
		printsudo(mat);
		cout << "=======================================================" << endl;
		return;
	}
	if (mat[row][col] != 0)
	{
		if (row >= s_r - 1)
		{
			fillSudoko(mat, 0, col + 1);
		}
		else
		{
			fillSudoko(mat, row + 1, col);
		}
		return;
	}
	for (int i = 1; i < (s_c + 1); i++)
	{
		if (IsSafeMove(mat, row, col, i))
		{
			mat[row][col] = i;

			if (row >= s_r - 1)
			{
				fillSudoko(mat, 0, col + 1);
			}
			else
			{
				fillSudoko(mat, row + 1, col);
			}
			mat[row][col] = 0;
		}
	}
}


#if 0
int main()
{
	int sudoko[s_r][s_c] =
	{
	0, 5, 3, 0, 0, 0, 0, 1, 0,
	7, 0, 0, 0, 0, 1, 0, 0, 4,
	0, 0, 0, 4, 2, 0, 9, 0, 5,
	0, 0, 0, 1, 0, 0, 0, 0, 3,
	0, 8, 0, 2, 0, 7, 0, 4, 0,
	2, 0, 0, 0, 0, 6, 0, 0, 0,
	8, 0, 9, 0, 1, 5, 0, 0, 0,
	3, 0, 0, 9, 0, 0, 0, 0, 1,
	0, 6, 0, 0, 0, 0, 2, 9, 0
	};
	fillSudoko(sudoko, 0, 0);

	return 0;
}

#endif




