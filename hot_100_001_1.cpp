#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> vec;
            unordered_map<int, vector<int>> um;
            for (int i = 0; i < nums.size(); ++i) {
                um[nums[i]].push_back(i);
            }
            for (int i = 0; i < nums.size(); ++i) {
                int res = target - nums[i];
                if (um.find(res) != um.end()) {
                    if (res == nums[i]) {
                        if (um[res].size() == 2) {
                            vec.push_back(um[res][0]);
                            vec.push_back(um[res][1]);
                            break;
                        }
                    } else {
                        vec.push_back(i);
                        vec.push_back(um[res][0]);
                        break;
                    }
                }
            }
            if (vec[0] > vec[1]) {
                swap(vec[0], vec[1]);
            }
            return vec;
        }
};

int main()
{
    return 0;
}
