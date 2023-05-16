#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> um;
        queue<char> q;
        for (int i = 0; i < s.size(); ++i) {
            if (um.find(s[i]) == um.end() || um[s[i]] == 0) {
                um[s[i]] = 1;
                q.push(s[i]);
            }
            else {
                if (q.size() > res) {
                    res = q.size();
                }
                while (q.front() != s[i]) {
                    um[q.front()] = 0;
                    q.pop();
                }
                q.pop();
                q.push(s[i]);
                um[s[i]] = 1;
            }
        }
        if (q.size() > res) {
            res = q.size();
        }
        return res;
    }
};

int main()
{
    string s = string("pwwkew");
    Solution s1;
    cout << s1.lengthOfLongestSubstring(s) << endl;
    return 0;
}
