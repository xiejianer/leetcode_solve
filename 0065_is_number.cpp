class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        if (len == 0) return false;
        int i = 0;
        int has_flag = 0;
        if (s[0] == '+' || s[0] == '-') {
            ++i;
            has_flag = 1;
        }
        int has_dot = len;
        int has_e = len;
        for (int idx = i; idx < len; ++idx) {
            if (s[idx] == '.') {
                if (has_dot != len) return false;
                has_dot = idx;
            }
            if (s[idx] == 'e' || s[idx] == 'E') {
                if (has_e != len) return false;
                has_e = idx;
            }
        }
        if (has_flag == has_e || has_e == len - 1) {
            return false;
        }
        if (has_dot != len && has_dot > has_e) return false;
        int has_digit = 0;
        if (has_dot == len) {
            for (int idx = has_flag; idx < has_e; ++idx) {
                if (!(s[idx] >= '0' && s[idx] <= '9')) {
                    return false;
                }
                has_digit = 1;
            }
            if (has_digit == 0) return false;
            if (has_e + 1 < len && (s[has_e + 1] == '+' || s[has_e + 1] == '-')) {
                has_e++;
                has_digit = 0;
            }
            for (int idx = has_e + 1; idx < len; ++idx) {
                if (!(s[idx] >= '0' && s[idx] <= '9')) {
                    return false;
                }
                has_digit = 1;
            }
            if (has_digit == 0) return false;
            return true;
        }
        has_digit = 0;
        if (has_dot == has_flag) {
            for (int idx = has_dot + 1; idx < has_e; ++idx) {
                if (!(s[idx] >= '0' && s[idx] <= '9')) {
                    return false;
                }
                has_digit = 1;
            }
            if (has_digit != 1) return false;
            if (has_e + 1 < len && (s[has_e + 1] == '+' || s[has_e + 1] == '-')) {
                has_e++;
                has_digit = 0;
            }
            for (int idx = has_e + 1; idx < len; ++idx) {
                if (!(s[idx] >= '0' && s[idx] <= '9')) {
                    return false;
                }
                has_digit = 1;
            }
            if (has_digit != 1) return false;
            return true;
        }
        has_digit = 0;
        for (int idx = has_flag; idx < has_dot; ++idx) {
            if (!(s[idx] >= '0' && s[idx] <= '9')) {
                return false;
            }
            has_digit = 1;
        }
        if (has_digit != 1) return false;
        for (int idx = has_dot + 1; idx < has_e; ++idx) {
            if (!(s[idx] >= '0' && s[idx] <= '9')) {
                return false;
            }
        }
        if (has_e + 1 < len && (s[has_e + 1] == '+' || s[has_e + 1] == '-')) {
            has_e++;
            has_digit = 0;
        }
        for (int idx = has_e + 1; idx < len; ++idx) {
            if (!(s[idx] >= '0' && s[idx] <= '9')) {
                return false;
            }
            has_digit = 1;
        }
        if (has_digit != 1) return false;
        return true;
    }
};
