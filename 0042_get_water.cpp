class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        vector<int> left;
        vector<int> right;
        int left_max = height[0];
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > left_max) {
                left_max = height[i];
            }
            left.push_back(left_max);
        }
        int right_max = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            if (height[i] > right_max) {
                right_max = height[i];
            }
            right.push_back(right_max);
        }
        int water = 0;
        for (int i = 0; i < height.size(); ++i) {
            cout << "i = " << i << '\t' << min(left[i], right[i]) - height[i] << endl;
            water += min(left[i], right[height.size() - i - 1]) - height[i];
        }
        return water;
    }
};
