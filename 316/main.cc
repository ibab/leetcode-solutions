#include <string>
#include <array>
#include <deque>
#include <iostream>

class Solution {
public:
    std::string removeDuplicateLetters(const std::string& s) {

        std::array<int, 256> count;
        count.fill(0);
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        std::deque<char> stack;
        std::array<bool, 256> seen;
        seen.fill(false);
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]--;
            if (seen[s[i]]) {
                continue;
            }

            while(!stack.empty() && stack.back() > s[i] && count[stack.back()] >= 1) {
                seen[stack.back()] = false;
                stack.pop_back();
            }

            stack.push_back(s[i]);
            seen[s[i]] = true;
        }

        return std::string(stack.begin(), stack.end());
    }
};

int main() {
    std::cout << Solution().removeDuplicateLetters("abcba") << std::endl;
    return 0;
}
