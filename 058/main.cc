class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.size() - 1;
        int seen = false;
        int spaces = 0;
        for (int i = last; i >= 0; i--) {
            if (s[i] == ' ') {
                if (seen) {
                    return last - i - spaces;
                } else {
                    spaces++;
                }
            } else {
                seen = true;
            }
        }
        return seen ? s.size() - spaces : 0;
    }
};
