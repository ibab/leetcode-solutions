class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // It's enough to keep track of the gain per station.
        for (int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
        }
        // Initialize the computation by finding the needed
        // gas for a given station (here, i = 0).
        int need = 0;
        int g = 0;
        for (int i = 0; i < gas.size(); i++) {
            g += gas[i];
            if (g < -need) {
                need = -g;
            }
        }
        if (need <= 0) {
            return 0;
        }
        // Next, we can compute the needed gas for station i - 1
        // by making use of the needed gas for station i.
        for (int i = gas.size() - 1; i >= 1; i--) {
            need = need - gas[i];
            if (need <= 0) {
                return i;
            }
        }
        return -1;
    }
};
