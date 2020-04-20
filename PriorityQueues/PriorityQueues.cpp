#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Considering min priority queue
//To implement priority queue we need a heap
//To save complete binary tree, we actually need an array(vector)

class PriorityQueue
{
    vector<int> v;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }

    int getSize()
    {
        return v.size();
    }

    int getMin()
    {
        if (v.size() == 0)
            return 0;
        return v[0];
    }

    void insert(int value)
    {
        v.push_back(value);

        int child = v.size() - 1;

        while (child > 0)
        {
            int parent = (child - 1) / 2;
            if (v[parent] > v[child])
            {
                int temp = v[parent];
                v[parent] = v[child];
                v[child] = temp;
            }
            else
                break;

            child = parent;
        }
    }

    int removeMin()
    {
        if (v.size() == 0)
            return 0;
        int s = v.size() - 1;
        int ans = v[0];
        v[0] = v[s];
        v.pop_back();

        int parent = 0;
        int c1 = 2 * parent + 1;
        int c2 = 2 * parent + 2;

        while (c1 < v.size())
        {
            int minIndex = parent;

            if (v[minIndex] > v[c1])
            {
                minIndex = c1;
            }

            if (c2 < v.size() && v[minIndex] > v[c2])
            {
                minIndex = c2;
            }
            if (minIndex == parent)
                break;

            int temp = v[parent];
            v[parent] = v[minIndex];
            v[minIndex] = temp;

            parent = minIndex;
            c1 = 2 * parent + 1;
            c2 = 2 * parent + 2;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue Pqueue;

    Pqueue.insert(10);
    Pqueue.insert(8);
    Pqueue.insert(1);
    Pqueue.insert(7);
    Pqueue.insert(15);
    Pqueue.insert(16);
    Pqueue.insert(32);
    Pqueue.insert(100);

    cout << Pqueue.getSize() << endl;
    cout << Pqueue.getMin() << endl;

    while (!Pqueue.isEmpty())
    {
        cout << Pqueue.removeMin() << " ";
    }
    cout << endl;
    cout << Pqueue.getSize() << endl;
    return 0;
}