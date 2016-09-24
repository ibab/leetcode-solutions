#include <array>
#include <string>
#include <iostream>

class Solution {
public:
    bool isIsomorphic(const std::string& s, const std::string& t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::array<bool, 256> used;
        used.fill(false);
        std::array<char, 256> map;
        map.fill(-1);

        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == -1) {
                map[s[i]] = t[i];
                if (used[t[i]]) {
                    return false;
                }
                used[t[i]] = true;
            } else if (map[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isIsomorphic("abc", "def") << std::endl;
    return 0;
}
