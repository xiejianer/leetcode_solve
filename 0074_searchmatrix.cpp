iclass Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int len = m * n;
        int pos = left_bound(matrix, 0, len, target);
        if (pos < len && matrix[pos / n][pos % n] == target) return true;
        return false;
    }
    int left_bound(const vector<vector<int>>& matrix, int idx1, int idx2, int target) {
        int mid = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while (idx1 < idx2) {
            mid = idx1 + (idx2 - idx1) / 2;
            if (target > matrix[mid / n][mid % n]) {
                idx1 = ++mid;
            } else {
                idx2 = mid;
            }
        }
        return idx1;
    }
};
