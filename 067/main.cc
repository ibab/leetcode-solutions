class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        stringstream out;
        int i = 0;
        while (i < a.size() || i < b.size() || carry) {
            int c1 = i < a.size() ? a[a.size() - i - 1] - '0' : 0;
            int c2 = i < b.size() ? b[b.size() - i - 1] - '0' : 0;
            out << (carry + c1 + c2) % 2;
            carry = (carry + c1 + c2) / 2;
            i++;
        }
        string result = out.str();
        reverse(result.begin(), result.end());
        return result;
    }
};
