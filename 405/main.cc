#include <iostream>
#include <sstream>
#include <string>

using std::string;

class Solution {
public:
    char getChar(int num) {
        switch(num) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                return num + '0';
            case 10:
                return 'a';
            case 11:
                return 'b';
            case 12:
                return 'c';
            case 13:
                return 'd';
            case 14:
                return 'e';
            case 15:
                return 'f';
        }
        return 0;
    }
    string toHex(int num_) {
        unsigned int num = num_;
        std::stringstream ss;
        while (num > 0) {
            ss << getChar(num % 16);
            num /= 16;
        }
        std::string out = ss.str();
        if (out.empty()) {
            return "0";
        }
        std::reverse(out.begin(), out.end());
        return out;
    }
};

int main() {
    std::cout << Solution().toHex(-34231) << std::endl;
    return 0;
}
