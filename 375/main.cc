#include <vector>
#include <iostream>

class Solution {
public:

    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> solution(n + 1, std::vector<int>(n + 1));
        for (int i = 0; i <= n; i++) {
            solution[i][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                int s = j;
                int e = j + i;
                int min = INT_MAX;
                for (int k = j; k < j + i; k++) {
                    int num = k + std::max(solution[s][k - 1], solution[k + 1][e]);
                    min = std::min(min, num);
                }
                solution[s][e] = min;
            }
        }

        return solution[1][n];
    }
};

int main() {
    std::cout << Solution().getMoneyAmount(20) << std::endl;
    return 0;
}
