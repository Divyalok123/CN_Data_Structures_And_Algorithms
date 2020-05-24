// Given a string S, remove consecutive duplicates from it recursively.

#include <iostream>
using namespace std;

#include <cstring>

void removeConsecutiveDuplicates(char *input)
{
    if (strlen(input) == 0)
        return;
    if (input[0] == input[1])
    {
        for (int i = 0; input[i] != '\0'; i++)
        {
            input[i] = input[i + 1];
        }
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input + 1);
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}