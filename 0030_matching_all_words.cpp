// OOM

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() < words[0].size() * words.size()) return res;
        for (int i = 0; i <= s.size() - words[0].size() * words.size(); ++i) {
            solve(s, words, res, i, i);
        }
        return res;
    }
    void solve(string s, const vector<string>& words, vector<int>& res, int pivot, int idx) {
        if (words.size() == 0) {
            if (res.size() == 0 || (res.size() != 0 && res[res.size() - 1] != pivot)) {
                res.push_back(pivot);
            }
            return;
        }
        if (idx >= s.size() || idx + words[0].size() > s.size()) {
            return;
        }
        for (int i = 0; i < words.size(); ++i) {
            bool flag = true;
            for (int j = 0; j < words[i].size(); ++j) {
                    if (words[i][j] != s[idx + j]) {
                        flag = false;
                        break;
                    }
            }
            if (flag) {
                vector<string> vec;
                int j = 0;
                while (j < words.size()) {
                    if (j != i) {
                        vec.push_back(words[j]);
                    }
                    ++j;
                }
                solve(s, vec, res, pivot, idx + words[0].size());
            }
        }
    }
};



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() < words[0].size() * words.size()) return res;
        unordered_map<string, int> um1, um2;
        for (int i = 0; i < words.size(); ++i) {
            um1[words[i]] += 1;
            um2[words[i]] += 1;
        }
        for (int i = 0; i <= s.size() - words[0].size(); ++i) {
            int left = i;
            int match_total = words.size();
            int match_cnt = 0;
            while (left < s.size()) {
                string str = s.substr(left, words[0].size());
                if (um1.find(str) == um1.end() || um1[str] == 0) {
                    break;
                }
                --um1[str];
                ++match_cnt;
                if (match_cnt == match_total) {
                    break;
                }
                left += words[0].size();
            }
            um1 = um2;
            if (match_cnt == match_total) {
                res.push_back(i);
            }
        }
        return res;
    }
};
