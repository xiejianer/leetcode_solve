#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> half_idx;
        unordered_map<int, int> value_idx;
        for (int i = 0 ; i < nums.size(); ++i) {
            value_idx[nums[i]] = i;
            if (nums[i] * 2 == target) {
                half_idx.push_back(i);
            }
        }
        if (half_idx.size() == 2) {
            return half_idx;
        }
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = value_idx.find(target - nums[i]);
            if (iter != value_idx.end() && nums[i] * 2 != target) {
                res.push_back(value_idx[nums[i]]);
                res.push_back(value_idx[target - nums[i]]);
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {3, 2, 4};
    int target = 6;
    vector<int> c = s.twoSum(vec, target);
    for (int i = 0; i < c.size(); ++i) {
        cout << c[i] << endl;
    }
    return 0;
}
