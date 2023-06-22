class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            /*
            cout << "left = " << left << "\tright = " << right << "\tmid = " << mid << endl;
            cout << "right - left: " << right - left << endl;
            cout << "(right - left) / 2 = " << ((right - left) >> 1) << endl;
            */
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target ){
                if (nums[right] > nums[mid]) {
                    if (nums[right] == target) {
                        return right;
                    }
                    else if (nums[right] < target) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                else {
                    left = mid + 1;
                }
            }
            else { // nums[mid] > target
                if (nums[right] > nums[mid]) {
                    right = mid - 1;
                }
                else {
                    if (nums[right] == target) {
                        return right;
                    }
                    else if (nums[right] > target) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
            }
        }
        if (nums[left] == target) return left;
        return -1;
    }
};
