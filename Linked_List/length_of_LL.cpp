// For a given singly linked list of integers, find and return its length. Do it using an iterative method.

#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

int length(Node *head)
{
    int length = 0;
    Node *temp = head;
    if (temp == NULL)
        return 0;
    if (temp->next == NULL)
        return 1;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        cout << length(head) << endl;
    }
    return 0;
}