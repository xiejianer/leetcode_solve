#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len1 = nums1.size();
            int len2 = nums2.size();
            int len = len1 + len2;
            if ((len & 1) == 1) {
                return findKthNum(nums1, nums2, len / 2 + 1);
            } else {
                return (findKthNum(nums1, nums2, len / 2) + findKthNum(nums1, nums2, len / 2 + 1)) / 2.0;
            }
        }
        int findKthNum(const vector<int>& vec1, const vector<int>& vec2, int k) {
            int len1 = vec1.size();
            int len2 = vec2.size();
            int idx1 = 0, idx2 = 0;
            int kthNum = 0;
            while (true) {
                if (idx1 == len1) {
                    return vec2[idx2 + k - 1];
                }
                if (idx2 == len2) {
                    return vec1[idx1 + k - 1];
                }
                if (k == 1) {
                    return (vec1[idx1] < vec2[idx2]) ? vec1[idx1] : vec2[idx2];
                }
                int half = k / 2;
                int newIdx1 = idx1 + half - 1;
                if (newIdx1 > len1 - 1) {
                    newIdx1 = len1 - 1;
                }
                int newIdx2 = idx2 + half - 1;
                if (newIdx2 > len2 - 1) {
                    newIdx2 = len2 - 1;
                }
                if (vec1[newIdx1] <= vec2[newIdx2]) {
                    k -= newIdx1 - idx1 + 1;
                    idx1 = newIdx1 + 1;
                } else {
                    k -= newIdx2 - idx2 + 1;
                    idx2 = newIdx2 + 1;
                }
            }
        }
};

int main()
{
    vector<int> vec1 = {1, 3};
    vector<int> vec2 = {2};
    Solution s;
    cout << s.findMedianSortedArrays(vec1, vec2) << endl;
    return 0;
}
