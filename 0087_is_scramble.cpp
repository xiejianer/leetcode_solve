class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string s11 = s1;
        string s22 = s2;
        sort(s11.begin(), s11.end());
        sort(s22.begin(), s22.end());
        if (s11 != s22) return false;
        unordered_map<string, int> um;
        return solve(s1, s2, um);
    }
    bool solve(const string& s1, const string& s2, unordered_map<string, int>& um) {
        if (s1 == s2) {
            um[s1 + "_" + s2] = 1;
            return true;
        }
        if (s1.size() < 2) {
            if (s1 == s2) {
               um[s1 + "_" + s2] = 1;
                return true;
            }
            um[s1 + "_" + s2] = 0;
            return false;
        }
        if (um.find(s1 + "_" + s2) != um.end()) {
            return um[s1 + "_" + s2];
        }
        for (int i = 0; i < s1.size() - 1; ++i) {
            string s11 = s1.substr(0, i + 1);
            string s12 = s1.substr(s1.size() - i - 1);
            string s21 = s2.substr(0, i + 1);
            string s22 = s2.substr(s2.size() - i - 1);
            sort(s11.begin(), s11.end());
            sort(s21.begin(), s21.end());
            sort(s22.begin(), s22.end());
            if (s11 == s21) {
                bool b1 = false;
                if (um.find(s1.substr(0, i + 1) + "_" + s2.substr(0, i + 1)) != um.end()) {
                    b1 = um[s1.substr(0, i + 1) + "_" + s2.substr(0, i + 1)];
                } else {
                    b1 = solve(s1.substr(0, i + 1), s2.substr(0, i + 1), um);
                }
                bool b2 = false;
                if (um.find(s1.substr(i + 1) + "_" + s2.substr(i + 1)) != um.end()) {
                    b2 = um[s1.substr(i + 1) + "_" + s2.substr(i + 1)];
                } else {
                    b2 = solve(s1.substr(i + 1), s2.substr(i + 1), um);
                }
                if (b1 == true) {
                    um[s1.substr(0, i + 1) + "_" + s2.substr(0, i + 1)] = 1;
                } else {
                    um[s1.substr(0, i + 1) + "_" + s2.substr(0, i + 1)] = 0;
                }
                if (b2 == true) {
                    um[s1.substr(i + 1) + "_" +  s2.substr(i + 1)] = 1;
                } else {
                    um[s1.substr(i + 1) + "_" +  s2.substr(i + 1)] = 0;
                }
                if (b1 && b2) return true;
            }
            if (s11 == s22) {
                bool b1 = false;
                if (um.find(s1.substr(0, i + 1) + "_" +  s2.substr(s2.size() - i - 1)) != um.end()) {
                    b1 = um[s1.substr(0, i + 1) + "_" +  s2.substr(s2.size() - i - 1)];
                } else {
                    b1 = solve(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1), um);
                }
                bool b2 = false;
                if (um.find(s2.substr(0, s2.size() - i - 1) + "_" + s1.substr(i + 1)) != um.end()) {
                    b2 = um[s2.substr(0, s2.size() - i - 1) + "_" + s1.substr(i + 1)];
                } else {
                    b2 = solve(s2.substr(0, s2.size() - i - 1), s1.substr(i + 1), um);
                }
                if (b1 == true) {
                    um[s1.substr(0, i + 1) + "_" + s2.substr(s2.size() - i - 1)] = 1;
                } else {
                     um[s1.substr(0, i + 1) + "_" + s2.substr(s2.size() - i - 1)] = 0;
                }
                if (b2 == true) {
                    um[s2.substr(0, s2.size() - i - 1) + "_" + s1.substr(i + 1)] = 1;
                } else {
                    um[s2.substr(0, s2.size() - i - 1) + "_" + s1.substr(i + 1)] = 0;
                }
                if (b1 && b2) return true;
            }
        }
        return false;
    }
};
