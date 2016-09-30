#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        // No need to check for 2.
        return n / 5 + trailingZeroes(n / 5);
    }
};

int main() {
    std::cout << Solution().trailingZeroes(1000) << std::endl;
    return 0;
}
