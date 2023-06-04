#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isParlindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        vector<int> vec;
        int num = 0;
        while (x > 0) {
            num = x % 10;
            vec.push_back(num);
            x /= 10;
        }
        int len = vec.size();
        for (int i = 0; i < len / 2; ++i) {
            if (vec[i] != vec[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isParlindrome(-100) << endl;
    cout << s.isParlindrome(100) << endl;
    cout << s.isParlindrome(101) << endl;
    cout << s.isParlindrome(1001) << endl;
    return 0;
}
