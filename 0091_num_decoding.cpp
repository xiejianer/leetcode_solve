class Solution {
public:
    int numDecodings(string s) {
        int cnt = 0;
        if (s.size() < 1) return cnt;
        dfs(s, 0, cnt);
        return cnt;
    }
    void dfs(const string& s, int idx, int& cnt) {
        if (idx == s.size()) {
            ++cnt;
            return;
        }
        for (int i = idx; i < idx + 2; ++i) {
            if (i >= s.size()) continue;
            if (s[idx] == '0') return;
            int num = stoi(s.substr(idx, i - idx + 1));
            if (num > 0 && num < 27) {
                dfs(s, i + 1, cnt);
            }
        }
        return;
    }
};
