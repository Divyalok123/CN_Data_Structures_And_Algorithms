// Given a random integer array, push all the zeros that are present to end of the array. The respective order of other elements should remain same.
// Change in the input array itself. You don't need to return or print elements. Don't use extra array.

#include <iostream>
using namespace std;

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PushZeroesEnd(int arr[], int n)
{    
    int k = 0;
    int i = 0;
    while(i < n)
    {
        if(arr[k] != 0)
        {
            k++;
        }
        i++;
        if(arr[i] != 0) swap(&arr[i], &arr[k]);
    }
    
}


int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	PushZeroesEnd(input,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	
	return 0;

}
