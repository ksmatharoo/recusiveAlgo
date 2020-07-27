#include <stdio.h>
#include "iostream"

using namespace std;
#define MAX 4

int sum(int m[][MAX],int x,int y,int n)
{
	int s = 0;
	int endx = x + n;
	int endy = y + n;
	for(int i=x;i<endx;i++)
	{
		for(int j=y;j<endy;j++)
		{
			s += m[i][j];
		}	
	}
	return s;
}


int g_max=0;
int g_functioncalls=0;


void subsum(int mat[][MAX],int startx,int starty,int dimesion)
{
	g_functioncalls++;

	if(startx  + dimesion > MAX )
		return;

	if(starty  + dimesion > MAX )
		return;


	if((startx == 0 && starty == 0) && ( MAX==dimesion))
	{
		int s = sum(mat,startx,starty,dimesion);
		if(s > g_max)
			g_max = s;

		return;
	}
	else
	{
		int s = sum(mat,startx,starty,dimesion);

		if(s > g_max)
			g_max = s;

		if(startx + 1  + dimesion <= MAX )
			subsum(mat,startx + 1,starty,dimesion);		
		else if(starty +1 + dimesion <= MAX)
			subsum(mat,0,starty+1,dimesion);
	}

}

int main()
{
	int mat[MAX][MAX] =
	{ 
		1,2,-1,4,
		-8,-3,4,2,
		3,8,10,-8,
		-4,-1,1,7
	};


	for(int i=1;i<=MAX;i++)
		subsum(mat,0,0,i);

	cout<<g_max<<endl;
	cout<<g_functioncalls<<endl;
	return 0;

}