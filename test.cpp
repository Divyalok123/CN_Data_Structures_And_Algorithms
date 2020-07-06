// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
//FN TO FIND THE MID OF THE LL
node *midpoint_linkedlist(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL)
    {
        if (fast->next == NULL || (fast->next)->next == NULL)
        {
            fast = fast->next;
            break;
        }
        else
            fast = (fast->next)->next;
        slow = slow->next;
    }
    return slow;
}
//fn to merge the left and right half of a given ll
node *mergeTwoLLs(node *head1, node *tail1)
{
    node *fhead = NULL;
    node *ftail = NULL;
    node *midpt = midpoint_linkedlist(head1);

    node *temp1 = head1;
    node *temp2 = midpt;

    while (temp1 != midpt && temp2 != tail1->next)
    {
        if (temp1->data < temp2->data)
        {
            if (fhead == NULL) //inserting the 1st elem
            {
                fhead = head1;
                ftail = head1;
            }
            else //ins the other elem
            {
                node *a = temp1->next; //trav to the next elem
                ftail->next = temp1;
                ftail = temp1;
                temp1 = a;
            }
        }
        else
        {
            if (fhead == NULL) //inserting the 1st elem
            {
                fhead = midpt;
                ftail = midpt;
            }
            else //ins the other elem
            {
                node *a = temp2->next; //trav to the next elem
                ftail->next = temp2;
                ftail = temp2;
                temp2 = a;
            }
        }

        //TRAVERSING TO THE NEXT ELE
    }
    while (temp1 != midpt) //IF THERE ARE REM ELEM IN THE 1st LL
    {
        ftail->next = temp1;
        ftail = temp1;
        //TRAVERSING TO THE NEXT ELE
        temp1 = temp1->next;
    }
    while (temp2 != tail1->next) //IF THERE ARE REM ELEM IN THE 2nd LL
    {
        ftail->next = temp2;
        ftail = temp2;
        //TRAVERSING TO THE NEXT ELE
        temp2 = temp2->next;
    }
    return fhead; //return head node of the final LL
}

node *mergeSortsub(node *head, node *tail)
{
    if (head == tail) //BASE CASE(ONLY 1 ELEM)
        return head;
    node *midpoint = midpoint_linkedlist(head);
    //finding mid tail(element before mid point)
    node *midtail = head;
    while (midtail != NULL && midtail->next != midpoint)
        midtail = midtail->next;
    //left sub LL call
    head = mergeSortsub(head, midtail);
    //right sub LL call
    node *right = mergeSortsub(midpoint, tail);
    //merging the left and the right sorted LLs
    head = mergeTwoLLs(head, tail);
    return head;
}

node *mergeSort(node *head)
{
    if (head != NULL)
    {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        node *tail = temp;
        head = mergeSortsub(head, tail);
    }
    return head;
}
