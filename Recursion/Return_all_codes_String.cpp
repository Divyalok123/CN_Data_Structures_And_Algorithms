// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.

#include <iostream>
using namespace std;

#include <string>

using namespace std;

int toint(char x)
{
    int res = x - '0';
    return res;
}

char tochar(int x)
{
    char res = x + 'a' - 1;
    return res;
}

int getCodes(string input, string output[10000])
{
    if (input.size() == 0)
        return 1;
    if (input.size() == 1)
    {
        output[0] = output[0] + tochar(toint(input[0]));
        return 1;
    }

    string r1[10000], r2[10000];

    int size1 = getCodes(input.substr(1), r1);

    int size2 = 0;

    if (input.size() > 1 && ((toint(input[0]) * 10 + toint(input[1])) >= 10 && (toint(input[0]) * 10 + toint(input[1])) <= 26))
    {
        size2 = getCodes(input.substr(2), r2);
    }
    for (int i = 0; i < size1; i++)
    {
        output[i] = tochar(toint(input[0])) + r1[i];
    }

    for (int j = 0; j < size2; j++)
    {
        output[j + size1] = tochar(toint(input[0]) * 10 + toint(input[1])) + r2[j];
    }

    return size1 + size2;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
