class Solution {
public:
    string replaceSpace(string s) {
        string s1;
        for(size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s1 += "%20";
            } else {
                s1 += s[i];
            }
        }
        return s1;
    }
};
