#include <array>
#include <string>
#include <cassert>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::array<int, 256> table = {0};
        for (char x: s) {
            table[x]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (table[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    assert(solution.firstUniqChar("leetcodeltc") == 5);
    return 0;
}
