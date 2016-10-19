class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> data(n, vector<int>(n, 0));
        int x = 0;
        int y = 0;
        int distance = n;
        int count = 3;
        vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int idx = 0;
        int i = 1;
        while (distance) {
            auto p = directions[idx];
            for (int j = 0; j < distance; j++) {
                data[x][y] = i;
                if (j != distance - 1) {
                  x += p.first;
                  y += p.second;
                  i++;
                }
            }
            idx = (idx + 1) % 4;
            count--;
            if (count == 0) {
                count = 2;
                distance--;
            }
        }
        return data;
    }
};
