class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = missingNumberFunc(nums, 0, nums.size() - 1);
        return res;
    }
    int missingNumberFunc(const vector<int>& vec, int left, int right) {
        if (left > right) {
            return vec[left] - 1;
        }
        int mid = left + (right - left) / 2;
        if (vec[mid] == mid) {
            if (left == right) return mid + 1;
            return missingNumberFunc(vec, mid + 1, right);
        }
        if (vec[mid] > mid) {
            if (left == right) return mid;
            return missingNumberFunc(vec, left, mid - 1);
        }
        return 0;
    }
};
