#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pqueue;

    pqueue.push(23);
    pqueue.push(25);
    pqueue.push(12);
    pqueue.push(199);
    pqueue.push(34);
    pqueue.push(46);
    pqueue.push(56);

    cout << "Size: " << pqueue.size() << endl;
    cout << "Top: " << pqueue.top() << endl;

    while (!pqueue.empty())
    {
        cout << pqueue.top() << endl;
        pqueue.pop();
    }

    return 0;
}