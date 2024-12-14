#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    vector<TreeNode*> children;  // A node can have multiple children

    TreeNode(int val) : value(val) {}
};

// Postorder traversal (children -> root)
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse each child
    for (TreeNode* child : root->children) {
        postorderTraversal(child);
    }

    // Visit the root after its children
    cout << root->value << " ";
}