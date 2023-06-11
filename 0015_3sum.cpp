#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<vector<int>> res_2sum = twoSum(nums, i + 1, nums[i] * (-1));
            if (res_2sum.size() > 0) {
                for (int j = 0; j < res_2sum.size(); ++j) {
                    res_2sum[j].push_back(nums[i]);
                    res.push_back(res_2sum[j]);
                }
            }
        }
        return res;
    }

    vector<vector<int>> twoSum(const vector<int>& nums, int start_idx, int target) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> um;
        for (int i = start_idx; i < nums.size(); ++i) {
            um[nums[i]].push_back(i);
        }
        for (int i = start_idx; i < nums.size(); ++i) {
            if(i > start_idx && nums[i] == nums[i - 1]) {
                continue;
            }
            if (um.find(target - nums[i]) != um.end()) {
                if (nums[i] == target - nums[i]) {
                    if (um[nums[i]].size() > 1) {
                        res.push_back(vector<int>{nums[i], nums[i]});
                    }
                } else{
                    if (um[target - nums[i]][0] > i) {
                        res.push_back(vector<int>{nums[i], nums[um[target - nums[i]][0]]});
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> res = s.threeSum(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
