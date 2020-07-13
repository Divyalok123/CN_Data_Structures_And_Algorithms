/*
Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.
*/

#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL && root2 != NULL) return false;
    if(root1 != NULL && root2 == NULL) return false;
    
    if(root1 -> data != root2 -> data) return false;
    for(int i = 0; i < root1->children.size(); i++)
    {
        if(root1->children[i]->data != root2->children[i]->data) return false;
        return isIdentical(root1->children[i], root2->children[i]);
    }

    return true;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    if(isIdentical(root1, root2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
