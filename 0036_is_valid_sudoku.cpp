class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //vector<vector<int>> vec(9, vector<int>(9, 0));
        for (int i = 0; i < board.size(); ++i) {
            vector<int> vec(10, 0);
            for (int j = 0; j < board[0].size(); ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                if (vec[c - '0'] != 0) return false;
                vec[c - '0'] = 1;
            }
        }
        for (int j = 0; j < board[0].size(); ++j) {
            vector<int> vec(10, 0);
            for (int i = 0; i < board.size(); ++i) {
                char c = board[i][j];
                if (c == '.') continue;
                if (vec[c - '0'] != 0) return false;
                vec[c - '0'] = 1;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<int> vec(10, 0);
                for (int k = 0; k < 9; ++k) {
                    char c = board[i + k / 3][j + k % 3];
                    if (c == '.') continue;
                    if (vec[c - '0'] == 1) return false;
                    vec[c - '0'] = 1;
                }
            }
        }
        return true;
    }
};
