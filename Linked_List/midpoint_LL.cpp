// Given a linked list, find and return the midpoint.
// If the length of linked list is even, return the first mid point.

//Find midpoint of a Linked List
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

node *midpoint_linkedlist(node *head)
{
    node *slow = head;
    node *fast = head;
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    fast = fast->next->next;
    while ((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    node *mid = midpoint_linkedlist(head);
    cout << mid->data;
    return 0;
}
