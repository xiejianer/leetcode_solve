/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        solve(root);
        return;
    }
    TreeNode* solve(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* left = solve(root->left);
        TreeNode* right = solve(root->right);
        if (left == nullptr) {
            root->left = nullptr;
            root->right = right;
        } else {
            root->right = left;
            root->left = nullptr;
            while (left->right != nullptr) {
                left = left->right;
            }
            left->right = right;
        }
        return root;
    }
};
