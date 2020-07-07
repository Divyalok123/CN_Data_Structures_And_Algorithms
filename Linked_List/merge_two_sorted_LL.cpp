// Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
// Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.

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

Node *mergeTwoLLs(Node *head1, Node *head2)
{
    Node *fHead = NULL;
    Node *fTail = NULL;

    Node *temp1 = head1;
    Node *temp2 = head2;

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
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}
