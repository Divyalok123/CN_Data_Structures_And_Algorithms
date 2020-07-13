/*

Given a generic tree, print the input tree in level wise order. ####For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
wherer, N is data of any node present in the binary tree. x1, x2, x3, ...., xn are the children of node N
There is no space in between.
You need to print all nodes in the level order form in different lines.
*/

#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

#include <queue>

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<TreeNode<int> *> q;

    q.push(root);

    while (q.size() != 0)
    {

        TreeNode<int> *newNode = q.front();
        q.pop();
        cout << newNode->data << ":";
        for (int i = 0; i < newNode->children.size(); i++)
        {
            if (i == newNode->children.size() - 1)
            {
                cout << newNode->children[i]->data;
            }
            else
                cout << newNode->children[i]->data << ",";

            q.push(newNode->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
}
