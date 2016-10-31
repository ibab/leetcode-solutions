class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int, 3> counts;
        counts.fill(0);
        for (int x: nums) {
            counts[x]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int k = 0; k <= 2; k++) {
                if (counts[k] > 0) {
                    nums[i] = k;
                    counts[k]--;
                    break;
                }
            }
        }
    }
};
