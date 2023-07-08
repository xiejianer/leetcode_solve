class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        if (nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        solve(res, path, nums, 0);
        return res;
    }
    void solve(vector<vector<int>>& res, vector<int>& path, const vector<int>& nums, int idx) {
        res.push_back(path);
        if (idx >= nums.size()) return;
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            solve(res, path, nums, i + 1);
            path.pop_back();
        }
        return;
    }
};
