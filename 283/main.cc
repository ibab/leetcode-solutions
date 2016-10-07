#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                j++;
            } else {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        for (; i < j; i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    std::vector<int> a{1, 2, 3, 0, 4, 5, 0, 6, 0, 7, 8};
    Solution().moveZeroes(a);
    std::cout << "[";
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i];
        if (i != a.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    return 0;
}
