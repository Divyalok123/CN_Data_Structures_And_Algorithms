// Given a sorted integer array (in ascending order) and an element x. You need to search this element x in the given input array using binary search. Return the index of element in the input.

#include <iostream>
using namespace std;

// arr - input array
// n - size of array
// val - element to be searched
int BinarySearch(int arr[], int n, int val){	
    int l = 0;
    int h = n-1;
    while(l <= h)
    {
        int mid = (l+h)/2;
        if(arr[mid] == val)
        {
            return mid;
        }
        else if(arr[mid] < val) 
            l = mid+1;
        else 
            h = mid-1;
    }
    return -1;
}


int main() {
	
	int size,val;
	cin>>size;
	int *input=new int[1+size];
	
	for(int i=0;i<size;i++)
		cin>>input[i];

	cin>>val;
	cout<<BinarySearch(input,size,val);
	return 0;
}

