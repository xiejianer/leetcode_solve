#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        cout << "n = " << n << endl;
        vector<vector<int>> vec;
        vec.push_back(vector<int>{1});
        vec.push_back(vector<int>{1});
        for (int i = 2; i <= n; ++i) {
            cout << "i = " << i << "\tpre_vec_size = " << vec[i-1].size() << endl;
            int num = vec[i-1][0];
            int count = 1;
            vector<int> tmp;
            for (int j = 1; j < vec[i-1].size(); ++j) {
                cout << "j = " << j << endl;
                if (vec[i-1][j] == num) {
                    ++count;
                }
                else {
                    cout << "count = " << count << "\tnum = " << num << endl;
                    tmp.push_back(count);
                    tmp.push_back(num);
                    count = 1;
                    num = vec[i-1][j];
                }
            }
            cout << "count = " << count << "\tnum = " << num << endl;
            tmp.push_back(count);
            tmp.push_back(num);
            vec.push_back(tmp);
        }
        string res;
        for (int i = 0; i < vec[n].size(); ++i) {
           cout << vec[n][i] << endl;
           res += '0' + vec[n][i];
        }
        return res;
    }
};

int main()
{
    Solution s;
    int num = 1;
    cout << s.countAndSay(num) << endl;
    num = 4;
    cout << s.countAndSay(num) << endl;
    return 0;
}
