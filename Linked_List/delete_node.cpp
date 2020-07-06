// You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'pos'.

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

Node *deleteNode(Node *head, int i)
{

    if (i == 0)
    {
        head = head->next;
        return head;
    }

    int count = 0;
    Node *temp = head;
    // Node * a = head;
    while (count < i - 1 && temp != NULL)
    {

        temp = temp->next;
        count++;
    }

    if (temp->next != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
    }
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
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}