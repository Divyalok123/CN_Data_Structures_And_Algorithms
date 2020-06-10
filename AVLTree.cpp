#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

class Node
{
public:
    int height;
    int value;
    Node *left;
    Node *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *newNode(int value)
{
    Node *node = new Node();
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Node *rightRotate(Node *z)
{
    Node *p1 = z->left;
    Node *p2 = p1->right;

    p1->right = z;
    z->left = p2;

    z->height = max(height(z->left), height(z->right)) + 1;
    p1->height = max(height(p1->left), height(p1->right)) + 1;

    return p1;
}

Node *leftRotate(Node *z)
{
    Node *p1 = z->right;
    Node *p2 = p1->left;

    p1->left = z;
    z->right = p2;

    z->height = max(height(z->left), height(z->right)) + 1;
    p1->height = max(height(p1->left), height(p1->right)) + 1;

    return p1;
}

int getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
        return newNode(value);

    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }

    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }

    else // Equal value are discarded
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int bal = getBalance(root);

    if (bal > 1 && value < root->left->value)
    {
        return rightRotate(root);
    }

    if (bal > 1 && value > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bal < -1 && value > root->right->value)
    {
        return leftRotate(root);
    }

    if (bal < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *minNode(Node *root)
{
    if (root == NULL)
        return root;

    Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->value)
    {
        root->left = deleteNode(root->left, value);
    }

    else if (value > root->value)
    {
        root->right = deleteNode(root->right, value);
    }

    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }

            else
            {
                root->value = temp->value;
                temp = NULL;
            }

            delete temp;
        }
        else
        {
            Node *temp = minNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int bal = getBalance(root);

    if (bal > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    if (bal > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bal < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    if (bal < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 13);
    root = insert(root, 18);
    root = insert(root, 3);
    root = insert(root, 6);

    printPreOrder(root);

    root = deleteNode(root, 5);
    cout << endl;
    printPreOrder(root);
    return 0;
}