// Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.

//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
#include <iostream>
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

node *skipMdeleteN(node *head, int M, int N)
{
    node *temp = head;
    if (M == 0)
        return NULL;
    while (temp != NULL)
    {
        int val0 = M;
        int val1 = N;

        while (--val0 && temp != NULL)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            return head;

        node *t = temp->next;
        while (val1-- && t != NULL)
        {
            node *a = t;
            t = t->next;
            delete a;
        }
        temp->next = t;
        temp = t;
    }

    return head;
}

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
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
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = takeinput();
    int m, n;
    cin >> m >> n;
    head = skipMdeleteN(head, m, n);
    print(head);
    return 0;
}
