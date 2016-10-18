class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> results(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            results[i] = results[i & (i - 1)] + 1;
        }
        return results;
    }
};
