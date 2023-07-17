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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = nullptr;
        if (inorder.size() == 0 || postorder.size() != inorder.size()) return root;
        root = solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        return root;
    }
    TreeNode* solve(const vector<int>& inorder, int l1, int r1,
                    const vector<int>& postorder, int l2, int r2) {
        if (l1 < 0 || r1 >= inorder.size() || l1 > r1 || l2 < 0 || r2 >= postorder.size() || l2 > r2) {
            return nullptr;
        }
        TreeNode* ptr = new TreeNode();
        if (l1 == r1) {
            ptr->val = inorder[l1];
            return ptr;
        } else {
            int i = l1;
            for (i = l1; i <= r1; ++i) {
                if (inorder[i] == postorder[r2]) {
                    break;
                }
            }
            ptr->val = postorder[r2];
            ptr->left = solve(inorder, l1, i - 1, postorder, l2, i + l2 - l1 - 1);
            ptr->right = solve(inorder, i + 1, r1, postorder, i + l2 - l1, r2 - 1);
            return ptr;
        }
        return nullptr;
    }
};
