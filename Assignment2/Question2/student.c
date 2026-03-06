/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int heightAndBST(struct TreeNode* root, long min, long max) {
    if (root == NULL) return 0;

    if (root->val <= min || root->val >= max) return -1;
    
    int leftHeight = heightAndBST(root->left, min, root->val);
    int rightHeight = heightAndBST(root->right, root->val, max);
    
    if (leftHeight == -1 || rightHeight == -1) return -1;
    
    int factor = leftHeight - rightHeight;
    if (factor > 1 || factor < -1) return -1;
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    return (heightAndBST(root,LONG_MIN,LONG_MAX) == -1 ? false : true);

}
