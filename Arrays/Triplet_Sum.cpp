// Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
// While printing a triplet, print the smallest element first.
// That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.

#include <iostream>
using namespace std;

int min(int a, int b, int c)
{
    if(a <= b && a <= c) return a;
    else if(b <= c && b <= a) return b;
    return c;
}

int max(int a, int b, int c)
{
    if(a >= b && a >= c) return a;
    else if(b >= c && b >= a) return b;
    return c;
}


void FindTriplet(int arr[], int size, int x) {
    int val1, val2, val3;
    for(int i = 0; i<size; i++)
    {
        val1 = arr[i];
        for(int j = i+1; j<size; j++)
        {
            val2 = arr[j];
            for(int k = j+1; k < size; k++)
            {
                val3 = arr[k];
                if(val1 + val2 + val3 == x)
                {
                    cout << min(val1, val2, val3) << " ";
                    cout << x - min(val1, val2, val3) - max(val1, val2, val3) << " ";
                    cout << max(val1, val2, val3) << "\n";
                    
                }
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

	FindTriplet(input,size,x);
		
	return 0;
}

