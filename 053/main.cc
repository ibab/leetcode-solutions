class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;
        for (int& x: nums) {
            sum = std::max(sum + x, x);
            max = std::max(max, sum);
        }
        return max;
    }
};
