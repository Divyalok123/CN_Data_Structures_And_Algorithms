/*
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
*/

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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

Node *NextLargeNumber(Node *head)
{
    head = reverse(head);
    Node *prev = NULL;
    Node *temp = head;
    int carry = 1;
    int sum = 0;
    while (temp != NULL)
    {
        sum = temp->data + carry;

        if (sum >= 10)
        {
            carry = 1;
        }
        else
            carry = 0;

        sum = sum % 10;
        temp->data = sum;
        prev = temp;
        temp = temp->next;
    }

    if (carry > 0)
    {
        Node *newNode = new Node(carry);
        prev->next = newNode;
    }

    head = reverse(head);
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

    head = NextLargeNumber(head);
    print(head);
    return 0;
}
