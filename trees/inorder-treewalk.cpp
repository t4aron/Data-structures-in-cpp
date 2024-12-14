#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Inorder traversal function (left -> root -> right)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    inorderTraversal(root->left);

    // Visit the root
    cout << root->value << " ";

    // Traverse the right subtree
    inorderTraversal(root->right);
}