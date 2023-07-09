class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (len < 1 || s[0] == '0') return 0;
        vector<int> vec(len, 0);
        vec[0] = 1;
        if (len < 2) return 1;
        if (s[1] == '0') {
            if (s[0] > '2') return 0;
            vec[1] = 1;
        } else {
            int num = stoi(s.substr(0, 2));
            if (num > 0 && num < 27) {
                vec[1] = 2;
            } else {
                vec[1] = 1;
            }
        }
        for (int i = 2; i < len; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] != '1' && s[i - 1] != '2') {
                    return 0;
                }
                vec[i] = vec[i - 2];
            } else {
                int num = stoi(s.substr(i - 1, 2));
                if (num > 0 && num < 27) {
                    if (s[i - 1] != '0') {
                        vec[i] = vec[i - 1] + vec[i - 2];
                    } else {
                        if (i > 2) {
                            vec[i] = vec[i - 3];
                        } else {
                            vec[i] = 1;
                        }
                    }
                } else {
                    vec[i] = vec[i - 1];
                }
            }
        }
        return vec[len - 1];
    }
};

