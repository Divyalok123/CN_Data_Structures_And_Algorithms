// Given an integer array A of size N, check if the input array can be splitted in two parts such that -
// - Sum of both parts is equal
// - All elements in the input, which are divisible by 5 should be in same group.
// - All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
// - Elements which are neither divisible by 5 nor by 3, can be put in any group.
// Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
// Return true, if array can be split according to the above rules, else return false.
// Note : You will get marks only if all the test cases are passed.

#include <iostream>
using namespace std;

bool helper(int *input, int size, int s, int l, int r)
{
    if (s == size)
        return l == r;
    if (input[s] % 5 == 0)
        l += input[s];

    else if (input[s] % 3 == 0)
        r += input[s];

    else
    {
        return helper(input, size, s + 1, l + input[s], r) || helper(input, size, s + 1, l, r + input[s]);
    }
    return helper(input, size, s + 1, l, r);
}

bool splitArray(int *input, int size)
{
    return helper(input, size, 0, 0, 0);
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
