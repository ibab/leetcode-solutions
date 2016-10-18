class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& e) {
        sort(e.begin(), e.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first || (a.first == b.first && a.second >  b.second);
        });
        vector<int> result;
        for (auto& p: e) {
            auto it = lower_bound(result.begin(), result.end(), p.second);
            if (it == result.end()) {
                result.push_back(p.second);
            } else if (p.second < *it) {
                *it = p.second;
            }
        }
        return result.size();
    }
};
