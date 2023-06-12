#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        int left = 0;
        gen(n, left, res, s);
        return res;
    }
    void gen(int num, int left, vector<string>& vec, string& s) {
        if (num == 0) {
            if (left == 0) {
                vec.push_back(s);
                return;
            } else {
                --left;
                s += ")";
                gen(num, left, vec, s);
                ++left;
                s = s.substr(0, s.size() - 1);
            }
        } else {
            if (left == 0) {
                // append left
                --num;
                ++left;
                s += "(";
                gen(num, left, vec, s);
                ++num;
                --left;
                s = s.substr(0, s.size() - 1);
            } else {
                // append right
                --left;
                s += ")";
                gen(num, left, vec, s);
                ++left;
                s = s.substr(0, s.size() - 1);
                // append left
                --num;
                ++left;
                s += "(";
                gen(num, left, vec, s);
                ++num;
                --left;
                s = s.substr(0, s.size() - 1);
            }
        }
    }
};
int main()
{
    Solution s;
    vector<string> vec = s.generateParenthesis(3);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << '\t';
    }
    cout << endl;
    return 0;
}
