class Solution {
public:
    bool match(std::string a, std::string b) {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        return a == b;
    }
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (!match(s1, s2)) {
            return false;
        }
        
        for (int i1 = 1; i1 < s2.size(); i1++) {
            int i2 = s2.size() - i1;
            if (isScramble(s2.substr(0, i1), s1.substr(0, i1)) && 
                isScramble(s2.substr(i1, i2), s1.substr(i1, i2))) {
                return true;
            }
            if (isScramble(s2.substr(0, i1), s1.substr(i2, i1)) && 
                isScramble(s2.substr(i1, i2), s1.substr(0, i2))) {
                return true;
            }
        }
        return false;
    }
};
