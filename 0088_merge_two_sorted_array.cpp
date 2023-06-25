class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0 && n == 0) return;
        int m1 = m, n1 = n;
        int pos = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[pos] = nums2[n - 1];
                --n;
            } else {
                nums1[pos] = nums1[m - 1];
                --m;
            }
            --pos;
        }
        while (n > 0) {
            nums1[pos] = nums2[n-1];
            --pos;
            --n;
        }
        for (int i = 0; i < m1 + n1; ++i) {
            cout << nums1[i] << '\t';
        }
        cout << endl;
        return;
    }
};
