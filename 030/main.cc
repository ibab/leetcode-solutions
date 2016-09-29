#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || words.size() * words[0].size() > s.size()) {
            return std::vector<int>();
        }
        // Store map from each word to 
        //  1. The count that this word appears with in the words vector.
        //  2. The current index up to which we've checked in the string.
        //  3. The current count of this word that we've seen at this index.
        std::unordered_map<std::string, std::tuple<int, int, int>> map;
        for (auto& w: words) {
            if (map.find(w) == map.end()) {
                map[w] = std::make_tuple(1, -1, 0);
            } else {
                std::get<0>(map[w])++;
            }
        }
        int word_size = words[0].size();
        std::vector<int> results;

        for (int i = 0; i <= s.size() - word_size * words.size(); i++) {
            int count = 0;
            for (int j = 0; j < words.size(); j++) {
                int start = i + j * word_size;
                int end = i + (j + 1) * word_size;
                if (end > s.size()) {
                    break;
                }
                std::string sub = s.substr(
                    i + j * word_size,
                    word_size);
                // Break if we don't know this word, or if we've used up each instance of this word
                if (map.find(sub) == map.end() ||
                    (std::get<1>(map[sub]) == i &&
                     std::get<2>(map[sub]) == std::get<0>(map[sub]))) {
                    break;
                }
                if (std::get<1>(map[sub]) != i) {
                    std::get<1>(map[sub]) = i;
                    std::get<2>(map[sub]) = 0;
                }
                std::get<2>(map[sub])++;

                count++;
                if (count == words.size()) {
                    results.push_back(i);
                }
            }
        }
        return results;
    }
};

int main() {
    return 0;
}
