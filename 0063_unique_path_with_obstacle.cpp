class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        bool flag = 0;
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                flag = 1;
            }
            if (flag) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
        flag = 0;
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) {
                flag = 1;
            }
            if (flag) {
                dp[0][j] = 0;
            } else {
                dp[0][j] = 1;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
