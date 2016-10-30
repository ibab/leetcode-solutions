#include <queue>
#include <iostream>

using std::queue;

class Solution {
public:
    typedef unsigned int uint;
    int nthUglyNumber(int n) {
        queue<uint> a;
        queue<uint> b;
        queue<uint> c;

        uint number = 1;
        a.push(2 * number);
        b.push(3 * number);
        c.push(5 * number);

        for (int i = 1; i < n; i++) {
            if (a.front() < b.front() && a.front() < c.front()) {
                number = a.front();
                a.pop();
                a.push(2 * number);
                b.push(3 * number);
                c.push(5 * number);
            } else if (b.front() < c.front()) {
                number = b.front();
                b.pop();
                b.push(3 * number);
                c.push(5 * number);
            } else {
                number = c.front();
                c.pop();
                c.push(5 * number);
            }
        }
        return number;
    }
};

int main() {

    for (int i = 0; i < 1000; i++) {
        std::cout << Solution().nthUglyNumber(1600) << std::endl;
    }
    return 0;
}

