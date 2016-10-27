class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '.';
                q.emplace(i, 0);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                board[i][board[0].size() - 1] = '.';
                q.emplace(i, board[0].size() - 1);
            }
        }
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                board[0][i] = '.';
                q.emplace(0, i);
            }
            if (board[board.size() - 1][i] == 'O') {
                board[board.size() - 1][i] = '.';
                q.emplace(board.size() - 1, i);
            }
        }

        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int i;
            int j;
            tie(i, j) = q.front();
            q.pop();
            for (auto& p: directions) {
                int i_ = i + p.first;
                int j_ = j + p.second;
                if (i_ >= 0 && i_ < board.size() && j_ >= 0 && j_ < board[0].size() && board[i_][j_] == 'O') {
                    board[i_][j_] = '.';
                    q.emplace(i_, j_);
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
