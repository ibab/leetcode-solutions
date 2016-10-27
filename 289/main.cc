class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int count = 0;
                for (auto& p: directions) {
                    int i_ = i + p.first;
                    int j_ = j + p.second;

                    if (i_ < 0 || i_ >= board.size() || j_ < 0 || j_ >= board[0].size()) {
                        continue;
                    }

                    if (board[i_][j_] & 1) {
                        count++;
                    }
                }
                if (board[i][j] & 1) {
                    if (count == 2 || count == 3) {
                        board[i][j] |= 2;
                    }
                } else if (count == 3) {
                    board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
