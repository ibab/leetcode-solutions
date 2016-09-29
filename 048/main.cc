class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int shell = 0; shell < (n + 1) / 2; shell++) {
            for (int offset = shell; offset < n - (shell + 1); offset++) {
                int tmp = matrix[offset][shell];
                matrix[offset][shell] = matrix[n - shell - 1][offset];
                matrix[n - shell - 1][offset] = matrix[n - offset - 1][n - shell - 1];
                matrix[n - offset - 1][n - shell - 1] = matrix[shell][n - offset - 1];
                matrix[shell][n - offset - 1] = tmp;
            }
        }
    }
};

/*
[1][4][4][4]
[1][ ][ ][3]
[1][ ][ ][3]
[2][2][2][3]
*/
