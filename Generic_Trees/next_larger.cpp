/*
Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.

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

TreeNode<int> *nextLargerElement(TreeNode<int> *root, int n)
{
    if (root == NULL)
        return NULL;
    TreeNode<int> *resNode = NULL;
    int curr = 0;
    if (root->data > n)
    {
        if (!resNode || resNode->data > root->data)
        {
            resNode = root;
            curr = root->data;
        }
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *b = nextLargerElement(root->children[i], n);
        int r;
        if (b != NULL)
            r = b->data;

        if (b != NULL && r > n && curr == 0)
        {
            curr = r;
            resNode = b;
        }

        if (b != NULL && r > n && r < curr)
        {
            curr = r;
            resNode = b;
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
    int n;
    cin >> n;
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = nextLargerElement(root, n);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << INT_MIN << endl;
    }
}
