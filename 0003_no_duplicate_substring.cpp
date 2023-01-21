#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> valuePos;
        int left = 0; // 记录上次出现重复的位置信息
        int maxlen = -1; // 记录最大值
        for (int i = 0; i < s.size(); ++i) {
            if (valuePos[s[i]] != 0) {
                if (valuePos[s[i]] - 1 >= left) {
                    if (i - left > maxlen) {
                        maxlen = i - left;
                    }
                    left = valuePos[s[i]];
                }
            }
            valuePos[s[i]] = i + 1;
        }
        int len = int(s.size());
        if (len - left > maxlen) {
            maxlen = len - left;
        }
        return maxlen;
    }
};

int main()
{
    Solution s;
    string str = "";
    int len = s.lengthOfLongestSubstring(str);
    cout << len << endl;
    return 0;
}
