#include <string>
#include <stack>
#include <iostream>

using std::string;

class Solution {
public:
    char partner(char c) {
        switch(c) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
        }
        throw "Invalid input";
    }

    bool isValid(string s) {
        std::stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                    stack.push(s[i]);
                    break;
                case ')':
                case ']':
                case '}':
                    if (stack.empty() || stack.top() != partner(s[i])) {
                        return false;
                    }
                    stack.pop();
                    break;
            }
        }
        return stack.empty();
    }
};

int main() {
    std::cout << Solution().isValid("[]{{(([]))}}{}()[]") << std::endl;
    return 0;
}
