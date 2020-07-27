#include<iostream>
#include<time.h>
#include<vector>
#include<map>
using namespace std;

int notes[100] = { 0 };
void printNotes(int end)
{
	for (int i = 0; i < end; i++)
	{
		cout << notes[i] << " ";
	}
	cout << endl;
}

void all_curency_combinations(int *a, int start, int end, int sum, int level)
{
	if (sum == 0)
	{
		printNotes(level);
		return;
	}
	if (sum < 0)
		return;
	else
	{
		for (int i = start; i < end; i++)
		{
			notes[level] = a[i];
			all_curency_combinations(a, i, end, (sum - a[i]), level + 1);
		}
	}
}

#if 0
int main()
{
	int notes[] = { 10, 20, 50 };
	all_curency_combinations(notes, 0, (sizeof(notes) / sizeof(int)), 50, 0);

	return 0;
}
#endif