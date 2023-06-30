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
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return max_diameter;
    }
    void solve(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        if (left + right > max_diameter) {
            max_diameter = left + right;
        }
        solve(root->left);
        solve(root->right);
        return;
    }
    int maxdepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxdepth(root->left), maxdepth(root->right)) + 1;
    }
private:
    int max_diameter = 0;
};
