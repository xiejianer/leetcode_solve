#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		unordered_map<int, vector<int>> um;
		for (int i = 0; i < nums.size(); ++i) {
			um[nums[i]].push_back(i);
		}
		for (int i = 0; i < nums.size(); ++ i) {
			int minus = target - nums[i];
			if (um.find(minus) != um.end()) {
				if (minus == nums[i]) {
					if (um[nums[i]].size() == 2) {
						res.push_back(um[nums[i]][0]);
						res.push_back(um[nums[i]][1]);
						break;
					}
				} else {
					res.push_back(i);
					res.push_back(um[minus][0]);
					break;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> vec = {1, 3, 3, 4};
	int target = 6;
	vector<int> res = s.twoSum(vec, target);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
    return 0;
}
