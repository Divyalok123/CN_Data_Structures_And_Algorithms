// Given a string S, find and return all the possible permutations of the input string.
// Note 1 : The order of permutations is not important.
// Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input.size() == 0)
    {
        output[0] = "";
        return 1;
    }

    string tempstr[10000];
    int tempsize = returnPermutations(input.substr(1), tempstr);
    int len = 0;
    for (int i = 0; i < tempsize; i++)
    {
        for (int j = 0; j <= tempstr[0].size(); j++)
        {
            output[len] = tempstr[i].substr(0, j) + input[0] + tempstr[i].substr(j);
            len++;
        }
    }
    return len;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
