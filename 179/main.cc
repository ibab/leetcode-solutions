class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        auto func = [](const string& a, const string& b) {
            return a + b > b + a;
        };
        vector<string> words;
        for (auto& x: nums) {
            words.push_back(to_string(x));
        }
        sort(words.begin(), words.end(), func);
        stringstream result;
        for (auto& x: words) {
            result << x;
        }
        string s = result.str();
        return s[0] == '0' ? "0" : s;
    }
};
