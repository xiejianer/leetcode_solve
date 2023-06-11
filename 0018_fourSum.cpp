#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4) return res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] < 0 && target > INT_MAX + nums[i] || nums[i] > 0 && target < INT_MIN + nums[i]) {
				continue;
			}
			vector<vector<int>> tmp = threeSum(nums, i + 1, target - nums[i]);
			for (int j = 0; j < tmp.size(); ++j) {
				tmp[j].push_back(nums[i]);
				res.push_back(tmp[j]);
			}
		}
		return res;
	}
	vector<vector<int>> threeSum(const vector<int>& nums, int start_idx, int target) {
		vector<vector<int>> res;
		for (int i = start_idx; i < nums.size() - 2; ++i) {
			if (i > start_idx && nums[i] == nums[i - 1]) continue;
			if (nums[i] < 0 && target > INT_MAX + nums[i] || nums[i] > 0 && target < INT_MIN + nums[i]) {
				continue;
			}
			vector<vector<int>> tmp = twoSum(nums, i + 1, target - nums[i]);
			for (int j = 0; j < tmp.size(); ++j) {
				tmp[j].push_back(nums[i]);
				res.push_back(tmp[j]);
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
			if (nums[i] > 0 && nums[i] > INT_MAX - nums[j]) {
				--j;
			}
			if (nums[j] < 0 && nums[i] < INT_MIN - nums[j]) {
				++i;
			} 
			if (nums[i] + nums[j] == target) {
				res.push_back(vector<int>{nums[i], nums[j]});
				++i;
			} else if (nums[i] + nums[j] < target) {
				++i;
			} else {
				--j;
			}
		}
		return res;
	}
};

int main()
{
	vector<int> vec1 = {1, -2, -5, -4, -3, 3, 3, 5};
	Solution s;
	vector<vector<int>> vec = s.fourSum(vec1, -11);
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < vec[i].size(); ++j) {
			cout << vec[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}