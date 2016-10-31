
class Solution {
public:
    uint32_t reverseBits(uint32_t in) {
        uint32_t out = 0;
        for (int i = 0; i < 32; i++) {
            out |= ((in >> i) & 1) << (31 - i);
        }
        return out;
    }
};
