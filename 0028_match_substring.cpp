class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        for (int i = 0; i <= len1 - len2; ++i) {
            bool match = true;
            cout << "i = " << i << endl;
            for (int j = 0; j < len2; ++j) {
                cout << "matching: " << haystack[i + j] << "\t == " << needle[j] << endl;
                if (needle[j] != haystack[i + j]) {
                    match = false;
                    break;
                }
            }
            cout << "i = " << i << "\tmatch: " << match << endl;
            if (match) {
                return i;
            }
        }
        return -1;
    }
};
