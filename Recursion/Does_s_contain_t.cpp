// Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
// Return true or false.
// Do it recursively.
// E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.

#include <iostream>
using namespace std;

bool helper(char large[], char *small, int l, int s)
{
    if (l == 0)
        return false;
    if (s == 0)
        return true;

    if (large[l - 1] == small[s - 1])
        return helper(large, small, l - 1, s - 1);
    return helper(large, small, l - 1, s);
}

bool checksequenece(char large[], char *small)
{
    if (large[0] == '\0')
        return false;
    if (small[0] == '\0')
        return true;
    int i = 0;
    int j = 0;

    while (large[i] != '\0')
        i++;
    while (small[j] != '\0')
        j++;

    return helper(large, small, i, j);
}

int main()
{
    char large[10000];
    char small[10000];
    cin >> large;
    cin >> small;
    bool x = checksequenece(large, small);

    if (x)
        cout << "true";
    else
        cout << "false";
}
