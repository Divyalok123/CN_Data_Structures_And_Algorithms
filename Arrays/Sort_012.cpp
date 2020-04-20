// You are given an integer array containing only 0s, 1s and 2s. Write a solution to sort this array using one scan only.
// You need to change in the given array itself. So no need to return or print anything.

#include <iostream>
#include <algorithm>
using namespace std;

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int a[], int n)  {  
    int nz = 0;
    int nt = n-1;
    int i = 0;
    while(i <= nt)
    {
        if(a[i] == 0)
        {
            swap(&a[nz], &a[i]);
            i++;
            nz++;
        }
        else if(a[i] == 1)
        {
            i++;
        }
        else if(a[i] == 2)
        {
            swap(&a[nt], &a[i]);
            nt--;
        }
    }
}


int main() {

	int size_first;

	cin>>size_first;
	int *arr_first=new int[1+size_first];	
	
	for(int i=0;i<size_first;i++)
		cin>>arr_first[i];
	
	sort012(arr_first,size_first);
		
	for(int i=0;i<size_first;i++)
		cout<<arr_first[i]<<" ";	
	return 0;
}
