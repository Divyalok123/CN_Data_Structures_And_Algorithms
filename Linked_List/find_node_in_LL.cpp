// Given a linked list and an integer n you need to find and return index where n is present in the LL. Do this recursively.
// Return -1 if n is not present in the LL.

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

int indexOfNRecursive(Node *head, int n)
{
    if (head == NULL)
        return -1;
    if (head->data == n)
    {
        return 0;
    }
    int returnVal = indexOfNRecursive(head->next, n);
    return (returnVal == -1) ? -1 : returnVal + 1;
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
    int n;
    cin >> n;
    cout << indexOfNRecursive(head, n);
}
