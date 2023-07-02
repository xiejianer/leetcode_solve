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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (! isValidBST(root->left)) return false;
        if (! isValidBST(root->right)) return false;
        TreeNode* ptr = root->left;
        while (ptr != nullptr && ptr->right != nullptr) {
            ptr = ptr->right;
        }
        if (ptr != nullptr && ptr->val >= root->val) return false;
        ptr = root->right;
        while (ptr != nullptr && ptr->left != nullptr) {
            ptr = ptr->left;
        }
        if (ptr != nullptr && ptr->val <= root->val) return false;
        return true;
    }
};
