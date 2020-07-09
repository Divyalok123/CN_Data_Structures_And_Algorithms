/*
Reverse a given Stack with the help of another empty stack. Two stacks will be given. Out of which first contains some integers and second one is empty. You need to reverse the first one using second stack. Change in the given first stack itself.
Note : You don't need to print or return the stack, just reverse the given stack and it will be printed internally.
*/

#include <iostream>
using namespace std;

#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra)
{
    //Recursive(Not working)
    if (input.empty())
    {
        return;
    }

    int x = input.top();
    input.pop();

    reverseStack(input, extra);

    while (!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }

    input.push(x);

    while (!extra.empty())
    {
        input.push(extra.top());
        extra.pop();
    }
}

int main()
{
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        s1.push(val);
    }
    reverseStack(s1, s2);
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}
