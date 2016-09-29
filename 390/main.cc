#include <iostream>

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) {
            return 1;
        }
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};

int main() {
    std::cout << Solution().lastRemaining(9) << std::endl;
    return 0;
}
