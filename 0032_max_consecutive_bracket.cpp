class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> s1;
        stack<char> s2;
        for (int i = 0; i < s.size(); ++i) {
            if (s1.size() == 0) {
                s1.push(s[i]);
            }
            else {
                if (s[i] == '(') {
                    s1.push(s[i]);
                } else {
                    while (s1.size() != 0 && s1.top() == '1') {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    if (s1.size() == 0) {
                        while (s2.size() != 0) {
                            s1.push(s2.top());
                            s2.pop();
                        }
                        s1.push(s[i]);
                    } else {
                        if (s1.top() == '(') {
                            s1.pop();
                            s1.push('1');
                            while (s2.size() != 0) {
                                s1.push(s2.top());
                                s2.pop();
                            }
                        }
                        else {
                            while (s2.size() != 0) {
                                s1.push(s2.top());
                                s2.pop();
                            }
                            s1.push(')');
                        }
                    }
                }
            }
        }
        int max_len = 0;
        int len = 0;
        while (s1.size() != 0) {
            if (s1.top() != '1') {
                len = 0;
            }
            else {
                ++len;
            }
            max_len = max(max_len, len);
            s1.pop();
        }
        return max_len * 2;
    }
};
