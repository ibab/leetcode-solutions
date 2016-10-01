#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        unsigned long left = 0;
        unsigned long right = INT_MAX;
        while (left + 1 < right) {
            unsigned long mid = left + (right - left) / 2;
            if (mid * mid <= x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

// Alternative solution using Newton method.
/*
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
*/

int main() {
    std::cout << Solution().mySqrt(2147395599) << std::endl;
    return 0;
}
