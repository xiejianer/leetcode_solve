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
    int maxPathSum(TreeNode* root) {
        max_value = INT_MIN;
        solve(root);
        return max_value;
    }
    int solve(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int root_sum  = root->val + max(0, left) + max(0, right);
        if (root_sum > max_value) {
            max_value = root_sum;
        }
        return max(max(left, 0) + root->val, max(right, 0) + root->val);
    }
private:
    int max_value;
};
