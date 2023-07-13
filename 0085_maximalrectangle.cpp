class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> h(n, 0);
        int max_size = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    h[j] += 1;
                } else {
                    h[j] = 0;
                }
            }
            int curr_size = mono_stack(h);
            if (curr_size > max_size) {
                max_size = curr_size;
            }
        }
        return max_size;
    }
    int mono_stack(const vector<int> vec) {
        stack<pair<int, int>> s;
        int max_area = 0;
        int curr_area = 0;
        int idx1 = 0;
        int idx2 = 0;
        int last_pop = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (s.size() == 0 || vec[i] >= vec[s.top().second]) {
                s.push(make_pair(i, i));
            } else {
                while (s.size() > 0) {
                    idx2 = s.top().second;
                    idx1 = s.top().first;
                    if (vec[idx2] > vec[i]) {
                        s.pop();
                        last_pop = idx1;
                        curr_area = (i - idx1) * vec[idx2];
                        if (curr_area > max_area) {
                            max_area = curr_area;
                        }
                    } else {
                        break;
                    }
                }
                s.push(make_pair(last_pop, i));
            }
        }
        while (s.size() > 0) {
            idx1 = s.top().first;
            idx2 = s.top().second;
            curr_area = (vec.size() - idx1) * vec[idx2];
            if (curr_area > max_area) {
                max_area = curr_area;
            }
            s.pop();
        }
        return max_area;
    }
};
