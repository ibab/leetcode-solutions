#include <iostream>
#include <string>

class Solution {
public:
    std::string reverseString(std::string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            std::swap(s[i], s[s.size() - i - 1]);
        }
        return s;
    }
};

int main() {
    Solution solution;
    std::cout << solution.reverseString("hello") << std::endl;
    return 0;
}

