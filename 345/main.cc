#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    bool isVowel(char c) {
        switch(c) {
            case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
            case 'A':
            case 'I':
            case 'U':
            case 'E':
            case 'O':
                return true;
            default:
                return false;
        }
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {

            for (; !isVowel(s[left]) && left < s.size(); left++);
            for (; !isVowel(s[right]) && right >= 0; right--);
            if (left < right) {
                std::swap(s[left], s[right]);
            }
            left++;
            right--;
        }
        return s;
    }
};

int main() {
    std::cout << Solution().reverseVowels("leetcode") << std::endl;
    return 0;
}
