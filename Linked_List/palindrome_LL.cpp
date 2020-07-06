// You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

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

/*----------------------------------*/

using node = Node;
node *reverse_linked_list_rec(node *head)
{

    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;

    node *temp = reverse_linked_list_rec(head->next);

    head->next->next = head;
    head->next = NULL;

    return temp;
}

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

bool isPalindrome(node *head)
{
    if (head == NULL)
        return true;
    if (head->next == NULL)
        return true;

    if (head->next->next == NULL)
    {
        if (head->data != head->next->data)
            return false;
        return true;
    }
    node *temp = head;
    node *mid = midpoint_linkedlist(temp);

    node *head2 = mid->next;
    mid->next = NULL;

    head2 = reverse_linked_list_rec(head2);
    while (head != NULL && head2 != NULL)
    {
        if (head->data != head2->data)
            return false;
        else
        {
            head = head->next;
            head2 = head2->next;
        }
    }

    return true;
}

/*----------------------------------*/

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}