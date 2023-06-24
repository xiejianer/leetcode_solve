class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; ++i) {
            s += '0' + i;
        }
        if (n == 1) return s;
        k = k % fact(n);
        if (k == 1) return s;
        if (k == 0) {
            reverse(s.begin(), s.end());
            return s;
        }
        int num = 2;
        while (k > fact(num)) {
            ++num;
        }
        --num;
        int round = k / fact(num);
        int extra = k % fact(num);
        cout << "k = " << k << endl;
        cout << "num = " << num << "\tfact_num = " << fact(num) << endl;
        cout << "round: " << round << "\textra: " << extra << endl;
        if (round > 1) {
            cout << "s = " << s << endl;
            swap(s[n - num - 1], s[n - num - 1 + round - 1]);
            cout << "s = " << s << endl;
            sort(s.begin() + n - num, s.end());
        }
        int left = n - num;
        int right = n - 1;
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        cout << "before while, s = " << s << endl;
        while (extra > 0) {
            //cout << "extra = " << extra << "\ts = " << s << endl;
            nextPermutation(s);
            extra--;
        }
        return s;
    }
    void nextPermutation(string& s) {
        int i = s.size() - 1;
        while (i > 0 && s[i] < s[i - 1]) {
            --i;
        }
        if (i == 0) {
            reverse(s.begin(), s.end());
            return;
        }
        int pos = findfirstbigger(s, i, s[i-1]);
        swap(s[i-1], s[pos]);
        reverse(s.begin() + i, s.end());
        return;
    }
    int findfirstbigger(const string& s, int start_pos, char target) {
        int i = s.size() - 1;
        while (i >= start_pos) {
            if (s[i] > target) {
                return i;
            }
            --i;
        }
        return -1;
    }
    int fact(int n) {
        int res = 1;
        while (n > 1) {
            res *= n;
            n--;
        }
        return res;
    }
};
