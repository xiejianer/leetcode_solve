class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int idx1 = 0;
        int idx2 = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i == 0) {
                reverse(nums, 0);
                break;
            } else {
                if (nums[i] > nums[i - 1]) {
                    int idx = findFirstBig(nums, nums[i - 1], i);
                    swap(nums[i-1], nums[idx]);
                    reverse(nums, i);
                    break;
                }
            }
        }
        return;
    }
    void reverse(vector<int>& nums, int idx) {
        if (idx >= nums.size() - 1) return;
        int i = nums.size() - 1;
        while (idx < i) {
            swap(nums[idx], nums[i]);
            ++idx;
            --i;
        }
        return;
    }
    int findFirstBig(const vector<int>& nums, int target, int end_idx) {
        int idx = nums.size() - 1;
        while (idx >= end_idx) {
            if (nums[idx] > target) {
                return idx;
            }
            --idx;
        }
        return -1;
    }
};
