class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> col(n + 1, 0);
        vector<int> xyplus(2 * n + 1, 0);
        vector<int> xyminus(2 * n + 1, 0);
        dfs(count, 1, n, col, xyplus, xyminus);
        return count;
    }
    void dfs(int& count, int row, int n, vector<int>& col, vector<int>& xyplus, vector<int>& xyminus) {
        if (row == n + 1) {
            ++count;
            return;
        }
        for (int i = 1; i < n + 1; ++i) {
            if (col[i] == 1 || xyplus[row + i] == 1 || xyminus[i - row + n] == 1) continue;
            col[i] = 1;
            xyplus[row + i] = 1;
            xyminus[i - row + n] = 1;
            dfs(count, row + 1, n, col, xyplus, xyminus);
            col[i] = 0;
            xyplus[row + i] = 0;
            xyminus[i - row + n] = 0;
        }
        return;
    }
};
