#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        // Max scan of height.
        vector<int> maxLeft(height.size(), 0);
        for (int i = 0; i < maxLeft.size(); i++) {
            if (i == 0) {
                maxLeft[i] = height[i];
                continue;
            }
            maxLeft[i] = std::max(maxLeft[i - 1], height[i]);
        }
        // Reverse max scan of height
        vector<int> maxRight(height.size(), 0);
        for (int i = maxRight.size() - 1; i >= 0; i--) {
            if (i == maxRight.size() - 1) {
                maxRight[i] = height[i];
                continue;
            }
            maxRight[i] = std::max(maxRight[i + 1], height[i]);
        }
        // answer for each cell is min(max_left, max_right) - height
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            sum += std::max(0, std::min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return sum;
    }
};

int main() {
    vector<int> data{1, 6, 2, 4, 6, 4, 1, 6, 3, 5};
    std::cout << Solution().trap(data) << std::endl;
    return 0;
}
