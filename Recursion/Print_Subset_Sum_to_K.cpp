// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

#include <iostream>
using namespace std;

void helper(int input[], int size, int k, int output[], int size1)
{
    if (size == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < size1; i++)
            {
                cout << output[i] << " ";
            }
            cout << "\n";
            return;
        }
        else
            return;
    }
    int newOut[10000];

    int i;
    for (i = 0; i < size1; i++)
    {
        newOut[i] = output[i];
    }
    newOut[i] = input[0];

    helper(input + 1, size - 1, k - input[0], newOut, size1 + 1);
    helper(input + 1, size - 1, k, output, size1);
}

void printSubsetSumToK(int input[], int size, int k)
{
    int output[10000];
    helper(input, size, k, output, 0);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
