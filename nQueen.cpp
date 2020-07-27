#include<iostream>
using namespace std;


void print(int *a,int size)
{
	for (int i=0;i<size;i++)
	{
	cout<<a[i]<<endl;
	}
	cout<<"------------------"<<endl;
}

int place(int *a,int row,int col)
{
	for (int i=0;i<col-1;i++)
	{
		if (a[i]==col)
			return 0;
		if(abs(a[i]-col)==abs(i-row))
			return 0;	
	}
	return 1;
}


void queen(int *a,int start,int end){

	for (int i=0;i<end;i++)
	{
		if(place(a,start,i))
		{
			a[start]=i;
			if(start==end)
				print(a,end);
			else
				queen(a,start+1,end);	
	}
	}
}


	int main()
	{
	int a[4]={0};
	queen(a,0,3);	
	}