class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 1) return vector<int>{-1, -1};
        vector<int> res;
        int left = lower_bound(nums, 0, len, target);
        int right = upper_bound(nums, 0, len, target);
        if (left == len || nums[left] != target) {
            left = -1;
        }
        if (right == 0 || nums[right - 1] != target) {
            right = -1;
        }
        right = (right == -1) ? right: right - 1;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
    int lower_bound(const vector<int>& nums, int left, int right, int target) {
        int mid = 0;
        while (left != right) {
            mid = left + ((right - left) >> 1);
            if (target > nums[mid]) {
                left = ++mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int upper_bound(const vector<int>& nums, int left, int right, int target) {
        int mid = 0;
        while (left != right) {
            mid = left + ((right - left) >> 1);
            if (target >= nums[mid]) {
                left = ++mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
