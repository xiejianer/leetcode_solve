class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;
        int len = s.size();
        int k = int(ceil((len - numRows) * 1.0 / (2 * numRows - 2)));
        int total_num = numRows + k * (2 * numRows - 2);
        queue<int> q1, q2;
        vector<int> vec;
        int idx = 1;
        for (int i = 0; i <= k; ++i) {
            q1.push(idx);
            idx = idx + 2 * numRows - 2;
        }
        while (q1.size() > 0) {
            idx = q1.front();
            if (idx == 1) {
                q2.push(idx + 1);
            }
            else {
                q2.push(idx - 1);
                q2.push(idx + 1);
            }
            vec.push_back(idx);
            q1.pop();
        }
        int counter = numRows - 2;
        while (counter --) {
            int flag = -1;
            while (q2.size() > 0) {
                idx = q2.front();
                vec.push_back(idx);
                flag = flag * (-1);
                q1.push(idx + flag);
                q2.pop();
            }
            q1.swap(q2);
        }
        idx = numRows;
        for (int i = 0; i <= k; ++i) {
            vec.push_back(idx);
            idx = idx + 2 * numRows - 2;
        }
        string res = "";
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] <= len) {
                res += s[vec[i] - 1];
            }
        }
        return res;
    }
};
