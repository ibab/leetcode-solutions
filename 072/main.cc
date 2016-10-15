
#include <string>
#include <vector>
#include <type_traits>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty()) {
            // All insertions.
            return std::max(word1.size(), word2.size());
        }
        // Stores the minimum number of operations needed to convert
        // word1[:i - 1] into word2[:j - 1].
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) {
            // Insert all characters.
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.size(); i++) {
            // Insert all characters.
            dp[0][i] = i;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // No operation needed.
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Choose among replacement, insertion, deletion.
                    dp[i][j] = min_(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
private:
    // A variadic min implementation that's used to express the minimum above more cleanly.
    template <typename T>
    T min_(T&& x) {
        return std::forward<T>(x);
    }
    template <typename T0, typename... Ts>
    typename std::common_type<T0, Ts...>::type
    min_(T0&& x0, Ts&&... xs) {
        return std::min(x0, min_(std::forward<Ts>(xs)...));
    }
};

int main() {
    std::cout << Solution().minDistance("sdfk29", "sdvsdf3") << std::endl;
    return 0;
}
