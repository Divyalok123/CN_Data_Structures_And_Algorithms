// Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
// You need to find and return that number which is unique in the array.
// Note : Given array will always contain odd number of elements.

#include <iostream>
#include <algorithm>
using namespace std;

int FindUnique(int arr[], int size)
{
    int res = arr[0];
    for (int i = 1; i < size; i++)
    {
        res ^= arr[i];
    }
    return res;
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[1 + size];
    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << FindUnique(input, size) << endl;
    return 0;
}
