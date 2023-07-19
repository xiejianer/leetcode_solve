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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<int> path;
        dfs(res, path, root, targetSum, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int targetSum, int currSum) {
        if (root == nullptr) return;
        currSum += root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && currSum == targetSum) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        dfs(res, path, root->left, targetSum, currSum);
        dfs(res, path, root->right, targetSum, currSum);
        path.pop_back();
        return;
    }
};
