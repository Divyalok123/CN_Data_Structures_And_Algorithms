// Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.

//bubble sort iterative
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

int length(node *head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

node *bubble_sort_LinkedList_itr(node *head)
{
    int n1 = length(head);
    while (n1--)
    {
        node *prev = NULL;
        node *temp = head;
        int n2 = n1;
        while (n2--)
        {
            if (temp->data > temp->next->data)
            {
                if (temp == head)
                {
                    head = temp->next;
                    temp->next = temp->next->next;
                    head->next = temp;
                    prev = head;
                }

                else
                {
                    prev->next = temp->next;
                    node *t = temp->next->next;
                    prev->next->next = temp;
                    temp->next = t;
                    prev = prev->next;
                }
            }

            else
            {
                prev = temp;
                temp = temp->next;
            }
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
    head = bubble_sort_LinkedList_itr(head);
    print(head);
}
