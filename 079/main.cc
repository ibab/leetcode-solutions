class Solution {
public:
    Solution() {}
    bool exist(vector<vector<char>>& board, string& word) {
        board_ = board;
        word_ = word;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (recurse(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool recurse(int i, int j, int idx) {
        if (board_[i][j] != word_[idx]) {
            // This can't be a match.
            return false;
        }
        if (idx == word_.size() - 1) {
            // Word has been completed.
            return true;
        }
        char remember = board_[i][j];
        board_[i][j] = '\0';
        vector<pair<int, int>> coords = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (pair<int, int>& x: coords) {
            int i_ = i + x.first;
            int j_ = j + x.second;
            if (i_ >= 0 && i_ < board_.size() && j_ >= 0 && j_ < board_[0].size()) {
                if (recurse(i_, j_, idx + 1)) {
                    return true;
                }
            }
        }
        board_[i][j] = remember;
        return false;
    }
private:
    string word_;
    vector<vector<char>> board_;
};
