class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        int idx = 0;
        for (int i = 1; i < len; ++i) {
            if (nums[i] != nums[idx]) {
                nums[++idx] = nums[i];
            }
            cout << "idx = " << idx << endl;
        }
        return idx + 1;
    }
}
