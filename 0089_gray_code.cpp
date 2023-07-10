class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        vector<vector<int>> vec;
        vec.push_back(vector<int>(n, 0));
        int total = (1 << n);
        unordered_map<int, int> um;
        um[0] = 1;
        solve(res, vec, 1, total, um);
        return res;
    }
    int solve(vector<int>& res, vector<vector<int>>& vec, int cnt, int total, unordered_map<int, int>& um) {
        if (cnt == total) {
            if (checkdiff(vec[0], vec[total - 1]) == 1) {
                get_result(res, vec);
                return 0;
            }
            return -1;
        }
        for (int i = 0; i < total; ++i) {
            vector<int> tmp = vec[cnt - 1];
            tmp[i] ^= 1;
            int num = binvec2int(tmp);
            if (um[num] == 1) {
                continue;
            } else {
                um[num] = 1;
                vec.push_back(tmp);
                if (solve(res, vec, cnt + 1, total, um) == 0) {
                    return 0;
                }
                um[num] = 0;
                vec.pop_back();
            }
        }
        return 0;
    }
    int binvec2int(const vector<int>& vec) {
        int res = 0;
        for (int i = 0; i < vec.size(); ++i) {
            res = res * 2 + vec[i];
        }
        return res;
    }

    int checkdiff(const vector<int>& vec1, const vector<int>& vec2) {
        int cnt = 0;
        for (int i = 0; i < vec1.size(); ++i) {
            if (vec1[i] != vec2[i]) ++cnt;
        }
        if (cnt != 1) return 0;
        return 1;
    }

    void get_result(vector<int>& res, const vector<vector<int>>& vec) {
        for (auto item: vec) {
            int ins = 0;
            for (auto num: item) {
                ins = ins * 2 + num;
            }
            res.push_back(ins);
        }
        return;
    }
};

