#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        // Initialize to arbitrary difference.
        int best_delta = nums[0] + nums[1] + nums[2] - target;

        int i = 0;
        while (i < nums.size() - 1) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int delta = nums[i] + nums[j] + nums[k] - target;
                if (delta < 0) {
                    // The only way to increase the sum
                    // without moving i is to move j forward.
                    j++;
                } else if (delta > 0) {
                    // The only way to decrease the sum without
                    // moving i is to move k backward.
                    k--;
                } else {
                    // Exact match
                    return target;
                }
                if (abs(delta) < abs(best_delta)) {
                    best_delta = delta;
                }
            }
            i++;
        }
        return target + best_delta;
    }
};

int main() {
    vector<int> data{-4, 4, 2, -1, 20};
    std::cout << Solution().threeSumClosest(data, 14) << std::endl;
    return 0;
}
