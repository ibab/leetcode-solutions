//
// Problem 1 - Two Sum
//
// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.  You may assume that each input would have
// exactly one solution.
//

#include <unordered_map>
#include <vector>
#include <iostream>
#include <cassert>

// BEGIN
class Solution {
public:
    // The idea is to create a map from entries in the vector to their index in
    // the vector. Then, if there is a partner to the current number that sums
    // to the target value, we can find it quickly by looking up (target -
    // number) in the map, which we can do in O(1) amortized time.
    // We can do this while we are building the map.
    // Because the partner value must occur before the current value in the
    // vector, we can order the indices consistently by simply placing one
    // before the other.
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int item = target - nums[i];
            if (map.count(item)) {
                return std::vector<int>{map[item], i};
            }
            map[nums[i]] = i;
        }
        return std::vector<int>{};
    }
};
// END

int main() {
    Solution solution;
    std::vector<int> vec{3, 2, 4};
    std::vector<int> out = solution.twoSum(vec, 6);
    assert((out == std::vector<int>{1, 2}));
}
