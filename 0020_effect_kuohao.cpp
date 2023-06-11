#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i = 0;
        char top_c = '(';
        while (i < s.size()) {
            if (stk.size() == 0) {
                stk.push(s[i++]);
                continue;
            }
            top_c = stk.top();
            if (top_c == '(' || top_c == '{' || top_c == '[') {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    stk.push(s[i]);
                } else {
                    if (top_c == '(' && s[i] == ')') {
                        stk.pop();
                    } else if (top_c == '[' && s[i] == ']') {
                        stk.pop();
                    } else if (top_c == '{' && s[i] == '}') {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            } else {
                return false;
            }
            ++i;
        }
        if (stk.size() != 0) {
            return false;
        }
        return true;
    }
};


int  main()
{
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    Solution s;
    cout << s.isValid(s1) << endl;
    cout << s.isValid(s2) << endl;
    cout << s.isValid(s3) << endl;
    return 0;
}
