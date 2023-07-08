class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        solve(res, vec, 1, k, n);
        return res;
    }
    void solve(vector<vector<int>>& res, vector<int>& vec, int pos, int k, int n) {
        //cout << "invoke solve：" << "pos = " << pos << "\t k = " << k << "\tn = " << n << endl;
        if (vec.size() == k) {
            res.push_back(vec);
            return;
        }
        for (int i = pos; i <= n; ++i) {
            vec.push_back(i);
            solve(res, vec, i + 1, k, n);
            vec.pop_back();
        }
        return;
    }
};

