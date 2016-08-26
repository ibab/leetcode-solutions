
#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        return (int)(unsigned long)(&((char*)a)[b]);
    }
};

int main() {
    Solution solution;
    int a = 34254224;
    int b = -23523525;
    std::cout << a + b << std::endl;
    std::cout << solution.getSum(a, b) << std::endl;
}
