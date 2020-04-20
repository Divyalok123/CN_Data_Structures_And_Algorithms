// Given a random integer array A and a number x. Find and print the pair of elements in the array which sum to x.
// Array A can contain duplicate elements.
// While printing a pair, print the smaller element first.
// That is, if a valid pair is (6, 5) print "5 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.

#include <iostream>
using namespace std;

int min(int a, int b)
{
    if(a <= b) return a;
    return b;
}

int max(int a, int b)
{
    if(a >= b) return a;
    return b;
}

void pairSum(int arr[], int size, int x) {
    for(int i = 0; i < size; i++)
    {
        int val = arr[i];
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] + val == x)
            {
                cout << min(arr[j], val) << " ";
                cout << max(arr[j], val) << "\n";
            }
        }
    }
}


int main() {

	int size;
	int x;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;
	pairSum(input,size,x);
		
	return 0;
}
