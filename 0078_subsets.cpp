class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        solve(res, vec, 0, nums);
        return  res;
    }
    void solve(vector<vector<int>>& res, vector<int>& vec, int pos, const vector<int>& nums) {
        res.push_back(vec);
        for (int i = pos; i < nums.size(); ++i) {
            vec.push_back(nums[i]);
            solve(res, vec, i + 1, nums);
            vec.pop_back();
        }
        return;
    }
};
