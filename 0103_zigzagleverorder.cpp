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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while (q.size() > 0) {
            int len = q.size();
            vector<int> vec;
            flag = 1 - flag;
            while (len > 0) {
                TreeNode* ptr = q.front();
                vec.push_back(ptr->val);
                q.pop();
                if (ptr->left != nullptr) {
                    q.push(ptr->left);
                }
                if (ptr->right != nullptr) {
                    q.push(ptr->right);
                }
                --len;
            }
            if (vec.size() != 0) {
                if (flag == 0) {
                    reverse(vec.begin(), vec.end());
                }
                res.push_back(vec);
            }
        }
        return res;
    }
};
