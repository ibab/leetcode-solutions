#include <vector>
#include <random>
#include <iostream>

class Solution {
public:
    Solution(std::vector<int> nums)
        : nums_(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return nums_;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::vector<int> result = nums_;
        for (int i = 0; i < result.size(); i++) {
            int k = std::uniform_int_distribution<int>(0, result.size() - (i + 1))(g);
            std::swap(result[i], result[i + k]);
        }
        return result;
    }
private:
    std::vector<int> nums_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
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

int main() {
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution solution(a);
    std::cout << solution.shuffle() << std::endl;
    std::cout << solution.reset() << std::endl;
    std::cout << solution.shuffle() << std::endl;
    std::cout << solution.shuffle() << std::endl;
    return 0;
}
