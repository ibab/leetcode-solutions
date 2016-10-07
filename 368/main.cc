class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return std::vector<int>();
        }
        std::sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int max_count = 0;
            int last_elem = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j].second + 1 > max_count) {
                    max_count = dp[j].second + 1;
                    last_elem = j;
                }
            }
            dp[i] = {last_elem, max_count};
        }
        int max_seen = 0;
        int start = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i].second > max_seen) {
                max_seen = dp[i].second;
                start = i;
            }
        }
        std::vector<int> result;
        int k = start;
        while (k >= 0) {
            result.push_back(nums[k]);
            k = dp[k].first;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
