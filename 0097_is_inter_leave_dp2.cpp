class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0) return true;
        if (s1.size() == 0 && s2 == s3) return true;
        if (s2.size() == 0 && s1 == s3) return true;
        if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0) return false;
        if (s1.size() + s2.size() != s3.size()) return false;
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            if(s1[i] == s3[n + i]) {
                dp[i][n] = 1;
            } else {
                break;
            }
        }
        for (int j = n - 1; j >= 0; --j) {
            if (s2[j] == s3[m + j]) {
                dp[m][j] = 1;
            } else {
                break;
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s1[i] == s3[i + j] && dp[i + 1][j] == 1) {
                    dp[i][j] = 1;
                } else if (s2[j] == s3[i + j] && dp[i][j + 1] == 1){
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }
};
