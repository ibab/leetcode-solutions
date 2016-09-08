#include <string>
#include <vector>
#include <array>
#include <iostream>

class Solution {
public:
    int longestSubstring(std::string s, int k) {
        s_ = s;
        k_ = k;
        counts_ = std::vector<std::array<int, 26>>();
        counts_.push_back({0});
        for (int i = 0; i < s.size(); i++) {
            auto tmp = counts_.back();
            tmp[s[i] - 'a']++;
            counts_.push_back(tmp);
        }
        return recurse(0, s.size());
    }

    bool invalid(int i, int j, char c) {
        return counts_[j][c - 'a'] - counts_[i][c - 'a'] > 0 && counts_[j][c - 'a'] - counts_[i][c - 'a'] < k_;
    }

    int recurse(int i, int j) {
        if (i >= j) {
            return 0;
        }
        int start = 0;
        int max = 0;
        int found = false;
        for (int k = i; k < j;) {
            int skip = 0;
            while (k + skip < j && invalid(i, j, s_[k + skip])) {
                skip++;
                found = true;
            }
            if (skip) {
                int result = recurse(start, k);
                start = k + skip;
                if (result > max) {
                    max = result;
                }
            }
            k = k + skip + 1;
        }
        if (!found) {
            return j - i;
        }
        // Also recurse into last bit
        int last = recurse(start, j);
        return std::max(max, last);
    }

private:
    std::string s_;
    std::vector<std::array<int, 26>> counts_;
    int k_;
};

int main() {
    std::cout << Solution().longestSubstring("xabccbd", 2) << std::endl;
    return 0;
}
