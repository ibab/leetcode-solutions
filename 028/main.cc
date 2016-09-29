#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (needle.size() > haystack.size()) {
            return -1;
        }

        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            bool found = true;
            for (int j = 0; j < needle.size(); j++) {
                if (i + j >= haystack.size() || haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}
