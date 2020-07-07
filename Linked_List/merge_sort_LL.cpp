// Sort a given linked list using Merge Sort.

//merge sort recursive
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

node *mergeTwoLLs(node *head1, node *head2)
{
    node *fHead = NULL;
    node *fTail = NULL;

    node *temp1 = head1;
    node *temp2 = head2;

    if (temp1 == NULL)
    {
        fHead = temp2;
        return fHead;
    }
    else if (temp2 == NULL)
    {
        fHead = temp1;
        return fHead;
    }

    if (temp1->data > temp2->data)
    {
        fHead = temp2;
        fTail = temp2;
        temp2 = temp2->next;
    }
    else
    {
        fHead = temp1;
        fTail = temp1;
        temp1 = temp1->next;
    }

    while ((temp1 != NULL) && (temp2 != NULL))
    {
        if (temp1->data > temp2->data)
        {
            fTail->next = temp2;
            temp2 = temp2->next;
            fTail = fTail->next;
        }

        else
        {
            fTail->next = temp1;
            temp1 = temp1->next;
            fTail = fTail->next;
        }
    }

    if (temp1 == NULL)
        fTail->next = temp2;
    else
        fTail->next = temp1;

    return fHead;
}

node *mergeSort(node *head)
{
    node *t = head;

    if (t == NULL || t->next == NULL)
        return head;

    node *mid = midpoint_linkedlist(t);
    node *head2 = mid->next;
    mid->next = NULL;

    node *a = mergeSort(head);
    node *b = mergeSort(head2);

    head = mergeTwoLLs(a, b);

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
    head = mergeSort(head);
    print(head);
    return 0;
}
