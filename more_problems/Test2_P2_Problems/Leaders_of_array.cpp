// Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].
// Print all the leader elements separated by space and in the same order they are present in the input array.


#include<iostream>
#include<climits>
using namespace std;

void Leaders(int* arr,int size)
{
    
	for (int i = 0; i < size; i++) 
    { 
        int j; 
        for (j = i+1; j < size; j++) 
        { 
            if (arr[i] < arr[j]) 
                break; 
        }     
        if (j == size) 
            cout << arr[i] << " "; 
  }
}


int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
