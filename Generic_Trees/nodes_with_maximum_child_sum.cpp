/*
Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.
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

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{

    TreeNode<int> *resNode = root;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *re = maxSumNode(root->children[i]);
        int resSum = re->data;
        for (int j = 0; j < re->children.size(); j++)
        {
            resSum = resSum + re->children[j]->data;
        }

        if (resSum > sum)
        {
            resNode = re;
            sum = resSum;
        }
    }

    return resNode;
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
    TreeNode<int> *ans = maxSumNode(root);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
}
