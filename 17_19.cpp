#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> missingTwo(vector<int>& nums) {
		vector<int> res;
		int i = 0;
		while (i < nums.size()) {
			while (nums[i] <= nums.size() && nums[i] != i + 1) {
				swap(nums[i], nums[nums[i] - 1]);
			}
			++i;
		}
		int notEqualCnt = 0;
		int notEqualNum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != i + 1) {
				res.push_back(i + 1);
				++notEqualCnt;
				notEqualNum = nums[i];
			}
		}
		if (notEqualCnt == 1) {
			res.push_back(2*nums.size() + 3 - notEqualNum);
		}
		if (notEqualCnt == 0) {
			res.push_back(nums.size() + 1);
			res.push_back(nums.size() + 2);
		}
		return res;
	}
};

int main()
{
	vector<int> vec = {3, 2, 1};
	Solution s;
	vector<int> res = s.missingTwo(vec);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
