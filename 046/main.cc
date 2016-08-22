

#include <vector>
#include <iostream>

template <typename t>
std::ostream& operator<<(std::ostream& os, std::vector<t>& vec) {
    os << "[";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}


class Solution {

    public:
    std::vector<std::vector<int>> permute(std::vector<int> input) {
        std::vector<std::vector<int>> answers;
        std::sort(input.begin(), input.end());
        answers.push_back(input);

        while (true) {
            int k = -1;
            for (int i = input.size() - 2; i >= 0; i--) {
                if (input[i] < input[i + 1]) {
                    k = i;
                    break;
                }
            }
            if (k == -1) {
                return answers;
            }

            int l = input.size() - 1;
            while (input[l] <= input[k]) {
                l--;
            }

            std::swap(input[k], input[l]);
            std::reverse(input.begin() + (k + 1), input.end());
            answers.push_back(input);
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> a{1, 2, 3};
    auto answer = solution.permute(a);
    for (auto& x: answer) {
        std::cout << x << std::endl;
    }
    std::cout << answer.size() << std::endl;
    return 0;
}
