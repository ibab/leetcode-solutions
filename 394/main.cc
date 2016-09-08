#include <iostream>
#include <string>
#include <sstream>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stringstream input(s);
        std::stringstream output;
        while (!input.eof()) {
            int n = 0;
            int next = input.peek();
            if (next >= '0' && next <= '9') {
                int n = 0;
                input >> n;

                std::stringstream inner;
                input.get(); // discard [
                int level = 1;
                while (level > 0) {
                    if (input.peek() == '[') {
                        level++;
                    } else if (input.peek() == ']') {
                        level--;
                        if (level == 0) {
                            input.get(); // discard ]
                            break;
                        }
                    }
                    inner << (char)input.get();
                }
                std::string decoded = decodeString(inner.str());
                for (int i = 0; i < n; i++) {
                    output << decoded;
                }
            } else {
                if (!input.eof()) {
                    output << (char)input.get();
                }
            }
        }
        return output.str(); 
    }
};

int main() {
    std::cout << Solution().decodeString("2[ab3[x]q]4[q]") << std::endl;
    return 0;
}
