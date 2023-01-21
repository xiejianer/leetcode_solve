#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> value_idx;
        vector<int> half_idx;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            value_idx[nums[i]] = i + 1;
            if (nums[i] * 2 == target) {
                half_idx.push_back(i + 1);
            }
        }
        if (half_idx.size() == 2) {
            for (int i = 0; i < 2; ++i) {
                res.push_back(half_idx[i] - 1);
            }
            return res;
        }
        for (int i = 0; i <= nums.size() / 2; ++i) {
            int idx1 = value_idx[nums[i]];
            int idx2 = value_idx[target - nums[i]];
            if (idx1 != 0 && idx2 != 0 && idx1 != idx2) {
                res.push_back(idx1 - 1);
                res.push_back(idx2 - 1);
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {1, 2, 4, 7, 9};
    vector<int> t = s.twoSum(vec, 11);
    return 0;
}
