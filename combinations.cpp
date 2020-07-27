#include<iostream>
#include<windows.h>
#include<time.h>
#include<vector>
#include<list>
std::vector<int> list;
void print()
{
	if (list.empty())
		return;	
	for (auto number : list)
	{
		std::cout << number ;
	}
	std::cout << "\n";
}
void combinations(int *arr, int index,int size )
{
	if (index == size){
		print();
		return;
	}
	list.push_back(arr[index]);
	combinations(arr, index + 1,size);
	list.erase((list.end() - 1));
	combinations(arr, index + 1,size);
}




int main()
{
	int arr[] = { 1, 2, 3 , 4 };
	
	combinations(arr, 0 ,4);


	return 0;
}

