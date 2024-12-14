#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    vector<TreeNode*> children;  // A node can have multiple children

    TreeNode(int val) : value(val) {}
};

// Preorder traversal (root -> children)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Visit the root
    cout << root->value << " ";

    // Traverse each child
    for (TreeNode* child : root->children) {
        preorderTraversal(child);
    }
}