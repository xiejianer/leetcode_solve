class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res = "";
        int extra = 0;
        int num = 0;
        while (i >= 0 && j >= 0) {
            num = a[i] - '0' + b[j] - '0' + extra;
            res += '0' + num % 2;
            extra = num / 2;
            i--;
            j--;
            cout << "while res = " << res << endl;
        }
        if (i == -1) {
            for (int k = j; k >= 0; --k) {
                num = b[k] - '0' + extra;
                res += '0' + num % 2;
                extra = num / 2;
                cout << "for 1, res = " << res << endl;
            }
        }
        if (j == -1) {
            for (int k = i; k >= 0; --k) {
                num = a[k] - '0' + extra;
                res += '0' + num % 2;
                extra = num / 2;
                cout << "for 2, res = " << res << endl;
            }
        }
        if (extra != 0) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
