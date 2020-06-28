// Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.
// Assume, duplicate number is always present in the array.

#include <iostream>
using namespace std;

// arr - input array
// size - size of array

int DuplicateNumber(int arr[], int size)
{
    int res = arr[0];
    for (int i = 1; i < size; i++)
    {
        res ^= arr[i];
    }
    for (int i = 0; i <= size - 2; i++)
    {
        res ^= i;
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

    cout << DuplicateNumber(input, size);

    delete[] input;

    return 0;
}