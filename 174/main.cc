#include <vector>

using std::vector;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon.front().size();
        // Stores minimum HP needed to get to the end when
        // starting from each tile.
        // We have no need for extra health, so the lower bound is 1.
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[m - 1][n - 1] = std::max(1, -dungeon[m -1][n - 1] + 1);

        // Uses dynamic programming.
        // We traverse the dungeon from end to start, updating the cost for
        // each tile if we've found a cheaper path. We can't make use of more
        // health than we need to finish, so we limit the lower bound of the
        // cost to 1 on each tile. It's important that we traverse the dungeon
        // from the end, as otherwise we can't know how much extra health will
        // be needed to surpass all negative tiles that are still in our path.
        // This is important, as sometimes taking more damage to get a big
        // health bonus is advantageous.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Look up.
                if (i > 0) {
                    cost[i - 1][j] = std::max(1,
                        std::min(cost[i - 1][j],
                                 cost[i][j] - dungeon[i - 1][j]));
                }
                // Look left.
                if (j > 0) {
                    cost[i][j - 1] = std::max(1,
                        std::min(cost[i][j - 1],
                                 cost[i][j] - dungeon[i][j - 1]));
                }
            }
        }
        return cost[0][0];
    }
};

int main() {
    return 0;
}
