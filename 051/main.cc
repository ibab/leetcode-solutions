class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        stringstream ss;
        for (int i = 0; i < n; i++) {
            ss << ".";
        }
        // Whether this row is occupied.
        occupied[0] = vector<bool>(n, false);
        // Whether this column is occupied.
        occupied[1] = vector<bool>(n, false);
        // Whether this diagonal is occupied.
        occupied[2] = vector<bool>(2 * n - 1, false);
        // Whether this diagonal is occupied.
        occupied[3] = vector<bool>(2 * n - 1, false);
        // Current board.
        current = vector<string>(n, ss.str());
        // Start out in the top row and advance row by row.
        for (int i = 0; i < n; i++) {
            recurse(0, i);
        }
        return results;
    }
    
    void recurse(int x, int y) {
        int n = occupied[0].size();
        current[x][y] = 'Q';
        occupied[0][x] = true;
        occupied[1][y] = true;
        occupied[2][x + y] = true;
        occupied[3][x + (n - y - 1)] = true;
        
        if (x == n - 1) {
            results.push_back(current);
        } else {
            for (int i = 0; i < n; i++) {
                if (!occupied[0][x + 1] &&
                    !occupied[1][i] &&
                    !occupied[2][x + 1 + i] &&
                    !occupied[3][x + 1 + (n - i - 1)]) {
                      recurse(x + 1, i);
                }
            }
        }
        
        // Undo everything to backtrack to the last state.
        occupied[0][x] = false;
        occupied[1][y] = false;
        occupied[2][x + y] = false;
        occupied[3][x + (n - y - 1)] = false;
        current[x][y] = '.';
    }
private:
    vector<string> current;
    array<vector<bool>, 4> occupied;
    vector<vector<string>> results;
};
