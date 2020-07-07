// Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
// Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.

//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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

node *arrange_LinkedList(node *head)
{
    //write your code here
    node *temp1 = head;
    node *temp2 = temp1->next;
    while (temp2 != NULL)
    {
        if ((temp1->data) % 2 != 0)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        else if ((temp1->data) % 2 == 0)
        {
            while ((temp2->data) % 2 != 0)
            {
                while (temp2 != NULL)
                    temp2 = temp2->next;
            }
            int x;
            x = temp1->data;
            temp1->data = temp2->data;
            temp2->data = x;

            temp1 = temp1->next;
            temp2 = temp1->next;
        }
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
    head = arrange_LinkedList(head);
    print(head);
    return 0;
}
