#include <vector>
#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size % 2 == 0) {
            return 0.5 * (findK(nums1, nums2, size / 2 - 1)
                        + findK(nums1, nums2, size / 2));
        }
        return findK(nums1, nums2, size / 2);
    }
    int findK(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int left1 = 0;
        int right1 = nums1.size();
        int left2 = 0;
        int right2 = nums2.size();
        // Find element by binary search in both arrays
        while ((left1 != right1) && (left2 != right2)) {
            int i1 = (left1 + right1) / 2;
            int i2 = (left2 + right2) / 2;
            if (i1 - left1 + i2 - left2 < k) {
                // k is larger than total number of elements left of both pivot elements.
                // Need to move one of the search areas to the right.
                if (nums1[i1] > nums2[i2]) {
                    // Move search area in nums2 to the right
                    k = k - (i2 - left2 + 1);
                    left2 = i2 + 1;
                } else {
                    // Move search area in nums1 to the right
                    k = k - (i1 - left1 + 1);
                    left1 = i1 + 1;
                }
            } else {
                // We are covering too many elements and need to move a search are to the left.
                if (nums1[i1] > nums2[i2]) {
                    // Move search area in nums1 to the left
                    right1 = i1;
                } else {
                    // Move search area in nums2 to the left
                    right2 = i2;
                }
            }
        }
        if (left1 == right1) {
            return nums2[left2 + k];
        } else {
            return nums1[left1 + k];
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> a {1, 2, 3, 4};
    std::vector<int> b {5, 6, 7, 8};
    std::cout << solution.findMedianSortedArrays(a, b) << std::endl;
    return 0;
}
