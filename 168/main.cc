class Solution {
public:
    string convertToTitle(int n) {
        std::stringstream ss;
        while (n > 0) {
            n -= 1;
            ss << (char)(n % 26 + 'A');
            n /= 26;
        }
        string s = ss.str();
        reverse(s.begin(), s.end());
        return s;
    }
};
