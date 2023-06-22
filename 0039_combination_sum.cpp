class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sum;
        vector<vector<int>> res;
        dfs(candidates, res, sum, target, 0);
        return res;
    }
    void dfs(const vector<int>& candidates, vector<vector<int>>& res, vector<int>& sum, int target, int index) {
        if (target == 0) {
            res.push_back(sum);
            return;
        }
        if (index >= candidates.size()) {
            return;
        }
        for (int i = 0; i * candidates[index] <= target; ++i) {
            for (int j = 1; j <= i; ++j) {
                sum.push_back(candidates[index]);
                target -= candidates[index];
            }
            dfs(candidates, res, sum, target, index + 1);
            for (int j = 1; j <= i; ++j) {
                sum.pop_back();
                target += candidates[index];
            }
        }
    }
};
