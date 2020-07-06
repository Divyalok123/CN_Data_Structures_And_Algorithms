// Given a linked list and a position i, delete the node of ith position from Linked List recursively.
// If position i is greater than length of LL, then you should return the same LL without any change.

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

Node *deleteNodeRec(Node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }

    if (i == 0)
    {
        head = head->next;
        return head;
    }

    head->next = deleteNodeRec(head->next, i - 1);
    return head;
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = takeinput();
    int pos;
    cin >> pos;
    head = deleteNodeRec(head, pos);
    print(head);
    return 0;
}
