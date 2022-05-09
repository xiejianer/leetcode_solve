#include <iostream>
#include <unordered_map>

class Solution {
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = s.size();
        if (len < 2) {
            return len;
        }
        unordered_map<char, int> um;
        int left = 0, right = 0;
        um[s[0]] = 1; // store pos + 1
        int tmp = right - left + 1;
        if (tmp > res) {
            res = tmp;
        }
        for (int i = 1; i < len; ++i) {
            if (um.find(s[i]) != um.end() && um[s[i]] != 0) {
                tmp = right - left + 1;
                if (tmp > res) {
                    res = tmp;
                }
                int j = 0;
                for (j = left; j < um[s[i]]; ++j) {
                    um[s[j]] = 0;
                }
                left = j;
            }
            right = i;
            um[s[i]] = i + 1;
        }
        tmp = right - left + 1;
        if (tmp > res) {
            res = tmp;
        }
        return res;
    }
};
