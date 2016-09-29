class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        int sum_A = std::accumulate(A.begin(), A.end(), 0);
        int current = 0;
        int max_seen = 0;

        for (int i = 0; i < A.size(); i++) {
            current += i * A[i];
        }
        max_seen = current;

        for (int pos = A.size() - 1; pos >= 1; pos--) {
            current += sum_A - A.size() * A[pos];
            if (current > max_seen) {
                max_seen = current;
            }
        }
        return max_seen;
    }
};
