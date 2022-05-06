#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> num_posvec;
        for (int idx = 0; idx < nums.size(); ++idx) {
            num_posvec[nums[idx]].push_back(idx);
        }
        vector<int> vec;
        for (int idx = 0; idx < nums.size(); ++idx) {
            int tmp = target - nums[idx];
            cout << "debug_info: idx = " << idx << " num = " << nums[idx] << endl;
            if (num_posvec.find(tmp) != num_posvec.end()) {
                int pos1 = num_posvec[nums[idx]][0];
                int pos2 = num_posvec[tmp][0];
                if (pos1 != pos2) {
                    vec.push_back(pos1);
                    vec.push_back(pos2);
                    break;
                } else {
                    if (num_posvec[tmp].size() == 2) {
                        vec = num_posvec[tmp];
                        break;
                    }
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
    Solution s;
    int target = 10;
    vector<int> vec = {1, 2, 4, 5, 6, 10};
    vector<int> res = s.twoSum(vec, target);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}

