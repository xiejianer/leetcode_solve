class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) return len;
        int idx = -1;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != val) {
                nums[++idx] = nums[i];
            }
        }
        return idx + 1;
    }
};
