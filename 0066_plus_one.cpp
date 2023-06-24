class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int extra = 1;
        vector<int> res;
        int num = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            num = digits[i] + extra;
            res.push_back(num % 10);
            extra = num / 10;
        }
        if (extra != 0) {
            res.push_back(extra);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
