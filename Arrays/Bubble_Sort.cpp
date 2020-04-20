// Given a random integer array. Sort this array using bubble sort.

#include <iostream>
using namespace std;

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// n - size of array
void BubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


int main(){

	int size;
	cin>>size;

	int * input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	BubbleSort(input,size);
	
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";	

}	
