class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        for (int x: nums) {
            num ^= x;
        }

        num &= -num;

        vector<int> results = {0, 0};
        for (int x: nums) {
            if ((x & num) == 0) {
                results[0] ^= x;
            } else {
                results[1] ^= x;
            }
        }
        return results;
    }
};
