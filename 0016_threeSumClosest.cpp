#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <limits.h>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int diff = 100000;
		int res = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() -2; ++i) {
			int tmp = nums[i] + twoSumClosest(nums, i + 1, target - nums[i]);
            cout << "i = " << i << "\t tmp = " << tmp << endl;
			if (abs(tmp - target) < diff) {
				diff = abs(tmp - target);
				res = tmp;
			}
		}
		return res;
	}
	int twoSumClosest(const vector<int>& nums, int start_idx, int target) {
		int diff = 100000;
		int i = start_idx;
		int j = nums.size() - 1;
        int res = 0;
		int tmp_sum = 0;
		int tmp_diff = 0;
		while (i < j) {
			tmp_sum = nums[i] + nums[j];
			tmp_diff = abs(tmp_sum - target);
            cout << "i = " << i << "\tj = " << j << "\t tmp_diff = " << tmp_diff << "\tdiff = " << diff << endl;
			if (tmp_diff < diff) {
				diff = tmp_diff;
                res = tmp_sum;
			}
			if (tmp_sum == target) {
				break;
			} else if (tmp_sum < target) {
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
	Solution s;
	vector<int> nums = {2, 3, 8, 9, 10};
	cout << s.threeSumClosest(nums, 16) << endl;
	return 0;
}
