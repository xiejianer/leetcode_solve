class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> path;
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(res, nums, path, used);
        return res;
    }
    void dfs(vector<vector<int>>& res, const vector<int>& nums, vector<int>& path, vector<int>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] != 0) continue;
            if (i != 0 && used[i - 1] == 0 && nums[i] == nums[i - 1]) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            dfs(res, nums, path, used);
            used[i] = 0;
            path.pop_back();
        }
        return;
    }
};
