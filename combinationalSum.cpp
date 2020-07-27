#include<iostream>
#include<vector>
#include<string>
#include <memory>
#include <iostream>
#include <vector>
using namespace std;



int result[100] = {0};

void print(int size){
	for (int i = 0; i<size; i++){
		cout << result[i];
	}
	cout << endl;
}



void printNumbers(int* arr, int sum, int index, int resultSize,int size){

	if (sum < 0)return;

	if (sum == 0){
		print(resultSize);
		return;
	}

	for (int i = index; i<size; i++)
	{
		result[resultSize] = arr[i];
		printNumbers(arr, sum - arr[i], i, resultSize + 1,size);
	}
}


int main()
{
	int arr[] = { 2, 4, 6, 8 };
	printNumbers(arr, 8, 0, 0 ,4);

	return 0;
}
