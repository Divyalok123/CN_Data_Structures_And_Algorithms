// Given a random integer array A and an element x. You need to search this element x in the given array using linear search. Return the index of element in the input.
// Linear search means, we need to compare elements from the array A one by one with the element x, till we found the match or we reach the end of array. If match found, return its index, and if not return -1.
// Indexing in the array starts from 0.

#include <iostream>

// arr - input array
// n - size of array
// val - element to be searched

int linearSearch(int arr[], int n ,int val){
    int i = 0;
    while(i < n)
    {
        if(arr[i] == val)
        {
            return i;
        }
        i++;
    }
    return -1;
}

using namespace std;

int main() {
	
	int size,x;
	cin>>size;
	int *input=new int[1+size];
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cin>>x;

	cout<<linearSearch(input,size,x);
	
	
	
	
	return 0;
}

