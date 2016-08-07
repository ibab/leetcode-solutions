// Problem 11 - Container With Water
//
// Given n non-negative integers a1, a2, ..., an, where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
// with x-axis forms a container, such that the container contains the most
// water.
//
// Note: You may not slant the container.

#include <vector>
#include <iostream>

// BEGIN
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;

        while (i != j) {
            int area = (j - i) * std::min(height[i], height[j]);
            if (area > max_area) {
                max_area = area;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_area;
    }
};
// END

int main() {
    Solution solution;
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    std::cout << solution.maxArea(a) << std::endl;
}
