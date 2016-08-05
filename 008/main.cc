// Problem 8 - String to Integer (atoi)
//
// Implement atoi to convert a string to an integer.

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int myAtoi(std::string str) {
        int curr = 0;
        int number = 0;
        int negative = false;
        std::vector<int> digits;
        while (curr < str.size() && (str[curr] == ' ' || str[curr] == '\t' || str[curr] == '\n')) {
            curr++;
        }
        if (curr >= str.size() || (str[curr] != '-' && str[curr] != '+' && (str[curr] < '0' || str[curr] > '9'))) {
            return 0;
        }
        if (str[curr] == '-') {
            negative = true;
            curr++;
        } else if (str[curr] == '+') {
            curr++;
        }
        if (str[curr] < '0' || str[curr] > '9') {
            return 0;
        }
        while (curr < str.size()) {
            if (str[curr] < '0' || str[curr] > '9') {
                break;
            }
            digits.push_back(str[curr] - '0');
            curr++;
        }
        std::reverse(digits.begin(), digits.end());
        int output = 0;
        int prev = 0;
        for (int i = 0; i < digits.size(); i++) {
            output += digits[i] * std::pow(10, i);
            if (output < prev) {
                if (negative) {
                    return -2147483648;
                } else {
                    return 2147483647;
                }
            }
            prev = output;
        }
        if (negative) {
            return -output;
        } else {
            return output;
        }
    }
};

int main() {
    std::cout << Solution().myAtoi("-1234") << std::endl;
}
