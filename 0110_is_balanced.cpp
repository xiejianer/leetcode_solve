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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (isBalanced(root->left) == false or isBalanced(root->right) == false) return false;
        int d1 = depth(root->left);
        int d2 = depth(root->right);
        if (d1 - d2 > 1 || d2 - d1 > 1) return false;
        return true;
    }
    int depth(TreeNode* ptr) {
        if (ptr == nullptr) return 0;
        return max(depth(ptr->left), depth(ptr->right)) + 1;
    }

};
