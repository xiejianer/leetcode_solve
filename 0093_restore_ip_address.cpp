class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4) return res;
        vector<string> path;
        solve(res, path, s, 0);
        return res;
    }
    void solve(vector<string>& res, vector<string>& path, const string& s, int idx) {
        if (idx >= s.size()) {
            if (path.size() == 4) {
                string tmp = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
                res.push_back(tmp);
            }
            return;
        }
        for (int i = idx; i < idx + 3; ++i) {
            if (i >= s.size()) continue;
            string tmp = s.substr(idx, i - idx + 1);
            int num = stoi(tmp);
            if (num >= 0 && num < 256) {
                path.push_back(tmp);
                solve(res, path, s, i + 1);
                path.pop_back();
                if (s[idx] == '0') break;
            }
        }
        return;
    }
};
