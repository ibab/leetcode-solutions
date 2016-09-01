
class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int curr = left + (right - left) / 2;
            int out = guess(curr);
            if (out == 1) {
                left = curr + 1;
            } else if (out == -1) {
                right = curr;
            } else {
                return curr;
            }
        }
        return left;
    }
};
