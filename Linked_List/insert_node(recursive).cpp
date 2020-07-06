// Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.
// If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.
// Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.
// Input format :

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

Node *insertNodeRec(Node *head, int i, int data)
{

    Node *newNode = new Node(data);
    if (head == NULL && i != 0)
    {
        return head;
    }

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *newh = insertNodeRec(head->next, i - 1, data);
    head->next = newh;
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
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}
