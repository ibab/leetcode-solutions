#include <string>
#include <vector>
#include <iostream>

using std::string;

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<char> stack;
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && !stack.empty() && stack.back() > num[i]) {
                stack.pop_back();
                k--;
            }
            stack.push_back(num[i]);
        }
        while(k > 0) {
            stack.pop_back();
            k--;
        }

        // If we remove all digits, the result should be "0"
        if (stack.empty()) {
            return "0";
        }
        // Remove extra zeros in the beginning
        int pad = 0;
        while (stack[pad] == '0' && pad < stack.size() - 1) {
            pad++;
        }
        return std::string(stack.begin() + pad, stack.end());
    }
};

int main() {
    std::cout << Solution().removeKdigits("23425340012304242042404159233210", 20) << std::endl;
    return 0;
}
