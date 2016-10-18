class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += unique(i);
        }
        return result + 1;
    }

    int unique(int n) {
        if (n == 0) {
            return 0;
        }
        if (n > 9) {
            return 0;
        }
        int result = 9;
        int factor = 9;
        for (int i = 1; i < n; i++) {
            result *= factor;
            factor--;
        }
        return result;
    }
};
