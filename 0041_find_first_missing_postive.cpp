class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> vec(500001, 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 500001 && nums[i] > 0) {
                vec[nums[i]] = 1;
            }
        }
        for (int i = 1; i < 500001; ++i) {
            if (vec[i] != 1) {
                return i;
            }
        }
        return 0;
    }
};


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1 && nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
