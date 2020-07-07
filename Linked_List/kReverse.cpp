// Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
// Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
// You don't need to print the elements, just return the head of updated LL.

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

node *kReverse(node *head, int n)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *prevll = NULL;
    node *nextll = NULL;
    node *temp1 = head;
    int val = n;

    while (val-- && temp1 != NULL)
    {
        nextll = temp1->next;
        temp1->next = prevll;
        prevll = temp1;
        temp1 = nextll;
    }

    if (temp1 != NULL)
    {
        head->next = kReverse(temp1, n);
    }

    return prevll;
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
    int n;
    cin >> n;
    head = kReverse(head, n);
    print(head);
    return 0;
}
