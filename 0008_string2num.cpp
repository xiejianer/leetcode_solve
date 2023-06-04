#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        int label = 1;
        while (idx < s.size()) {
            if (s[idx] == ' ') {
                ++idx;
                continue;
            }
            else if (s[idx] == '+') {
                ++idx;
                break;
            }
            else if (s[idx] == '-') {
                label = -1;
                ++idx;
                break;
            }
            else if (s[idx] >= '0' && s[idx] <= '9') {
                break;
            }
            else {
                return 0;
            }
        }
        int curr = 0;
        int num = 0;
        if (label == 1) {
            while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
                num = s[idx] - '0';
                if (curr <= (INT_MAX - num) / 10) {
                    curr = curr* 10 + num;
                    ++idx;
                }
                else {
                    curr = INT_MAX;
                    break;
                }
            }
        }
        else if (label == -1) {
            while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
                num = s[idx] - '0';
                if (curr >= (INT_MIN + num) / 10) {
                    curr = curr * 10 - num;
                    ++idx;
                }
                else {
                    curr = INT_MIN;
                    break;
                }
            }
        }
        return curr;
    }
};

int main()
{
    Solution s;
    string s1 = "    +123abc";
    auto res = s.myAtoi(s1);
    cout << res << endl;
    return 0;
}
