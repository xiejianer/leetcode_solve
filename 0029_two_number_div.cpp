class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
            if (divisor == 1) {
                return INT_MIN;
            }
        }
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int flag = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            flag = -1;
        }
        if (dividend > 0) {
            dividend = -dividend;
        }
        if (divisor > 0) {
            divisor = -divisor;
        }
        auto checkEqual = [](int divisor, int mid, int dividend) {
            int flag = 0;
            int result = 0;
            int add = divisor;
            while (mid > 0) {
                if (mid & 1) {
                    if (result < dividend - add) {
                        return 1;
                    }
                    if (result == dividend - add) {
                        return 0;
                    }
                    result += add;
                }
                if (mid != 1) {
                    if (add < dividend - add) {
                        return 1;
                    }
                    add += add;
                }
                mid >>= 1;
            }
            return -1;
        };
        int left = 1;
        int right = INT_MAX;
        int check = 0;
        int ans = 0;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            check = checkEqual(divisor, mid, dividend);
            if (check == 0) {
                ans = mid;
                break;
            }
            else if (check > 0) {
                if (mid == INT_MAX) return mid;
                else {
                    right = mid - 1;
                }
            }
            else {
                ans = mid;
                left = mid + 1;
            }
        }
        return flag > 0 ? ans: -ans;
    }
};
