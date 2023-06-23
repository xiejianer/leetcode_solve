class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0;
        int right = matrix[0].size() - 1;
        int height = matrix.size();
        int row = 0;
        while (left <= right && row < height) {
            cout << "left 2 right" << endl;
            for (int i = left; i <= right; ++i) {
                cout << matrix[row][i] << endl;
                res.push_back(matrix[row][i]);
            }
            cout << "upper 2 low" << endl;
            for (int i = row + 1; i < height - 1; ++i) {
                cout << matrix[i][right] << endl;
                res.push_back(matrix[i][right]);
            }
            if (height - 1 > row) {
                cout << "right 2 left" << endl;
                for (int i = right; i >= left; --i) {
                    cout << matrix[height - 1][i] << endl;
                    res.push_back(matrix[height - 1][i]);
                }
            }
            cout << "lower 2 upper" << endl;
            if (left < right) {
                for (int i = height - 2; i > row; --i) {
                    cout << matrix[i][left] << endl;
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
            row++;
            right--;
            height--;
        }
        return res;
    }
};
