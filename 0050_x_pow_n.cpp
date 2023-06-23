class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            if (n == 0) return 1;
            else return 0;
        }
        if (n == 1) return x;
        if (n == 0) return 1;
        int flag = 1;
        int extra = 0;
        if (n < 0) {
            flag = 0;
            if (n == INT_MIN) {
                n = INT_MAX;
                extra = 1;
            } else {
                n = -n;
            }
        }
        double res = 0;
        if (n % 2 == 0) {
            res = myPow(x, n / 2);
            res *= res;
        }
        else {
            res = myPow(x, (n - 1) / 2);
            res *= res;
            res *= x;
        }
        if (extra) {
            res *= x;
        }
        if (flag) return res;
        return 1.0 / res;
    }
};
