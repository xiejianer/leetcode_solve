class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n, 0));
        int left = 0;
        int right = n - 1;
        int height = n - 1;
        int row = 0;
        int num = 1;
        while (left <= right) {
            for (int i = left; i <= right; ++i) {
                vec[row][i] = num;
                cout << num << endl;
                ++num;
            }
            for (int i = row + 1; i < height; ++i) {
                vec[i][right] = num;
                cout << num << endl;
                ++num;
            }
            if (row < height) {
                for (int i = right; i >= left; --i) {
                    vec[height][i] = num;
                    cout << num << endl;
                    ++num;
                }
            }
            if (left < right) {
                for (int i = height - 1; i > row; --i) {
                    vec[i][left] = num;
                    cout << num << endl;
                    ++num;
                }
            }
            left++;
            right--;
            row++;
            height--;
        }
        return vec;
    }
};
