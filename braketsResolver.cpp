#include<iostream>
#include<time.h>
#include<vector>
#include<map>
using namespace std;

char brackets[100] = { 0 };

bool Safe(int l, int r, int c)
{
	if (l < 0 || r < 0)
		return false;
	if ((c - l) < (c - r))
		return false;
	else
		return true;
}

void printbrackets(int size)
{
	for (int i = 0; i < 6; i++)
		cout << brackets[i] << " ";
	cout << endl;
}

void printbrackets(int left, int right, int size, int cnt)
{
	if (left == 0 && right == 0)
	{
		printbrackets(size);
		return;
	}

	if (!Safe(left, right, cnt))
		return;

	brackets[size] = '(';
	printbrackets(left - 1, right, size + 1, cnt);
	brackets[size] = ')';
	printbrackets(left, right - 1, size + 1, cnt);
}

#if 0
int main() {
	printbrackets(3, 3, 0, 3);
	return 0;
}
#endif