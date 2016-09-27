
// A super inefficient solution because I was lazy.
class Solution {
public:

    string multiply(string num1, string num2) {
        std::string result = "0";
        // For each digit, add num2 that many times to itself and append the
        // right number of zeros.
        for (int i = 0; i < num1.size(); i++) {
            int a = num1[i] - '0';
            std::string left = "0";
            std::string right = num2;
            for (int j = 0; j < a; j++) {
                left = add(left, right);
            }
            left.resize(left.size() + num1.size() - i - 1, '0');
            result = add(result, left);
        }
        return result;
    }

    string add(string num1, string num2) {
        std::stringstream ss;
        if (num1.size() > num2.size()) {
            std::string tmp = num1;
            num1 = num2;
            num2 = tmp;
        }

        int carry = 0;
        int diff = num2.size() - num1.size();
        for (int i = num1.size() - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            int b = num2[i + diff] - '0';
            ss << (int)((a + b + carry) % 10);
            carry = (a + b + carry) / 10;
        }
        for (int i = diff - 1; i >= 0; i--) {
            int b = num2[i] - '0';
            ss << (int)((b + carry) % 10);
            carry = (b + carry) / 10;
        }
        if (carry) {
            ss << carry;
        }
        std::string out = ss.str();
        std::reverse(out.begin(), out.end());

        // Remove extra zeros in the beginning.
        int i;
        for (i = 0; i < out.size() - 1 && out[i] == '0'; i++) {}
        return std::string(out.begin() + i, out.end());
    }
};
