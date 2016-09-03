#include<vector>
#include <iostream>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> output;

        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                output.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return output;
    }
};

int main() {
  std::vector<int> a{1, 2, 2, 3};
  std::vector<int> b{2, 2};
  std::vector<int> out = Solution().intersect(a, b);
  for (int n : out) {
    std::cout << n << std::endl;
  }
  return 0;
}
