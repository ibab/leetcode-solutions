class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int count = 0;
        for (int x: nums) {
            if (x == majority) {
                count++;
            } else {
                count--;
                if (count < 0) {
                    majority = x;
                    count = 1;
                }
            }
        }
        return majority;
    }
};
