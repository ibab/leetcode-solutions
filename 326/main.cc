#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isPowerOfThree(3 * 3 * 3 * 3 * 3 * 3) << std::endl;
    std::cout << Solution().isPowerOfThree(3 * 3 * 3 * 3 * 3 * 2) << std::endl;
    return 0;
}
