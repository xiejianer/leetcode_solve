class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size() == 0) {
            res.push_back(vector<string>{""});
            return res;
        }
        unordered_map<string, int> um;
        int count = 0;

        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if (um.find(strs[i]) == um.end()) {
                um[strs[i]] = count;
                ++count;
                res.push_back(vector<string>{s});
            } else {
                res[um[strs[i]]].push_back(s);
            }
        }

        return res;
    }
};
