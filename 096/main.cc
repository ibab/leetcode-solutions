class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n + 1, 0);
        memo[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                memo[i] += memo[j] * memo[i - j - 1];
            }
        }
        return memo.back();
    }
};
