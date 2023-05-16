#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 1) return s;
        int n = s.size();
        int left = 0, maxlen = 1;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            if (i < n - 1 && s[i]==s[i + 1]) {
                dp[i][i + 1] = 1;
                left = i;
                maxlen = 2;
            }
        }
        for (int i = n - 3; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                if (dp[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    if (j - i + 1 > maxlen) {
                        left = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(left, maxlen);
    }
};
