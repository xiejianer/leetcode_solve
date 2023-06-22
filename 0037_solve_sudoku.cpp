#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> vec1(9, vector<int>(10, 0));
        vector<vector<int>> vec2(9, vector<int>(10, 0));
        vector<vector<int>> vec3(9, vector<int>(10, 0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '0';
                vec1[i][num] = 1;
                vec2[j][num] = 1;
                vec3[i / 3 * 3 + j / 3][num] = 1;
            }
        }
        dfs(board, 0, 0, vec1, vec2, vec3);
        return;
    }
    bool dfs(vector<vector<char>>& board,
             int row,
             int col,
             vector<vector<int>>& v1,
             vector<vector<int>>& v2,
             vector<vector<int>>& v3) {
        if (row == 9) {
            cout << "win" << endl;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    cout << board[i][j] << '\t';
                }
                cout << endl;
            }
            return true;
        }
        if (col == 9) {
            return dfs(board, row + 1, 0, v1, v2, v3);
        }
        if (board[row][col] != '.') return dfs(board, row, col + 1, v1, v2, v3);
        for (int i = 1; i < 10; ++i) {
            if (v1[row][i] == 1 || v2[col][i] == 1 || v3[row / 3 * 3 + col / 3][i] == 1) {
                continue;
            }
            board[row][col] = '0' + i;
            v1[row][i] = 1;
            v2[col][i] = 1;
            v3[row / 3 * 3 + col / 3][i] = 1;
            cout << "board[" << row << "][" << col << "] = " << board[row][col] << endl;
            if (dfs(board, row, col + 1, v1, v2, v3)) {
                return true;
            }
            cout << "回溯" << "board[" << row << "][" << col << "] = " << board[row][col] << endl;
            board[row][col] = '.';
            v1[row][i] = 0;
            v2[col][i] = 0;
            v3[row / 3 * 3 + col / 3][i] = 0;
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    Solution s;
    s.solveSudoku(board);
    return 0;
}
