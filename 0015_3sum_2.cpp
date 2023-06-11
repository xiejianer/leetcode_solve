#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> tmp = twoSum(nums, i + 1, nums[i] * (-1));
            if (tmp.size() > 0) {
                for (int j = 0; j < tmp.size(); ++j) {
                    tmp[j].push_back(nums[i]);
                    res.push_back(tmp[j]);
                }
            }
        }
        return res;
    }

    vector<vector<int>> twoSum(const vector<int>& nums, int start_idx, int target) {
        int i = start_idx;
        int j = nums.size() - 1;
        vector<vector<int>> res;
        while (i < j) {
            if (i > start_idx && nums[i] == nums[i - 1]) {
                ++i;
                continue;
            }
            if (j < nums.size() - 1 && nums[j] == nums[j + 1]) {
                --j;
                continue;
            }
            if (nums[i] + nums[j] == target) {
                res.push_back(vector<int>{nums[i], nums[j]});
                ++i;
                --j;
            } else if (nums[i] + nums[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
