// Given two random integer arrays of size m and n, print their intersection. That is, print all the elements that are present in both the given arrays.
// Input arrays can contain duplicate elements.

#include <iostream>
#include <algorithm>
using namespace std;

#include <climits>

void intersection(int input1[], int input2[], int size1, int size2) 
{    
    for(int i = 0; i < size1; i++)
    {        
        for(int j = 0; j < size2; j++)
        {
            if(input2[j] == input1[i])
            {
                cout << input2[j] << "\n";
                input2[j] = INT_MAX;
                break;
            }
        }
    }
}

int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}
