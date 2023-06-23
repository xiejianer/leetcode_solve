class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int current = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (current > 0) {
                current += nums[i];
            }
            else {
                current = nums[i];
            }
            if (current > res) {
                res = current;
            }
        }
        return res;
    }
};
