class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> canReachWithStep{{0, {0}}};
        for (int loc: stones) {
            for (int laststep: canReachWithStep[loc]) {
                for (int step: {laststep - 1, laststep, laststep + 1}) {
                    if (step >= 1) {
                        canReachWithStep[loc + step].insert(step);
                    }
                }
            }
        }

        return canReachWithStep[stones.back()].size() > 0;
    }
};
