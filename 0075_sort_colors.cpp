class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        int pos0 = 0;
        int pos1 = -1;
        int pos2 = nums.size() - 1;
        int i = 0;
        while (i < pos2) {
            if (nums[i] == 0) {
                if (pos1 != -1) {
                    swap(nums[i], nums[pos1]);
                    pos1 = i;
                    while (pos1 >= 0 && nums[pos1] == 1) {
                        if (pos1 - 1 >= 0) --pos1;
                    }
                    if (nums[pos1] != 1) ++pos1;
                }
            }
            if (nums[i] == 1 && pos1 == -1) pos1 = i;
            if (nums[i] == 2) {
                while (i < pos2 && nums[i] == 2) {
                    swap(nums[i], nums[pos2]);
                    --pos2;
                }
                if (nums[i] == 1) {
                    if (pos1 == -1) {
                        pos1 = i;
                    }
                }
                if (nums[i] == 0) {
                    if (pos1 != -1) {
                        swap(nums[i], nums[pos1]);
                        pos1 = i;
                        pos1 = i;
                        while (pos1 >= 0 && nums[pos1] == 1) {
                            if (pos1 - 1 >= 0) --pos1;
                        }
                        if (nums[pos1] != 1) ++pos1;
                    }
                }
            }
            ++i;
        }
        if (nums[i] == 0 && pos1 != -1) {
            swap(nums[i], nums[pos1]);
        }
        return;
    }
};
