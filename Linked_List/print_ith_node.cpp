// For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

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

void printIthNode(Node *head, int i)
{
    Node *temp = head;
    while (i-- && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (i >= 0)
        return;
    else
        cout << temp->data << endl;
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
        int pos;
        cin >> pos;
        printIthNode(head, pos);
        cout << endl;
    }
    return 0;
}