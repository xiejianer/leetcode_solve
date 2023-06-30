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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() != 0) {
            int cnt = q.size();
            vector<int> vec;
            while (cnt) {
                TreeNode* ptr = q.front();
                if (ptr->left != nullptr) {
                    q.push(ptr->left);
                }
                if (ptr->right != nullptr) {
                    q.push(ptr->right);
                }
                vec.push_back(ptr->val);
                q.pop();
                --cnt;
            }
            if (vec.size() > 0) {
                res.push_back(vec);
            }
        }
        return res;
    }
};
