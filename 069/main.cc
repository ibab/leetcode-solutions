#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        double y = 1;
        for (int i = 0; i < 20; i++) {
            y -= (y * y - x) / (2 * y);
        }
        return y;
    }
};

int main() {
    std::cout << Solution().mySqrt(2147395599) << std::endl;
    return 0;
}
