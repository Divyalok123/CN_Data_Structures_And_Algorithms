/*
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
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

bool containsX(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    for (int i = 0; i < root->children.size(); i++)
    {
        bool result = containsX(root->children[i], x);
        if (result == true)
            return true;
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
    int x;
    cin >> x;
    TreeNode<int> *root = takeInputLevelWise();
    if (containsX(root, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
