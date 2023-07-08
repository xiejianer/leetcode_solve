class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0) return true;
        if (s1.size() == 0 && s2 == s3) return true;
        if (s2.size() == 0 && s1 == s3) return true;
        if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0) return false;
        unordered_map<string, int> um;
        if (s3[0] == s1[0] && s3[0] != s2[0]) return ismatch(s1, s2, s3, um);
        if (s3[0] == s2[0] && s3[0] != s1[0]) return ismatch(s2, s1, s3, um);
        if (s3[0] == s1[0] && s3[0] == s2[0]) return (ismatch(s1, s2, s3, um) || ismatch(s2, s1, s3, um));
        return false;
    }
    bool ismatch(string s1, string s2, string s3, unordered_map<string, int>& um) {
        //cout << "matching s1: " << s1 << "\ts2: " << s2 <<  "\ts3: " << s3 << endl;
        if (um.find(s1 + "_" + s2 + "_" + s3) != um.end()) {
            return um[s1 + "_" + s2 + "_" + s3];
        }
        if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0) {
            um[s1 + "_" + s2 + "_" + s3] = 1;
            return true;
        }
        if (s1.size() == 0 && s2 == s3) {
            um[s1 + "_" + s2 + "_" + s3] = 1;
            return true;
        }
        if (s2.size() == 0 && s1 == s3) {
            um[s1 + "_" + s2 + "_" + s3] = 1;
            return true;
        }
        if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0) {
            um[s1 + "_" + s2 + "_" + s3] = 0;
            return false;
        }
        int len = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s3[i]) {
                ++len;
            } else {
                break;
            }
        }
        if (len == 0) {
            um[s1 + "_" + s2 + "_" + s3] = 0;
            return false;
        }
        for (int i = 1; i < len + 1; ++i) {
            if (ismatch(s2, s1.substr(i), s3.substr(i), um)) {
                um[s1 + "_" + s2 + "_" + s3] = 1;
                um[s2 + "_" + s1.substr(i) + "_" + s3.substr(i)] = 1;
                return true;
            }
        }
        um[s1 + "_" + s2 + "_" + s3] = 0;
        return false;
    }
};
