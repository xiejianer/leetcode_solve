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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        postorderTraversal(root, vec);
        return vec;
    }
    void postorderTraversal(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        postorderTraversal(root->left, vec);
        postorderTraversal(root->right, vec);
        vec.push_back(root->val);
    }
};
