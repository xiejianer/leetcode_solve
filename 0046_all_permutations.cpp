class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> used(nums.size(), 0);
        vector<int> path;
        dfs(res, path, used, nums);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& used, const vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == 0) {
                used[i] = 1;
                path.push_back(nums[i]);
                dfs(res, path, used, nums);
                path.pop_back();
                used[i] = 0;
            }
        }
        return;
    }
};
