
#include <vector>
#include <iostream>
#include <cassert>

class Solution {
public:
    // Simple solution using dynamic programming
    int combinationSum4(std::vector<int>& nums, int target) {

        std::vector<int> counts(target + 1, 0);
        counts[0] = 1;

        for (int i = 1; i < counts.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= i) {
                    counts[i] += counts[i - nums[j]];
                }
            }
        }

        return counts[target];
    }
};

int main() {
    Solution solution;
    std::vector<int> a{1, 2, 3};
    assert(solution.combinationSum4(a, 4) == 7);
    return 0;
}
