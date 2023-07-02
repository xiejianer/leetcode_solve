class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int pos = 2;
        int idx = 2;
        while (pos < nums.size()) {
            if (nums[pos] != nums[idx - 2]) {
                nums[idx] = nums[pos];
                idx++;
            }
            pos++;
        }
        return idx;
    }
};
