class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::array<int, 32> counts = {0};
        for (int x: nums) {
            for (int i = 0; i < 32; i++) {
                counts[i] = (counts[i] + ((x >> i) & 1)) % 3;
            }
        }

        int n = 0;
        for (int i = 0; i < 32; i++) {
            if (counts[i]) {
                n |= 1 << i;
            }
        }

        return n;
    }
};
