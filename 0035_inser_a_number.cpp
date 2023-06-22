class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return -1;
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = --mid;
            }
            else {
                left = ++mid;
            }
        }
        if (nums[left] >= target) return left;
        if (nums[left] < target) return left + 1;
        return 0;
    }
};

