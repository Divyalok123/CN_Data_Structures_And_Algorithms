// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

#include <iostream>
using namespace std;

#include <cstring>
#include <cmath>

void pairStar(char input[])
{
    if (strlen(input) == 0 || strlen(input) == 1)
        return;
    if (input[0] == input[1])
    {
        int n = strlen(input);
        for (int i = n - 1; i >= 0; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
        input[n + 1] = '\0';
        pairStar(input + 2);
    }
    else
        pairStar(input + 1);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}
