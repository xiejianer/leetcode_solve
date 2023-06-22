class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> freq;
        vector<int> path;
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        int prev = -1;
        for (int i = 0; i < candidates.size(); ++i) {
            freq[candidates[i]]++;
            if (candidates[i] != prev) {
                vec.push_back(candidates[i]);
                prev = candidates[i];
            }
        }
        dfs(res, vec, path, target, 0, freq);
        return res;
    }
    void dfs(vector<vector<int>>& res, const vector<int>& vec, vector<int>& path, int target, int index, unordered_map<int, int> freq) {
        if (target == 0) {
            //cout << "----------------win--------------" << endl;
            res.push_back(path);
            return;
        }
        if (index >= vec.size() || target < 0 || vec[index] > target) {
            return;
        }
        for (int i = 0; i <= freq[vec[index]]; ++i) {
            //cout << "num: " << vec[index] << "\tfreq: " << i << endl;
            for (int k = 1; k * vec[index] <= target, k <= i; ++k) {
                path.push_back(vec[index]);
                target -= vec[index];
            }
            dfs(res, vec, path, target, index + 1, freq);
            for (int k = 1; k * vec[index] <= target, k <= i; ++k) {
                path.pop_back();
                target += vec[index];
            }
        }
    }
};
