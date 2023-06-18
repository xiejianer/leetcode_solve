class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() < words[0].size() * words.size()) return res;
        int m = words[0].size();
        int n = words.size();
        int ls = s.size();
        for (int i = 0; i < m && i + m * n <= ls; ++i) {
            unordered_map<string, int> um;
            for (int j = 0; j < n; ++j) {
                um[s.substr(i + j * m, m)] += 1;
            }
            for (int j = 0; j < n; ++j) {
                if (--um[words[j]] == 0) {
                    um.erase(words[j]);
                }
            }
            for (int left = i; left + m * n < ls + 1; left += m) {
                if (left != i) {
                    string word = s.substr(left + (n - 1) * m, m);
                    if (++um[word] == 0) {
                        um.erase(word);
                    }
                    word = s.substr(left - m, m);
                    if (--um[word] == 0) {
                        um.erase(word);
                    }
                }
                if (um.empty()) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};
