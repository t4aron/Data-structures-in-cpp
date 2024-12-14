#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Preorder traversal function (root -> left -> right)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Visit the root
    cout << root->value << " ";

    // Traverse the left subtree
    preorderTraversal(root->left);

    // Traverse the right subtree
    preorderTraversal(root->right);
}