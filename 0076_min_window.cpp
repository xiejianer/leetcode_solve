class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> um;
        unordered_map<char, int> window;
        for (auto c: t) {
            um[c]++;
        }
        int right = 0;
        int left = -1;
        int valid = 0;
        int min_len = s.size() + 1;
        queue<int> q;
        while (right < s.size()) {
            window[s[right]]++;
            if (um.find(s[right]) != um.end() && window[s[right]] == um[s[right]]) {
                ++valid;
            }
            q.push(right);
            while (valid >= um.size()) {
                int tmp_len = q.back() - q.front() + 1;
                if (tmp_len < min_len) {
                    min_len = tmp_len;
                    left = q.front();
                }
                int idx = q.front();
                window[s[idx]]--;
                if (um.find(s[idx]) != um.end() && window[s[idx]] < um[s[idx]]) {
                    --valid;
                }
                q.pop();
            }
            ++right;
        }
        if (left == -1) {
            return "";
        }
        return s.substr(left, min_len);
    }
};
