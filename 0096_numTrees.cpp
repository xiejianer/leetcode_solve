class Solution {
public:
    int numTrees(int n) {
        int res = 0;
        solve(n, res);
        return res;
    }
    void solve(int n, int& res) {
        unordered_map<int, int> um;
        for (int i = 1; i < n + 1; ++i) {
            res += bst(i - 1, um) * bst(n - i, um);
        }
        return;
    }
    int bst(int i, unordered_map<int, int>& um) {
        if (i == 0 || i == 1) return 1;
        if (um.find(i) != um.end()) return um[i];
        int num = 0;
        for (int j = 1; j < i + 1; ++j) {
            num += bst(j - 1, um) * bst(i - j, um);
        }
        um[i] = num;
        return num;
    }
};
