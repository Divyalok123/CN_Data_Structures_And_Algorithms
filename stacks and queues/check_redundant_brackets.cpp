/*
Given a string mathematical expression, return true if redundant brackets are present in the expression. Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.
Assume the given string expression is balanced and contains only one type of bracket i.e. ().
Note: You will not get partial score for this problem. You will get marks only if all test cases are passed.
*/

#include <iostream>
#include <stack>
using namespace std;

bool isOpen(char x)
{
    if (x == '(')
        return true;
    return false;
}

bool isClose(char x)
{
    if (x == ')')
        return true;
    return false;
}

bool checkRedundantBrackets(char *input)
{
    stack<char> s;
    int i = 0;

    while (input[i] != '\0')
    {

        if (isClose(input[i]))
        {
            int count = 0;
            while (!isOpen(s.top()))
            {
                count++;
                s.pop();
            }

            if (count > 0)
            {
                s.pop();
            }
            else
                return true;
        }

        s.push(input[i]);
        i++;
    }
    return false;
}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);

    if (checkRedundantBrackets(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
