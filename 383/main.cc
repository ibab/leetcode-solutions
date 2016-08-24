#include <array>
#include <iostream>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::array<int, 256> table = {0};
        for (char x: magazine) {
            table[x]++;
        }
        for (char y: ransomNote) {
            table[y]--;
            if (table[y] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << solution.canConstruct("asdfasdf", "aaassffdd") << std::endl;
    return 0;
}
