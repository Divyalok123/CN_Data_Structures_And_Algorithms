/*
Given a linked list, delete all alternate nodes in the list. That means given Linked List is -
10 20 30 40 50 60 
you need to delete nodes - 20, 40 and 60
*/

//delete alternate Node in a linked list
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

    ~Node()
    {
        if (next)
        {
            delete next;
        }
    }
};

using namespace std;

void delete_alternate_node_LinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp->next = temp->next->next;
        temp = temp->next;
    }
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
    delete_alternate_node_LinkedList(head);
    print(head);
    delete head;
    return 0;
}