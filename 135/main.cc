#include <vector>
#include <numeric>
#include <iostream>

using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        std::vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = std::max(candy[i + 1] + 1, candy[i]);
            }
        }
        return std::accumulate(candy.begin(), candy.end(), 0);
    }
};

int main() {
    std::vector<int> data{2, 7, 4, 2, 1, 7, 4, 2, 7, 1, 8};
    std::cout << Solution().candy(data) << std::endl;
    return 0;
}
