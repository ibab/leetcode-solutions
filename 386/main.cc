#include <vector>
#include <cmath>
#include <iostream>

class Solution {
public:
    void intersperse(std::vector<int>& curr, int base, int level, int max_level, int n) {
        for (int i = 0; i <= 9; i++) {
            int number = base * 10 + i;
            if (number > 0 && number <= n) {
                curr.push_back(number);
            }
            if (number > 0 && level < max_level) {
                intersperse(curr, number, level + 1, max_level, n);
            }
        }
    }
    std::vector<int> lexicalOrder(int n) {
        int max_level = log10(n);
        std::vector<int> vec;
        intersperse(vec, 0, 0, max_level, n);
        return vec;
    }
};

int main() {
    Solution solution;
    std::vector<int> out = solution.lexicalOrder(113);
    for (int x: out) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
