#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int max_num = (1 << 31) - 1;
        if (x < 0 && x == max_num * (-1) - 1) return 0;
        int flag = 1;
        if (x < 0) {
            flag = - 1;
            x = -x;
        }
        if (x < 10) {
            return x * flag;
        }
        int res = x % 10;
        x = x / 10;
        int num = 0;
        while (x >= 10) {
            res = res * 10;
            res = res + x % 10;
            x /= 10;
        }
        if (flag > 0) {
            if ((max_num - x) / 10 < res) {
                return 0;
            }
        } else {
            if ((max_num - x + 1) / 10 < res) {
                return 0;
            }
        }
        res = res * 10 + x;
        return res * flag
    }
};

int main()
{
    Solution s;
    int a = s.reverse(12340);
    cout << a << endl;
    return 0;
}
