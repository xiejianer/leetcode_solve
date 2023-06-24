class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (newInterval.size() == 0) {
            return intervals;
        }
        int left_idx = left_bound(intervals, newInterval);
        cout << "left_idx = " << left_idx << endl;
        // merge
        vector<vector<int>> res;
        for (int i = 0; i < left_idx; ++i) {
            res.push_back(intervals[i]);
        }
        vector<int> vec = newInterval;
        if (left_idx != 0) {
            if (intervals[left_idx - 1][1] >= newInterval[0]) {
                vec[0] = intervals[left_idx - 1][0];
                if (intervals[left_idx - 1][1] > vec[1]) {
                    return intervals;
                }
                res.pop_back();
            }
        }
        for (int i = left_idx; i < intervals.size(); ++i) {
            if (intervals[i][1] >= vec[1]) {
                if (intervals[i][0] > vec[1]) {
                    res.push_back(vec);
                    vec = intervals[i];
                } else {
                    vec[1] = intervals[i][1];
                }
            }
        }
        res.push_back(vec);
        return res;
    }
    int left_bound(const vector<vector<int>>& vec, const vector<int>& target) {
        int left = 0;
        int right = vec.size();
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (target[0] > vec[mid][0]) {
                left = ++mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

