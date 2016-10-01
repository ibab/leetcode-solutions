#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <array>

using std::string;
using std::vector;
using std::unordered_set;
using std::pair;
using std::array;

class Trie {
public:

    Trie() : children_(), flag_(false) {
        children_.fill(nullptr);
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if(children_[i]) {
                delete children_[i];
            }
        }
    }

    bool flagged() {
        return flag_;
    }

    void insert(string s) {
        Trie* node = this;
        for (char c: s) {
            c = c - 'a';
            if (!node->children_[c]) {
                node->children_[c] = new Trie();
            }
            node = node->children_[c];
        }
        node->flag_ = true;
    }

    bool matches(char c) {
        c = c - 'a';
        return children_[c];
    }

    Trie* advance(char c) {
        c = c - 'a';
        return children_[c];
    }

private:
    array<Trie*, 26> children_;
    bool flag_;
};


class Solution {
    std::unordered_set<string> solution_;
public:
    void recurse(vector<vector<char>>& board,
                           int i,
                           int j,
                           Trie* trie,
                           std::string result) {
        vector<string> results;
        char c = board[i][j];
        if (trie->matches(c)) {
            board[i][j] = 'X';
            result.push_back(c);

            Trie* advanced = trie->advance(c);
            if (advanced->flagged()) {
                solution_.insert(result);
            }

            std::vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (const auto& p: directions) {
                int x = i + p.first;
                int y = j + p.second;
                if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                    continue;
                }
                if(board[x][y] == 'X') {
                    continue;
                }
                recurse(board, x, y, advanced, result);
            }
            board[i][j] = c;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& x: words) {
            trie->insert(x);
        }
        solution_ = unordered_set<string>();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                recurse(board, i, j, trie, "");
            }
        }
        delete trie;
        return std::vector<string>(solution_.begin(), solution_.end());
    }
};

int main() {
    vector<vector<char>> board{{'a', 'a'}};
    vector<string> words{"aa"};
    std::cout << Solution().findWords(board, words)[0] << std::endl;
    return 0;
}
