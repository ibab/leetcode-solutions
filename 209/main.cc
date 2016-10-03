#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, const vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0;
        int sum = 0;
        int shortest_seen = INT_MAX;
        for (int right = 1; right <= nums.size(); right++) {
            sum += nums[right - 1];
            if (sum >= s) {
                // Found valid subarray.
                shortest_seen = std::min(shortest_seen, right - left);
                // Try to reduce the subarray as much as possible.
                while (left < right) {
                    sum -= nums[left];
                    left++;
                    if (sum < s) {
                        break;
                    }
                    shortest_seen = std::min(shortest_seen, right - left);
                }
            }
        }
        return shortest_seen == INT_MAX ? 0 : shortest_seen;
    }
};

int main() {
    std::vector<int> data{2, 3, 1, 2, 4, 3};
    std::cout << Solution().minSubArrayLen(7, data) << std::endl;
    return 0;
}
