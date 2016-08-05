// Problem 9 - Palindrome Number
//
// Determine whether an integer is a palindrome. Do this without extra space.

#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        // We define negative numbers to not be palindromes
        if (x < 0) {
            return false;
        }
        uint num = std::abs(x);
        uint size = std::ceil(std::log10(num + 1));
        for (uint i = size / 2; i < size; i++) {
            uint lower = (x % (uint)std::pow(10, i + 1)) / std::pow(10, i);
            uint upper = (x % (uint)std::pow(10, size - i)) / std::pow(10, size - i - 1);
            if (lower != upper) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isPalindrome(112211) << std::endl;
    std::cout << Solution().isPalindrome(11211) << std::endl;
    std::cout << Solution().isPalindrome(112212) << std::endl;
    std::cout << Solution().isPalindrome(11212) << std::endl;
    return 0;
}
