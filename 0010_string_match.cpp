#include <iostream>
#include <string>
#include <unistd.h>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        cout << "s: " << s << "\tp: " << p << endl;
        if (s.size() == 0 && p.size() == 0) return true;
        if (s.size() != 0 && p.size() == 0) return false;
        if (s.size() == 0) {
            if (p.size() == 1) return false;
            if (p[1] == '*') {
                return isMatch(s, p.substr(2));
            }
            else {
                return false;
            }
        }
        if (cache.find(s + '_' + p) != cache.end()) {
            return cache[s + '_' + p];
        }
        if (s[0] == p[0]) {
            if (p.size() == 1) {
                if (s.size() == 1) return true;
                else {
                    return false;
                }
            } else {
                if (p[1] == '*') {
                    bool res = isMatch(s.substr(1), p) || isMatch(s.substr(1), p.substr(2)) || isMatch(s, p.substr(2));
                    cache[s + '_' + p] = res;
                    return res;
                } else {
                    bool res = isMatch(s.substr(1), p.substr(1));
                    cache[s + '_' + p] = res;
                    return res;
                }
            }
        } else {
            if (p[0] == '.') {
                bool res = false;
                if (p.size() == 1) {
                    if (s.size() != 1) {
                        res = false;
                    }
                    else {
                        res = true;
                    }
                } else {
                    if (p[1] == '*') {
                        res = isMatch(s.substr(1), p.substr(2)) || isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
                    } else {
                        res = isMatch(s.substr(1), p.substr(1));
                    }
                }
                cache[s + '_' + p] = res;
                return res;
            } else {
                bool res = false;
                if (p.size() > 1) {
                    if (p[1] == '*') {
                        res =  isMatch(s, p.substr(2));
                    } else {
                        res = false;
                    }
                } else {
                    res = false;
                }
                cache[s + '_' + p] = res;
                return res;
            }
        }
        return false;
    }
    map<string, bool> cache;
};

int main()
{
    Solution s;
    cout << s.isMatch("aaaaaaaaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*") << endl;
    return 0;
}
