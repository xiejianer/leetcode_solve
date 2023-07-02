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
    void recoverTree(TreeNode* root) {
        unordered_map<int, TreeNode*> um;
        vector<int> vec;
        tree2array(root, vec, um);
        int val1 = 0;
        int val2 = 0;
        int is_first = 1;
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] < vec[i - 1]) {
                if (is_first == 1) {
                    val1 = vec[i - 1];
                    val2 = vec[i];
                    is_first = 0;
                } else {
                    val2 = vec[i];
                }
            }
        }
        um[val1]->val = val2;
        um[val2]->val = val1;
        return;
    }
    void tree2array(TreeNode* root, vector<int>& vec, unordered_map<int, TreeNode*>& um) {
        if (root == nullptr) return;
        tree2array(root->left, vec, um);
        vec.push_back(root->val);
        um[root->val] = root;
        tree2array(root->right, vec, um);
    }
};
