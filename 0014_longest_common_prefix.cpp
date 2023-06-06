#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1) return "";
        string res = "";
        int idx = 0;
        bool match = true;
        while (idx < strs[0].size()) {
            char pivot = strs[0][idx];
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i][idx] != pivot) {
                    match = false;
                    break;
                }
            }
            if (! match) {
                break;
            }
            ++idx;
        }
        res = strs[0].substr(0, idx);
        return res;
    }
};

int main()
{
    return 0;
}
