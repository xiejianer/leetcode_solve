class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return true;
        int max_len = nums[0];
        int start_point = 1;
        while (max_len < nums.size() - 1) {
            int jumps = max_len;
            for (int i = start_point; i <= max_len; ++i) {
                if (i + nums[i] > jumps) {
                    jumps = i + nums[i];
                }
            }
            if (jumps == max_len) return false;
            start_point = max_len;
            max_len = jumps;
        }
        return true;
    }
};
