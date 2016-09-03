
#include <iostream>
#include <vector>

// This solution first shows how the problem can be solved using
// algorithms from std, and then proceeds to show how they are implemented
class Solution {
  public:
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    std::vector<int> output;
    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
                     std::back_inserter(output));
    return std::vector<int>(output.begin(),
                            unique(output.begin(), output.end()));
  }

  private:
  template <typename InputIt1, typename InputIt2, typename OutputIt>
  OutputIt set_intersection(InputIt1 begin1, InputIt1 end1, InputIt2 begin2,
                            InputIt2 end2, OutputIt start) {
    while (begin1 != end1 && begin2 != end2) {
      if (*begin1 > *begin2) {
        begin2++;
      } else if (*begin1 < *begin2) {
        begin1++;
      } else {
        start = *begin1++;
        begin2++;
      }
    }
    return start;
  }

  template <typename InputIt>
  InputIt unique(InputIt begin, InputIt end) {
    if (begin == end) {
      return end;
    }

    InputIt output = begin;
    while (++begin != end) {
      if (!(*output == *begin) && (++output != begin)) {
        *output = std::move(*begin);
      }
    }
    return ++output;
  }
};

int main() {
  std::vector<int> a{1, 2, 2, 3};
  std::vector<int> b{2, 2};
  std::vector<int> out = Solution().intersection(a, b);
  for (int n : out) {
    std::cout << n << std::endl;
  }
  return 0;
}
