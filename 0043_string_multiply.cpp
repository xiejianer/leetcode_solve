class Solution {
public:
    string multiply(string num1, string num2) {
        int num = 0;
        int bonus = 0;
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> vec(len1 + len2, 0);
        int start_pos = len1 + len2;
        for (int i = num1.size() - 1; i >= 0; --i) {
            start_pos--;
            int idx = start_pos;
            bonus = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                num = (num1[i] - '0') * (num2[j] - '0') + bonus;
                bonus = num / 10 + (vec[idx] + num % 10) / 10;
                vec[idx] = (vec[idx] + num % 10) % 10;
                --idx;
            }
            vec[idx] += bonus;
        }
        string res = "";
        bool flag = true;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == 0 && i != vec.size() - 1) {
                if (flag) {
                    continue;
                }
            }
            flag = false;
            res += '0' + vec[i];
        }
        return res;
    }
};
