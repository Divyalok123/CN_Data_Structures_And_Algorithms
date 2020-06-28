// Given a string, find and print all the possible permutations of the input string.
// Note : The order of permutations are not important. Just print them in different lines.

#include <iostream>
#include <string>
using namespace std;

void hprintPermutations(string input, int l, int r)
{
    if (l == r)
        cout << input << "\n";
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(input[l], input[i]);
            hprintPermutations(input, l + 1, r);
        }
    }
}

void printPermutations(string input)
{
    hprintPermutations(input, 0, input.size() - 1);
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
