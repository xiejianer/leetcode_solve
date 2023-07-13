class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                if (nums[right] > nums[mid]) {
                    right = mid - 1;
                } else if (nums[mid] == nums[right]) {
                    for (int i = left; i <= right; ++i) {
                        if (nums[i] == target) {
                            return true;
                        }
                    }
                    return false;
                } else {
                    if (nums[left] == target) {
                        return true;
                    } else if (nums[left] > target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            } else {
                // nums[mid] < target
                if (nums[right] == target) {
                    return true;
                } else if (nums[right] > target) {
                    left = mid + 1;
                } else {
                    if (nums[right] > nums[mid]) {
                        right = mid - 1;
                    } else if (nums[right] == nums[mid]) {
                        for (int i = left; i <= right; ++i) {
                            if (nums[i] == target) {
                                return true;
                            }
                        }
                        return false;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};
