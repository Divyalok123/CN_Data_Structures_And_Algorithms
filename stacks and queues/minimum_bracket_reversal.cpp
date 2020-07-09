/*
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
*/

#include <iostream>
using namespace std;

#include <stack>

int countBracketReversals(char input[])
{
    int j = 0;
    while (input[j] != '\0')
    {
        j++;
    }

    if (j & 1)
        return -1;

    stack<char> s;
    int i = 0;

    while (input[i] != '\0')
    {
        if (input[i] == '}' && !s.empty() && s.top() == '{')
        {
            s.pop();
            i++;
        }
        else
        {
            s.push(input[i]);
            i++;
        }
    }

    int res = 0;
    while (!s.empty())
    {
        char temp = s.top();
        s.pop();

        if (s.top() == '}' && temp == '{')
            res += 2;
        else if (s.top() == '{' && temp == '{')
            res += 1;
        else if (s.top() == '}' && temp == '}')
            res += 1;

        s.pop();
    }

    return res;
}

int main()
{
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}