#include <iostream>
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i < prime.size(); i++) {
            if (!prime[i]) {
                continue;
            }
            if (i * i > prime.size()) {
                break;
            }
            for (int j = i * i; j <= prime.size(); j += i) {
                prime[j] = false;
            }
        }
        int count = 0;
        for (int i = 0; i < prime.size(); i++) {
            if (prime[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    std::cout << Solution().countPrimes(1000000) << std::endl;
    return 0;
}
