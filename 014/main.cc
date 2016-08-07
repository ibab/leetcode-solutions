// Problem 14 - Longest Common Prefix
//
// Write a function to find the longest common prefix string amongst an array of strings.

#include <string>
#include <vector>
#include <iostream>

// BEGIN
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int i = 0;
        while (true) {
            char byte = 0;
            for (int j = 0; j < strs.size(); j++) {
                if (i >= strs[j].size()) {
                    return strs[0].substr(0, i);
                }
                if (!byte) {
                    byte = strs[j][i];
                } else {
                    if (byte != strs[j][i]) {
                        return strs[0].substr(0, i);
                    }
                }
            }
            i++;
        }
    }
};
// END

int main() {
    std::vector<std::string> input = {"abc", "ab", "ab"};
    std::cout << Solution().longestCommonPrefix(input) << std::endl;
    return 0;
}
