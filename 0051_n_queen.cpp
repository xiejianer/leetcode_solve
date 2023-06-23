class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution;
        vector<int> col(n + 1, 0);
        vector<int> xyplus(2 * n + 1, 0);
        vector<int> xyminus(2 * n + 1, 0);
        dfs(res, solution, 1, n, col, xyplus, xyminus);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& solution, int row, int n, vector<int>& col, vector<int>& xyplus, vector<int>& xyminus) {
        if (row == n + 1) {
            res.push_back(solution);
            return;
        }
        for (int i = 1; i < n + 1; ++i) {
            if (col[i] == 1 || xyplus[row + i] == 1 || xyminus[i - row + n] == 1) continue;
            col[i] = 1;
            xyplus[row + i] = 1;
            xyminus[i - row + n] = 1;
            string s = "";
            for (int j = 1; j <= n; ++j) {
                if (j != i) {
                    s += ".";
                } else {
                    s += "Q";
                }
            }
            solution.push_back(s);
            dfs(res, solution, row + 1, n, col, xyplus, xyminus);
            solution.pop_back();
            col[i] = 0;
            xyplus[row + i] = 0;
            xyminus[i - row + n] = 0;
        }
        return;
    }
};
控制台

