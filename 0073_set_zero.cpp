class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_zero = 0;
        int col_zero = 0;
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col_zero = 1;
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                row_zero = 1;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row_zero == 1) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col_zero == 1) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        return;
    }
};
