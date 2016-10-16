class Solution {
public:
    string step(const std::string& s) {
        std::stringstream ss(s);
        std::stringstream out;
        char ch;
        int curr = ss.peek() - '0';
        int count = 0;
        while (ss.get(ch)) {
            if (ch - '0' == curr) {
                count++;
            } else {
                out << count;
                out << curr;
                curr = (ch - '0');
                count = 1;
            }
        }
        out << count;
        out << curr;
        return out.str();
    }
    string countAndSay(int n) {
        std::string curr = "1";
        for (int i = 1; i < n; i++) {
            curr = step(curr);
        }
        return curr;
    }
};
