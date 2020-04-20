// Given a random integer array. Sort this array using insertion sort.

#include <iostream>
using namespace std;

// arr - input array
// n - size of array
void InsertionSort(int arr[], int n){
    for(int i = 1; i < n; i++)
    {
        int j = i-1;
        int val = arr[i];
        while(arr[j] > val && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}


int main() {
	
	int size;
	cin>>size;
	int *input=new int[1+size];
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	InsertionSort(input,size);

	for(int i=0;i<size;i++)
		cout << input[i]<<" ";
	
	return 0;
}
