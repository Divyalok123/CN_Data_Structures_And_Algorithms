// Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
// You need to return true if it is balanced, false otherwise.
// Note: This problem was asked in initial rounds in Facebook

#include <iostream>
using namespace std;

#include <stack>

bool isPair(char x, char y)
{
    if (x == '{' && y == '}')
        return true;
    else if (x == '(' && y == ')')
        return true;
    else if (x == '[' && y == ']')
        return true;
    else
        return false;
}

bool isOpen(char x)
{
    if (x == '(' || x == '[' || x == '{')
        return true;
    else
        return false;
}

bool isClose(char x)
{
    if (x == ')' || x == ']' || x == '}')
        return true;
    else
        return false;
}

bool checkBalanced(char *exp)
{
    stack<char> s;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isOpen(exp[i]))
        {
            s.push(exp[i]);
        }
        else if (isClose(exp[i]))
        {
            if (s.empty())
                return false;
            if (!isPair(s.top(), exp[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        i++;
    }
    if (s.empty())
        return true;
    else
        return false;
}

int main()
{
    char input[100000];
    cin.getline(input, 100000);
    //    cin >> input;
    if (checkBalanced(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
