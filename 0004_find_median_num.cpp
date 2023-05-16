class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if ((len1 + len2) % 2 != 0) {
            return findKthNum(nums1, 0, len1 - 1, nums2, 0, len2 - 1, (len1 + len2) / 2 + 1);
        } else {
            return (findKthNum(nums1, 0, len1 - 1, nums2, 0, len2 - 1, (len1 + len2) / 2) +
                    findKthNum(nums1, 0, len1 - 1, nums2, 0, len2 - 1, (len1 + len2) / 2 + 1)) / 2.0;
        }
    }
    int findKthNum(vector<int>& nums1, int l1, int r1,
                   vector<int>& nums2, int l2, int r2, int k)
    {
        if (l1 > r1) return nums2[l2 + k - 1];
        if (l2 > r2) return nums1[l1 + k - 1];
        if (r1 - l1 > r2 - l2) return findKthNum(nums2, l2, r2, nums1, l1, r1, k);
        if (k == 1) {
            return min(nums1[l1], nums2[l2]);
        }
        int p1 = min(l1 + k / 2 - 1, r1);
        int p2 = k - p1 + l1 + l2 -2;
        if (nums1[p1] == nums2[p2]) {
            return nums1[p1];
        }
        else if (nums1[p1] > nums1[p2]) {
            return findKthNum(nums1, l1, r1, nums2, p2 + 1, r2, k - p2 + l2 - 1);
        }
        else {
            return findKthNum(nums1, p1 + 1, r1, nums2, l2, r2, k - p1 + l1 - 1);
        }
    }
};
