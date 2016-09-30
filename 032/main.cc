#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    int longestValidParentheses(std::string s) {

        // First, we mark all invalid parentheses.
        std::stack<int> position;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                position.push(i);
            } else if (s[i] == ')') {
                if (position.empty()) {
                    // Invalid closing paren.
                    s[i] = 'X';
                } else {
                    position.pop();
                }
            }
        }
        // Now all positions are for invalid opening parens.
        while(!position.empty()) {
            s[position.top()] = 'X';
            position.pop();
        }

        // Traverse the input, keeping track of the length of the
        // longest valid substring. Each time we encounter an invalid
        // opening or closing paren, we have to reset the counter.
        int max_len = 0;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                max_len = std::max(len, max_len);
                len = 0;
            } else {
                len++;
            }
        }
        return std::max(max_len, len);
    }
};

int main() {
    std::cout << Solution().longestValidParentheses("())())((()()(()()()((()()()))()()(") << std::endl;
    return 0;
}

