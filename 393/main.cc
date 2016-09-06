#include <vector>
#include <iostream>

class Solution {
public:

    int utf8Type(int data) {
        if (data >> 7 == 0) {
            return 1;
        } else if (data >> 5 == 0b110) {
            return 2;
        } else if (data >> 4 == 0b1110) {
            return 3;
        } else if (data >> 3 == 0b11110) {
            return 4;
        } else {
            return -1;
        }
    }

    int hasHeader(int data) {
        return data >> 6 == 2;
    }

    bool validUtf8(std::vector<int>& data) {
        int pos = 0;
        while (pos < data.size()) {
            int type = utf8Type(data[pos]);
            if (type == -1) {
                return false;
            }
            for (int i = 1; i < type; i++) {
                if (!hasHeader(data[++pos])) {
                    return false;
                }
            }
            pos++;
        }
        return true;
    }
};

int main() {
    std::vector<int> input{197, 130, 1};
    std::cout << Solution().validUtf8(input) << std::endl;
    return 0;
}
