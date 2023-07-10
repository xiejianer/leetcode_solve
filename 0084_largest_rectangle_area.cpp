class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i < heights.size(); ++i) {
            if (s.size() == 0 || heights[i] >= s.top().second) {
                s.push(make_pair(i, heights[i]));
            } else {
                int idx = -1;
                while (s.size() != 0 && s.top().second > heights[i]) {
                    idx = s.top().first;
                    int area = (i - s.top().first) * s.top().second;
                    if (area > max_area) {
                        max_area = area;
                    }
                    s.pop();
                }
                if (s.size() == 0) {
                    s.push(make_pair(0, heights[i]));
                } else {
                    s.push(make_pair(idx, heights[i]));
                }
            }
        }
        while (s.size() != 0) {
            int area = (heights.size() - s.top().first) * s.top().second;
            if (area > max_area) {
                max_area = area;
            }
            s.pop();
        }
        return max_area;
    }
};
