#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        visited.insert(beginWord);
        while (!q.empty()) {
            string w;
            int n;
            tie(w, n) = q.front();
            q.pop();
            for (int i = 0; i < w.size(); i++) {
                char remember = w[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == remember) {
                        continue;
                    }
                    w[i] = ch;

                    auto it = wordList.find(w);
                    if (it != wordList.end() && visited.find(w) == visited.end()) {
                        if (w == endWord) {
                            return n + 1;
                        }
                        visited.insert(w);
                        q.emplace(w, n + 1);
                    }
                }
                w[i] = remember;
            }
        }
        return 0;
    }
};

int main() {
    unordered_set<string> data{"hot","dot","dog","lot","log"};
    cout << Solution().ladderLength("hit", "cog", data) << endl;
    return 0;
}
