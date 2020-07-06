// You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

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

Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL)
        return NULL;

    int count = 0;
    Node *t = head;
    while (t->next != NULL)
    {
        count++;
        t = t->next;
    }

    int val = count - n;
    int i = 0;

    if (val < 0)
        return NULL;

    Node *temp = head;
    while (i < val)
    {
        temp = temp->next;
        i++;
    }

    Node *head2 = temp->next;
    temp->next = NULL;

    Node *newt = head2;
    while (newt->next != NULL)
    {
        newt = newt->next;
    }

    newt->next = head;
    head = head2;

    return head;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}