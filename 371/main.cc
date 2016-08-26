#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int carry = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            int sum = (a & mask) ^ (b & mask) ^ carry;
            // Carry is on if at least two bits out of three are on
            carry = ((a & mask) & ((b & mask) | carry)) | ((b & mask) & ((a & mask) | carry));
            // Bring into next column
            carry <<= 1;
            c |= sum;
            mask = mask << 1;
        }
        return c;
    }
};

int main() {
    Solution solution;
    int a = 34254224;
    int b = 23523525;
    std::cout << a + b << std::endl;
    std::cout << solution.getSum(a, b) << std::endl;
}
