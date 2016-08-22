

#include <vector>
#include <iostream>


class Solution {

    public:
    void nextPermutation(std::vector<int>& input) {
        int k = -1;
        for (int i = input.size() - 2; i >= 0; i--) {
            if (input[i] < input[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            std::sort(input.begin(), input.end());
            return;
        }

        int l = input.size() - 1;
        while (input[l] <= input[k]) {
            l--;
        }

        std::swap(input[k], input[l]);
        std::reverse(input.begin() + (k + 1), input.end());
    }
};


int main() {
    Solution solution;
    std::vector<int> a{1, 2, 3};
    solution.nextPermutation(a);
    return 0;
}
