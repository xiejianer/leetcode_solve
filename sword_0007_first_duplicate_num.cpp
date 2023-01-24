class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] > i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
            //cout << "i = " << i << ", nums[i] = " << nums[i] << endl;
            if (nums[i] < i) {
                return nums[i];
            }
        }
        return -1;
    }
};
