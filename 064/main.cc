#include <vector>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        std::vector<vector<int>> distance(
            grid.size(),
            std::vector<int>(grid[0].size(), INT_MAX));
        // Set initial cost
        distance[0][0] = grid[0][0];

        int M = distance.size();
        int N = distance.front().size();

        // Interpret the array as a graph with directed edges leading to the
        // elements right and below of the current one.
        // Walk through the elements, always setting the adjacent distances to
        // the minimum of the current distance and the distance that can be
        // achieved by coming from this vertex.
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // Look to the right.
                if (i < M - 1) {
                    if (distance[i + 1][j] > distance[i][j] + grid[i + 1][j]) {
                        distance[i + 1][j] = distance[i][j] + grid[i + 1][j];
                    }
                }
                // Look downwards.
                if (j < N - 1) {
                    if (distance[i][j + 1] > distance[i][j] + grid[i][j + 1]) {
                        distance[i][j + 1] = distance[i][j] + grid[i][j + 1];
                    }
                }
            }
        }
        return distance[M - 1][N - 1];
    }
};

int main() {
    return 0;
}
