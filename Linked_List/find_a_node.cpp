// You have been given a singly linked list of integers. Write a function that returns the index/position of an integer data denoted by 'N'(if it exists). -1 otherwise.

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

int indexOfNIter(Node *head, int n)
{
    int i = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == n)
            break;
        else
        {
            i++;
            temp = temp->next;
        }
    }
    if (temp == NULL)
        return -1;
    return i;
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
        int val;
        cin >> val;
        cout << indexOfNIter(head, val) << endl;
    }
}