// Given an integer array (of length n), find and print all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print the subsets in different lines.

#include <iostream>
using namespace std;

void helper(int input[], int size, int output[], int size1)
{
    if (size == 0)
    {
        for (int i = 0; i < size1; i++)
        {
            cout << output[i] << " ";
        }
        cout << "\n";
        return;
    }
    int newOutput[1000];
    helper(input + 1, size - 1, output, size1);

    int i;
    for (i = 0; i < size1; i++)
    {
        newOutput[i] = output[i];
    }
    newOutput[i] = input[0];

    helper(input + 1, size - 1, newOutput, size1 + 1);
}

void printSubsetsOfArray(int input[], int size)
{
    int output[1000];
    helper(input, size, output, 0);
    return;
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
