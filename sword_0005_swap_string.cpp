class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res;
        for (size_t i = n; i < s.size(); ++i) {
            res += s[i];
        }
        for (int i = 0; i < n; ++i) {
            res += s[i];
        }
        return res;
    }
};
