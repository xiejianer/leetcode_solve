class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;
        if (intervals.size() == 1) {
            res.push_back(intervals[0]);
            return res;
        }
        sort(intervals.begin(),
             intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             }
        );
        int end_point = intervals[0][1];
        vector<int> vec = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > vec[1]) {
                res.push_back(vec);
                vec = intervals[i];
            } else {
                if (intervals[i][1] > vec[1]) {
                    vec[1] = intervals[i][1];
                }
            }
        }
        res.push_back(vec);
        return res;
    }
};

