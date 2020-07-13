/*
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
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
#include <climits>

class Tp
{
public:
    TreeNode<int> *max = NULL;
    TreeNode<int> *smax = NULL;
};

Tp helper(TreeNode<int> *root)
{
    Tp t1;
    if (root == NULL)
    {
        return t1;
    }

    Tp t2;
    t1.max = root;
    t1.smax = NULL;
    TreeNode<int> *temp;
    for (int i = 0; i < root->children.size(); i++)
    {
        t2 = helper(root->children[i]);
        if (t1.max->data == t2.max->data)
        {
            if (t1.smax == NULL)
            {
                if (t2.smax != NULL)
                {
                    t1.smax = t2.smax;
                }
            }
            else
            {
                if (t2.smax != NULL)
                {
                    if (t2.smax->data > t1.smax->data)
                    {
                        t1.smax = t2.smax;
                    }
                }
            }
        }
        else
        {
            if (t1.max->data > t2.max->data)
            {
                t1.smax = t2.max;
            }
            else
            {
                temp = t1.max;
                t1.max = t2.max;
                if (t2.smax != NULL)
                {
                    if (temp->data < t2.smax->data)
                    {
                        t1.smax = t2.smax;
                    }
                    else
                    {
                        t1.smax = temp;
                    }
                }
                else
                {
                    t1.smax = temp;
                }
            }
        }
    }
    return t1;
}

TreeNode<int> *secondLargest(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Tp t1;
    t1 = helper(root);
    return (t1.smax);
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
    TreeNode<int> *ans = secondLargest(root);
    if (ans == NULL)
    {
        cout << INT_MIN << endl;
    }
    else
    {
        cout << ans->data << endl;
    }
}
