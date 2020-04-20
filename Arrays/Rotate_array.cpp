// Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
// Change in the input array itself. You don't need to return or print elements.

#include <iostream>
using namespace std;

void r(int arr[], int size)
{
    int val = arr[0];
    for(int i = 0; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[size-1] = val;
}

void Rotate(int arr[], int d, int size) {
    for(int j = 0; j < d; j++)
    {
        r(arr, size);
    }
    
}	


int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}
