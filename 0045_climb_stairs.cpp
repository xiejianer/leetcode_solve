class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        vector<int> steps(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            steps[i] = i;
        }
        int last_update = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int max_pos = (i + nums[i] + 1 > nums.size()) ? nums.size(): i + nums[i] + 1;
            if (max_pos - 1 < last_update) continue;
            for (int j = last_update + 1; j < max_pos; ++j) {
                steps[j] = min(steps[j], steps[i] + 1);
            }
            last_update = max_pos - 1;
        }
        return steps[nums.size() - 1];
    }
};
