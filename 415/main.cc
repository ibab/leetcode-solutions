class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        if (num2.size() < num1.size()) {
            std::swap(num1, num2);
        }
        std::stringstream results;
        int diff = num2.size() - num1.size();
        for (int i = num2.size() - 1; i >= 0; i--) {
            int a = num2[i] - '0';
            int b;
            if (i - diff >= 0) {
                b = num1[i - diff] - '0';
            } else {
                b = 0;
            }
            int num = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            results << num;
        }
        if (carry) {
            results << carry;
        }
        std::string result = results.str();
        std::reverse(result.begin(), result.end());
        return result;
    }
};
