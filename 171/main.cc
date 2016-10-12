#include <string>
#include <sstream>
#include <iostream>

using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        std::reverse(s.begin(), s.end());
        std::stringstream ss(s);
        int num = 0;
        int base = 1;
        char ch;
        while (ss.get(ch)) {
            num += base * (ch - 'A' + 1);
            base *= 26;
        }
        return num;
    }
};

int main() {
    std::cout << Solution().titleToNumber("AABC") << std::endl;
    return 0;
}
