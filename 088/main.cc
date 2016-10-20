class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        int lower = nums1.size() - n - m - 1;
        m--;
        n--;
        while (i > lower) {
            if (n >= 0 && m >= 0) {
                if (nums1[m] > nums2[n]) {
                    nums1[i] = nums1[m--];
                } else {
                    nums1[i] = nums2[n--];
                }
            } else if (n >= 0) {
                nums1[i] = nums2[n--];
            } else if (m >= 0) {
                nums1[i] = nums1[m--];
            }
            i--;
        }
    }
};
