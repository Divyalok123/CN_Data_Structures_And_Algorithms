#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    string key;
    int value;
    Tree *parent;
    Tree *left;
    Tree *right;

    Tree(string k, int v)
    {
        this->key = k;
        this->value = v;

        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

Tree *findEntry(Tree *root, string k) //search function
{
    if (root == NULL)
        return NULL;

    Tree *curr = root;
    Tree *prev = root;

    while (curr != NULL)
    {
        if (k.compare(curr->key) < 0)
        {
            prev = curr;
            curr = curr->left;
        }

        else if (k.compare(curr->key) > 0)
        {
            prev = curr;
            curr = curr->right;
        }

        else
        {
            return curr;
        }
    }
    return prev;
}

int get(Tree *root, string k) //getter function
{
    Tree *p = findEntry(root, k);
    if (k.compare(p->key) == 0)
    {
        return p->value;
    }
    return -1;
}

void insert(Tree *root, string k, int v) //insert function
{
    Tree *temp;

    if (root == NULL)
    {
        root = new Tree(k, v);
        return;
    }

    temp = findEntry(root, k);
    if (k.compare(temp->key) == 0)
    {
        temp->value = v;
        return;
    }

    Tree *newNode = new Tree(k, v);
    newNode->parent = temp;
    if (k.compare(temp->key) < 0)
    {
        temp->left = newNode;
    }
    else
    {
        temp->right = newNode;
    }
}

void remove(Tree *root, string k)
{
    Tree *temp;
    Tree *parent;
    Tree *succ;

    temp = findEntry(root, k);
    if (!k == temp->key)
    {
        return;
    }

    if (temp->left == NULL || temp->right == NULL)
    {
        parent = temp->parent;
        if (parent->left == temp)
        {
            parent->left = NULL;
        }
        else
            parent->right = NULL;

        return;
    }

    if (temp->left == NULL)
    {
        parent = temp->parent;
        if (parent->left == temp)
        {
            parent->left = temp->right;
        }
        else
            parent->right = temp->right;
        return;
    }

    if (temp->right == NULL)
    {
        parent = temp->parent;

        if (parent->left == temp)
        {
            parent->left = temp->left;
        }
        else
            parent->right = temp->left;
        return;
    }

    succ = temp->right;

    while (succ != NULL)
    {
        succ = succ->left;
    }

    temp->key = succ->key;
    temp->value = succ->value;

    parent = succ->parent;
    parent->left = succ->right;

    return;
}

int main()
{
    Tr
    return 0;
}