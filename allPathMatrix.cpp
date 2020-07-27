#include<iostream>
#include<time.h>
#include<vector>
#include<map>
using namespace std;
#define ROW 3
#define COL 4

int bin[3][4] = { 0,0,0,1,
				  0,1,0,0,
				  0,0,0,0 };

char spath[100] = { 0 };

void printstr(int size)
{
	int i = 0;
	for (int i = 0; i < size; i++)
		cout << spath[i] << " ";
	cout << endl;

}
bool IsSafe(int row, int col)
{
	if (bin[row][col] == 0)
		return true;
	else
		return false;
}
// print all possible path in matrix to go from left top to bottom righ
void gofromLTtoBR(int row, int col, int size, char s)
{
	if (row >= ROW || col >= COL || !IsSafe(row, col))
		return;
	if (row == (ROW - 1) && col == (COL - 1))
	{
		spath[size++] = s;
		printstr(size);
		return;
	}
	else
	{
		spath[size++] = s;
		gofromLTtoBR(row + 1, col, size, 'D');
		gofromLTtoBR(row, col + 1, size, 'R');
	}
}
#if 0
int main()
{
	gofromLTtoBR(0, 0, 0, 'S');
	return 0;
}
#endif




