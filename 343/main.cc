#include <vector>
#include <iostream>

class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> vec(n + 1, 0);
        vec[0] = 1;
        for (int i = 1; i < vec.size(); i++) {
            for (int j = 1; j < std::min(n, 59); j++) {
                if (i - j >= 0) {
                    int prod = vec[i - j] * j;
                    if (prod > vec[i]) {
                        vec[i] = prod;
                    }
                } else {
                    break;
                }
            }
        }
        return vec.back();
    }
};

int main() {
    Solution solution;
    std::cout << solution.integerBreak(20) << std::endl;
    return 0;
}
