class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long total = (C - A) * (D - B) + (G - E) * (H - F);
        long x1 = max(A, E);
        long y1 = max(F, B);
        long x2 = min(C, G);
        long y2 = min(D, H);
        long d1 = (x2 - x1);
        long d2 = (y2 - y1);
        if (d1 > 0 && d2 > 0) {
            total -= d1 * d2;
        }
        return total;
    }
};
