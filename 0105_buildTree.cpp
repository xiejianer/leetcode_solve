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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        if (preorder.size() == 0 || preorder.size() != inorder.size()) return root;
        root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return root;
    }
    TreeNode* solve(const vector<int>& preorder, int l1, int r1, const vector<int>& inorder, int l2, int r2) {
        //cout << l1 << '\t' << r1 << '\t' << l2 << '\t' << r2 << endl;
        TreeNode* ptr = new TreeNode();
        if (l1 > r1 || l2 > r2 || l1 < 0 || r1 >= preorder.size() || l2 < 0 || r2 >= inorder.size()) {
            //cout << "fake" << endl;
            return nullptr;
        }
        if (l1 == r1) {
            ptr->val = preorder[l1];
            //cout << "fix: " << preorder[l1] << endl;
            return ptr;
        } else {
            int i = l1;
            for (i = l2; i <= r2; ++i) {
                if (inorder[i] == preorder[l1]) {
                    break;
                }
            }
            ptr->val = preorder[l1];
            ptr->left = solve(preorder, l1 + 1, i + l1 - l2, inorder, l2, i - 1);
            ptr->right = solve(preorder, i + l1 - l2 + 1, r1, inorder, i + 1, r2);
            return ptr;
        }
        return nullptr;
    }
};
