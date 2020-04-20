// Given a random integer array of size n, find and return the second largest element present in the array.
// If n <= 1 or all elements are same in the array, return -2147483648 i.e. -2^31.

#include <iostream>
using namespace std;

#include<climits>

int largest(int arr[], int n)
{
    int max = 0;
    for(int i = 1; i< n; i++)
    {
        if(arr[i] > arr[max])
        {
            max = i;
        }
    }
    return arr[max];
}
int FindSecondLargest(int arr[], int n)
{
    int val;
    val = largest(arr, n);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == val)
        {
            arr[i] = INT_MIN;
        }
    }
    val = largest(arr, n);
    return val;
     
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSecondLargest(input,size);
	
	return 0;

}