// Problem 15 - 3Sum
//
// Given an array S of n integers, are there elements a, b, c in S such that a
// + b + c = 0? Find all unique triplets in the array which gives the sum of
// zero.

#include <vector>
#include <iostream>
#include <unordered_set>

// BEGIN
class Solution {
public:
    // The challenge here is to avoid duplicate outputs.
    // First, sort the inputs (O(log n)) so that we are able to easily skip
    // duplicates. Then, we perform a double iteration over the sorted input,
    // skipping duplicate elements.
    // This guarantees that we only get unique solutions.
    // The third element is found in a similar way to the 2Sum solution.
    // The -999999 intializations are ugly and should be replaced with separate
    // boolean flags.
    // Although this solution has O(n^2) time complexity, the constant
    // prefactor is large, so that it is easily beaten by a more naive O(n^3)
    // solution (using the same skipping trick for the third loop) on small
    // inputs.
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> out;
        int prev_i = -999999;
        for (int i = 0; i < nums.size(); i++) {
            if (prev_i == nums[i]) {
                continue;
            }
            std::unordered_set<int> seen;
            int prev_j = -999999;
            for (int j = i + 1; j < nums.size(); j++) {
                if (prev_j == nums[j]) {
                    continue;
                }
                int target = 0 - nums[i] - nums[j];
                if (seen.count(target)) {
                    out.push_back({nums[i], target, nums[j]});
                    prev_j = nums[j];
                }
                seen.insert(nums[j]);
            }
            prev_i = nums[i];
        }
        return out;
    }
};
// END

int main() {
    Solution solution;
    std::vector<int> input = {-1, 1, 0, 1};
    auto solutions = solution.threeSum(input);
    for (auto &x: solutions) {
        std::cout << "[" << x[0] << ", " << x[1] << ", " << x[2] << "]" << std::endl;
    }
    return 0;
}

