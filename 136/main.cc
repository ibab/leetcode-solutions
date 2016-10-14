class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int x: nums) {
            num ^= x;
        }
        return num;
    }
};
