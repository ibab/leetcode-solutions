#include <string>
#include <iostream>

class Solution {
public:
    std::string encode(int number, std::string single, std::string middle, std::string full) {
        switch (number) {
            case 1:
                return single;
            case 2:
                return single + single;
            case 3:
                return single + single + single;
            case 4:
                return single + middle;
            case 5:
                return middle;
            case 6:
                return middle + single;
            case 7:
                return middle + single + single;
            case 8:
                return middle + single + single + single;
            case 9:
                return single + full;
            case 10:
                return full;
        }
        return "";
    }
    std::string intToRoman(int num) {
        std::string result = "";
        if (num >= 1000) {
            result += encode(num / 1000 % 10, "M", "", "");
        }
        if (num >= 100) {
            result += encode(num / 100 % 10, "C", "D", "M");
        }
        if (num >= 10) {
            result += encode(num / 10 % 10, "X", "L", "C");
        }
        if (num >= 1) {
            result += encode(num % 10, "I", "V", "X");
        }
        return result;
    }
};

int main() {

    Solution solution;
    std::cout << solution.intToRoman(2016) << std::endl;
    return 0;
}
