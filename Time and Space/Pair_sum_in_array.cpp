// Given a random integer array A and a number x. Find and print the pair of elements in the array which sum to x.
// Array A can contain duplicate elements.
// While printing a pair, print the smaller element first.
// That is, if a valid pair is (6, 5) print "5 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.

#include <iostream>
#include <algorithm>
using namespace std;

void pairSum(int input[], int size, int x)
{
    sort(input, input + size);
    if (size < 2)
        return;

    if (size == 2)
    {
        if ((input[0] + input[1]) == x)
            cout << input[0] << " " << input[1] << endl;
        else
            return;
    }

    if (input[0] == input[size - 1] && (2 * input[0] == x))
    {
        int n = (size - 1) * size / 2;
        for (int i = 0; i < n; i++)
        {
            cout << input[0] << " " << input[0] << "\n";
        }
        return;
    }
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        if (input[i] + input[j] == x)
        {
            cout << input[i] << " " << input[j] << "\n";
            j--;
            int count = 1;
            while (input[i] + input[j] == x && i < j)
            {
                cout << input[i] << " " << input[j] << "\n";
                j--;
                count++;
            }
            i++;
            j += count;
        }
        else if (input[i] + input[j] > x)
        {
            j--;
        }
        else
            i++;
    }
}

int main()
{

    int size;
    int x;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;
    pairSum(input, size, x);

    return 0;
}
