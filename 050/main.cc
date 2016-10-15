class Solution {
public:
    double myPow(double x, long n) {
        if (n < 0) {
            return 1 / myPow(x, -n);
        } else {
            double y = 1.;
            double curr = x;
            for (int i = 0; i < 32; i++) {
                if ((n >> i) & 1) {
                    y *= curr;
                }
                curr = curr * curr;
            }
            return y;
        }
    }
};
