#include <iostream>

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0 || x + y == z || x == z || y == z) {
            return true;
        }
        if (z > x + y) {
            return false;
        }
        return z % gcd(x, y) == 0;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};

int main() {
    std::cout << Solution().canMeasureWater(3, 5, 4) << std::endl;
    return 0;
}
