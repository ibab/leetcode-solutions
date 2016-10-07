#include <vector>
#include <iostream>

class Solution {
public:
    template<typename Container>
    void moveZeroes(Container& nums) {
        typedef typename Container::iterator iter;
        iter i = nums.begin();
        iter j = i;
        // Copy from next non-zero location.
        while (j != nums.end()) {
            if (*j != 0) {
                *i = *j;
                i++;
            }
            j++;
        }
        // Fill rest with zeros.
        for (; i < j; i++) {
            *i = 0;
        }
    }
};

int main() {
    std::vector<int> a{0, 1, 2, 3, 0, 4, 5, 0, 6, 0, 7, 8};
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
