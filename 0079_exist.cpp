class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<int, int> um;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (solve(board, word, um, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool solve(const vector<vector<char>>& board, const string& word, unordered_map<int, int>& um, int row, int col, int idx) {
        if (idx == word.size()) return true;
        if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0) return false;
        if (um[row * board[0].size() + col] == 1 || board[row][col] != word[idx]) return false;
        um[row * board[0].size() + col] = 1;
        if (solve(board, word, um, row + 1, col, idx + 1)) return true;
        if (solve(board, word, um, row - 1, col, idx + 1)) return true;
        if (solve(board, word, um, row, col + 1, idx + 1)) return true;
        if (solve(board, word, um, row, col - 1, idx + 1)) return true;
        um[row * board[0].size() + col] = 0;
        return false;
    }
};
