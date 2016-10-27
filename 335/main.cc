class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int a, b, c, d, e, f;
        a = b = c = d = e = f = 0;
        for (int i = x.size() - 1; i >= 0; i--) {
            f = e; e = d; d = c; c = b; b = a; a = x[i];

            // Check for d intersecting a.
            if (b > 0 && c <= a && d >= b) {
                return true;
            }

            // Check for e or f intersecting a.
            if (b > 0 && d >= b && c - e >= 0 && a >= (c - e) && f >= (d - b)) {
                return true;
            }

        }
        return false;
    }
};
