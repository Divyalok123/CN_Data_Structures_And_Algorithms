// Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.
// Assume, duplicate number is always present in the array.

#include <iostream>
using namespace std;

// arr - input array
// size - size of array

int DuplicateNumber(int arr[], int size){
    for(int i = 0; i<size; i++)
    {
        int val = arr[i];
        int count = 0;
        for(int j = 0; j < size; j++)
        {
            if(arr[j] == val)
            {
                count++;
            }
        }
        if(count == 2)
        {
            return arr[i];
        }
    }
}


int main() {
    
	int size;
	cin >> size;
	int * input = new int[size + 1];
	
	for(int i = 0; i < size; i++) {
		cin >> input[i];
    }
	
	cout << DuplicateNumber(input, size);	
	
	return 0;
}