class Solution {
public:
    int climbStairs(int n) {
        int dp_0 = 0;
        int dp_1 = 1;
        int dp_2 = 0;
        for (int i = 1; i < n + 1; ++i) {
            dp_2 = dp_1 + dp_0;
            dp_0 = dp_1;
            dp_1 = dp_2;
        }
        return dp_2;
    }
};
