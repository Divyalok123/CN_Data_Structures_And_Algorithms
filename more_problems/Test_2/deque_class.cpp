// C++ implementation of De-queue using circular
// array
#include <iostream>
using namespace std;

class Deque
{

public:
    int rear;
    int front;
    int size;
    int arr[10];

    Deque(int size)
    {
        this->size = size;
        rear = 0;
        front = -1;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void insertFront(int x)
    {
        if (isFull())
        {
            cout << -1 << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        else if (front == 0)
        {
            front = size - 1;
        }

        else
            front--;

        arr[front] = x;
    }

    void insertRear(int x)
    {
        if (isFull())
        {
            cout << -1 << endl;
            return;
        }

        if (rear == size - 1)
        {
            rear = 0;
        }

        else if (front == -1)
        {
            rear = 0;
            front = 0;
        }

        else
        {
            rear++;
        }

        arr[rear] = x;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << -1 << endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else
        {
            if (front == size - 1)
            {
                front = 0;
            }

            else
            {
                front++;
            }
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << -1 << endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
            rear--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[rear];
    }
};

int main()
{
    Deque dq(10);
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            dq.insertFront(input);
            break;
        case 2:
            cin >> input;
            dq.insertRear(input);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            cout << dq.getFront() << "\n";
            break;
        case 6:
            cout << dq.getRear() << "\n";
            break;
        default:
            return 0;
        }
    }

    return 0;
}
