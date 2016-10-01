#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long left = 1;
        unsigned long right = INT_MAX;
        while (left < right) {
            unsigned long mid = left + (right - left) / 2;
            if (mid * mid > num) {
                right = mid;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return left == num;
    }
};

int main() {
    std::cout << Solution().isPerfectSquare(16) << std::endl;
    return 0;
}
