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

class pair1
{
public:
    TreeNode<int> *max1;
    TreeNode<int> *max2;

    pair1()
    {
        max1 = NULL;
        max2 = NULL;
    }
};
pair1 helper(TreeNode<int> *root)
{
    TreeNode<int> *x = NULL;
    pair1 p;
    if (root == NULL)
        return p;

    if (root != NULL)
    {
        if (p.max1 == NULL)
        {
            p.max1 = root;
        }
        else
        {
            if (p.max1->data < root->data)
                p.max1 = root;
        }
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        pair1 t = helper(root->children[i]);
        if (t.max1 != NULL && t.max1 > p.max1)
        {
            x = p.max1;
            p.max1 = t.max1;

            if (t.max2 != NULL)
                p.max2 = max(x, t.max2);

            else
                p.max2 = x;
        }
        else if (t.max1 != NULL && t.max1 <= p.max1)
        {
            if (p.max2 != NULL)
                p.max2 = max(p.max2, t.max1);

            if (p.max2 == NULL)
                p.max2 = t.max1;
        }
        else if (t.max1 == NULL)
            continue;
    }
    return p;
}

TreeNode<int> *secondLargest(TreeNode<int> *root)
{
    if(root == NULL) return NULL;
    pair1 t1 = helper(root);
    return t1.max2;
}

#include <climits>

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

/* test cases 


1 1 2 2 30 4 1 5 1 60 1 70 1 8 1 9 1 100 0 0

correct: 70

1 3 20 3 40 1 90 2 50 6 1 100 1 150 17 1000 2000 3000 4000 5000 6000 7000 85 86 87 88 89 92 93 94 95 96 1 80 1 83 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

correct: 6000

*/