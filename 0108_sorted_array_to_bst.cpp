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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        if (nums.size() == 0) return root;
        root = sortedArrayToBST(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode* sortedArrayToBST(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        int mid = left + (right - left) / 2;
        root->val = nums[mid];
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }
};
