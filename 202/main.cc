class Solution {
public:
    int step(int n) {
        if (n == 0) {
            return 0;
        } 
        int k = (n % 10);
        return k * k + step(n / 10);
    }
    bool isHappy(int n) {
        unordered_set<int> m;
        m.insert(n);
        while (n != 1) {
            n = step(n);
            if (m.find(n) != m.end()) {
                return false;
            }
            m.insert(n);
        }
        return true;
    }
};
