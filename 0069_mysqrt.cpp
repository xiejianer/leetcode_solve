class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 4) return 1;
        int left = 1;
        int right = x / 2;
        int mid = 0;
        while (left <= right) {
            cout << "left: " << left << "\tright: " << right << endl;
            mid = left + (right - left) / 2;
            cout << "mid = " << mid << endl;
            if (mid == x / mid) {
                return mid;
            }
            else if (mid > x / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            cout << "left: " << left << "\tright: " << right << endl;
        }
        return left - 1;
    }
};
