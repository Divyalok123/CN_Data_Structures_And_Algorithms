// Given an integer array, which is sorted (in increasing order) and has been rotated by some number k in clockwise direction. Find and return the k.

#include <iostream>
using namespace std;

// arr - input array
// n - size of array

int FindSortedArrayRotation(int arr[], int n)
{
    int small = arr[0];
    int key = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < small)
        {
            small = arr[i];
            key = i;
        }
    }
    return key;
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSortedArrayRotation(input,size);
	
	return 0;

}
