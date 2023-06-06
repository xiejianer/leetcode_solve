#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int digit = num / 1000;
        while (digit > 0) {
            res += "M";
            --digit;
        }
        num %= 1000;
        digit = num / 100;
        if (digit == 9) {
            res += "CM";
        } else if (digit == 4) {
            res += "CD";
        } else if (digit > 4) {
            res += "D";
            digit -= 5;
            while (digit > 0) {
                res += "C";
                --digit;
            }
        } else if (digit > 0) {
            while (digit > 0) {
                res += "C";
                --digit;
            }
        }
        num %= 100;
        digit = num / 10;
        if (digit == 9) {
            res += "XC";
        } else if (digit == 4) {
            res += "XL";
        } else if (digit > 4) {
            res += "L";
            digit -= 5;
            while (digit > 0) {
                res += "X";
                --digit;
            }
        } else if (digit > 0) {
            while (digit > 0) {
                res += "X";
                --digit;
            }
        }
        num %= 10;
        digit = num;
        if (digit == 9) {
            res += "IX";
        } else if (digit == 4) {
            res += "IV";
        } else if (digit > 4) {
            res += "V";
            digit -= 5;
            while (digit > 0) {
                res += "I";
                --digit;
            }
        } else if (digit > 0) {
            while (digit > 0) {
                res += "I";
                --digit;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string res = s.intToRoman(1994);
    cout << res << endl;
     res = s.intToRoman(3);
    cout << res << endl;
     res = s.intToRoman(4);
    cout << res << endl;
     res = s.intToRoman(9);
    cout << res << endl;
     res = s.intToRoman(58);
    cout << res << endl;
    return 0;
}
