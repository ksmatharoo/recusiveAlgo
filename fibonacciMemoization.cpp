#include<iostream>
using namespace std;
int mem[100]={0};

int fastfib(int n){
	static int cnt;
	cout<<"fastfib call cnt"<< ++cnt<<endl;
	if (n==0 || n==1)
		return 1;
	if(mem[n]==0)
		return mem[n]=fastfib(n-1)+fastfib(n-2);
	else
		return mem[n];
}


// 

int fib(int n){
	static int cnt;
	cout<<"fib call cnt"<< ++cnt<<endl;
	if (n==0 || n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

int main(){
	cout<<fastfib(8)<<endl;
	cout<<fib(8);
	return 0;
} 