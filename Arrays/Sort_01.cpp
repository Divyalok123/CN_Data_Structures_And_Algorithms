// You are given an integer array A that contains only integers 0 and 1. Write a function to sort this array. Find a solution which scans the array only once. Don't use extra array.
// You need to change in the given array itself. So no need to return or print anything.

#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SortZeroesAndOne(int arr[], int n)
{
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		while (arr[i] == 0)
        {
            i++;
        }
        while(arr[j] == 1)
        {
            j--;
        }
        swap(&arr[i], &arr[j]);
	}
    swap(&arr[i], &arr[j]);
}


int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	SortZeroesAndOne(input,size);
		
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";	
	return 0;
}

