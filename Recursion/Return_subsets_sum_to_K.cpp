// Given an array A of size n and an integer K, return all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }

    int o1[10000][50];
    int o2[10000][50];

    int s1 = subsetSumToK(input + 1, n - 1, o1, k);
    int s2 = subsetSumToK(input + 1, n - 1, o2, k - input[0]);

    int row = 0;
    // copying from O1 to output
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j <= o1[i][0]; j++)
        {
            output[row][j] = o1[i][j];
        }
        row++;
    }
    // copying from o2
    for (int i = 0; i < s2; i++)
    {
        output[row][0] = o2[i][0] + 1;
        output[row][1] = input[0];
        for (int j = 1; j <= o2[i][0]; j++)
        {
            output[row][j + 1] = o2[i][j];
        }
        row++;
    }
    return s1 + s2;
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
