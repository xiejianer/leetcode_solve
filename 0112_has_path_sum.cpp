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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        bool res = dfs(root, targetSum, root->val);
        return res;
    }
    bool dfs(TreeNode* root, int targetSum, int currSum) {
        if (root == nullptr) return false;
        if (currSum == targetSum && root->left == nullptr && root->right == nullptr) return true;
        bool res = false;
        if (root->left != nullptr && dfs(root->left, targetSum, currSum + root->left->val)) {
            return true;
        }
        if (root->right != nullptr && dfs(root->right, targetSum, currSum + root->right->val)) {
            return true;
        }
        return false;
    }
};
