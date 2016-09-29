class Solution {
public:
    int integerReplacement(int n_) {
        // Use unsigned int to avoid weirdness at INT_MAX
        // (the reference solution can apparently go above INT_MAX)
        unsigned int n = n_;
        int step = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                // If it's even, divide by 2
                n = n / 2;
            } else if (n == 3) {
                // 3 is a special case, because
                // going to 1 is the goal and therefore
                // preferable to 3 -> 4 -> 2 -> 1.
                n = n - 1;
            } else {
                // Look at the binary representation of n to understand
                // the problem. Dividing by 2 is equivalent to moving left,
                // while +1/-1 are equivalent to flipping/not flipping the
                // next bit.
                // The best thing we can do is always guarantee that there's
                // a 0 bit in the next position, as this will allow us to move on.
                // Having a 1 in the next position can not be better, as it will
                // merely allow us to manipulate the next bit while taking one more
                // step.
                int next_bit = (n << 30) >> 31;
                if (next_bit) {
                    n = n + 1;
                } else {
                    n = n - 1;
                }
            }
            step++;
        }
        return step;
    }
};

int main() {
    return 0;
}
