#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <iostream>

class Solution {
public:
    std::pair<int, int> get(std::stack<int>& s) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        return {a, b};
    }
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;
        for (auto& t: tokens) {
            int num;
            int a, b;
            if (t == "+") {
                std::tie(a, b) = get(stack);
                stack.push(a + b);
            } else if (t == "-") {
                std::tie(a, b) = get(stack);
                stack.push(b - a);
            } else if (t == "/") {
                std::tie(a, b) = get(stack);
                stack.push(b / a);
            } else if (t == "*") {
                std::tie(a, b) = get(stack);
                stack.push(a * b);
            } else {
                std::stringstream ss;
                ss << t;
                ss >> num;
                stack.push(num);
            }
        }
        return stack.top();
    }
};

int main() {
    std::vector<std::string> instructions{"1", "2", "+", "3", "*"};
    std::cout << Solution().evalRPN(instructions) << std::endl;
    return 0;
}
