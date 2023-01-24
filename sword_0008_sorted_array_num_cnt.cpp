class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        int cnt = right - left;
        return cnt;
    }
    int left_bound(const vector<int>& vec, int num) {
        int left = 0;
        int right = vec.size();
        while (left != right) {
            int mid = left + (right - left) / 2;
            if (num > vec[mid]) {
                left = ++mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int right_bound(const vector<int>& vec, int num) {
        int left = 0;
        int right = vec.size();
        while (left != right) {
            int mid = left + (right - left) / 2;
            if (num >= vec[mid]) left = ++mid;
            else {
                right = mid;
            }
        }
        return left;
    }
};
