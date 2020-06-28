// You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the clockwise direction.
// Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.

#include <iostream>
using namespace std;

// arr - input array
// n - size of array

int arrayRotateCheck(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    int count = 0;
    while ((i < j) && (arr[i] <= arr[i + 1]))
    {
        count++;
        i++;
    }
    if (count >= n - 1)
    {
        return 0;
    }
    else
        return count + 1;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << arrayRotateCheck(input, size) << endl;
        delete[] input;
    }

    return 0;
}