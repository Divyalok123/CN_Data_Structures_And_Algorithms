// Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.
// Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.
// Assume i & j given will be within limits. And i can be greater than j also.

//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data
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

node *swap_nodes(node *head, int i, int j)
{
    //write your code here
    if (j < i)
    {
        int temp;
        temp = i;
        i = j;
        j = temp;
    }
    node *prev1 = NULL, *prev2 = NULL, *temp1, *temp2;
    node *swp;
    int k = 0;

    if (i == j)
    {
        return head;
    }
    temp1 = head;
    while (k != i)
    {
        prev1 = temp1;
        temp1 = temp1->next;
        k++;
    }

    prev2 = prev1;
    temp2 = temp1;
    while (k != j)
    {
        prev2 = temp2;
        temp2 = temp2->next;
        k++;
    }

    // critical part
    prev2->next = temp1;
    swp = temp1->next;
    temp1->next = temp2->next;
    temp2->next = swp;

    // check if prev1 exists
    if (prev1)
        prev1->next = temp2;
    else
        head = temp2;
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
    int i, j;
    node *head = takeinput();
    cin >> i;
    cin >> j;
    head = swap_nodes(head, i, j);
    print(head);
    return 0;
}
