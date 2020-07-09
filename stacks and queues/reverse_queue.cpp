/*
Given a queue of integers, reverse it without help of any explicit stack or queue. You need to change in the given queue itself.
*/

#include <iostream>
using namespace std;

#include <queue>

void reverseQueue(queue<int> &q)
{
    if (q.empty())
        return;

    int x = q.front();
    q.pop();

    reverseQueue(q);

    q.push(x);
}

int main()
{
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        q.push(val);
    }
    reverseQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
