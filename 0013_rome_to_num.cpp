#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char ,int> um;
        um['M'] = 1000;
        um['D'] = 500;
        um['C'] = 100;
        um['L'] = 50;
        um['V'] = 5;
        int res = 0;
        int idx = 0;
        int len = s.size();
        while (idx < len) {
            if (s[idx] == 'M' || s[idx] == 'D' || s[idx] == 'L' || s[idx] == 'V') {
                res += um[s[idx]];
                ++idx;
            }
            else if (s[idx] == 'C') {
                if (idx + 1 < len) {
                    if (s.substr(idx, 2) == "CM") {
                        res += 900;
                        idx += 2;
                    } else if (s.substr(idx, 2) == "CD") {
                        res += 400;
                        idx += 2;
                    } else {
                        res += 100;
                        idx += 1;
                    }
                } else {
                    res += 100;
                    idx += 1;
                }
            } else if (s[idx] == 'X') {
                if (idx + 1 < len) {
                    if (s.substr(idx, 2) == "XL") {
                        res += 40;
                        idx += 2;
                    } else if (s.substr(idx, 2) == "XC") {
                        res += 90;
                        idx += 2;
                    } else {
                        res += 10;
                        idx += 1;
                    }
                } else {
                    res += 10;
                    idx += 1;
                }
            } else if (s[idx] == 'V') {
                res += 5;
                idx += 1;
            } else {
                if (idx + 1 < len) {
                    if (s.substr(idx, 2) == "IV") {
                        res += 4;
                        idx += 2;
                    } else if (s.substr(idx, 2) == "IX") {
                        res += 9;
                        idx += 2;
                    } else {
                        res += 1;
                        idx += 1;
                    }
                } else {
                    res += 1;
                    idx += 1;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("IX") << endl;
    cout << s.romanToInt("LVIII") << endl;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}
