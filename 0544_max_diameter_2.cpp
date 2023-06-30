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
        maxdepth(root);
        return max_diameter;
    }
    int maxdepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        if (left + right > max_diameter) {
            max_diameter = left + right;
        }
        return max(left, right) + 1;
    }
private:
    int max_diameter = 0;
};
