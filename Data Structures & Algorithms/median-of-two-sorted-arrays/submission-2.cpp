class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int half = (m + n + 1) / 2;

        int l = 0;
        int r = m;

        while (l < r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            if (nums1[i] < nums2[j - 1]) {
                l = i + 1;
            } else {
                r = i;
            }
        }

        int i = l;
        int j = half - i;

        int Aleft = (i > 0) ? nums1[i - 1] : INT_MIN;
        int Bleft = (j > 0) ? nums2[j - 1] : INT_MIN;
        int leftMax = max(Aleft, Bleft);

        if ((m + n) % 2 != 0) {
            return leftMax;
        }

        int Aright = (i < m) ? nums1[i] : INT_MAX;
        int Bright = (j < n) ? nums2[j] : INT_MAX;
        int rightMin = min(Aright, Bright);

        return (leftMax + rightMin) / 2.0;
    }
};
