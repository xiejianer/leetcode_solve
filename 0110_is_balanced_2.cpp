class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) >= 0;
    }
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1) {
            return -1;
        } else {
            return max(left->height, right->height) + 1;
        }
    }
};
