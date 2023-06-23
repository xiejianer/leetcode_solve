class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if (len == 0) return;
        for (int i = 0; i < len - 1; ++i) {
            for (int j = 0; j < len - i - 1; ++j) {
                swap(matrix[i][j], matrix[len - j - 1][len - i - 1]);
            }
        }
        for (int i = 0; i < len / 2; ++i) {
            for (int j = 0; j < len; ++j) {
                swap(matrix[i][j], matrix[len - i - 1][j]);
            }
        }
        return;
    }
};

