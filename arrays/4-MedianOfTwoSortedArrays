class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // approach here: we have two pointers that increment nums1 and nums2, iterating whichever has a smaller value at it
        // we then want to iterate through each array, checkigng if we hit the end of one or the other array
        // and finally either the middle (if n+m is odd) or the median of the middle elements
        int n = nums1.size();
        int m = nums2.size();
        // i and j here are iterators, m1 and m2 keep track of medians for each array
        int i = 0, j = 0, m1 = 0, m2 = 0;

        // Find the median here
        for (int count = 0; count <= (n + m) / 2; count++) {
            m2 = m1;
            if (i != n && j != m) {
                // iterate i if nums1 is smaller, j if nums2 is smaller..
                if (nums1[i] > nums2[j]) {
                    m1 = nums2[j];
                    j++;
                } else {
                    m1 = nums1[i];
                    i++;
                }
            } else if (i < n) {
                m1 = nums1[i];
                i++;
            } else {
                m1 = nums2[j];
                j++;
            }
        }

        // if n+m is odd, return m1, else return (m1+m2)/2
        if ((n + m) % 2 == 1) {
            return static_cast<double>(m1);
        } else {
            double ans = static_cast<double>(m1) + static_cast<double>(m2);
            return ans / 2.0;
        }
    }

};