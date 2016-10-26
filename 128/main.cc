class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int result = 0;
        for (int x: nums) {
            if (numbers.find(x - 1) == numbers.end()) {
                int n = 1;
                while (numbers.find(++x) != numbers.end()) {
                    n++;
                }
                result = max(result, n);
            }
        }
        return result;
    }
};
