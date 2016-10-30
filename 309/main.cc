class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int canbuy = 0;
        int bought = INT_MIN;
        int wait = INT_MIN;
        for (int p: prices) {
            int b = max(canbuy - p, bought);
            int w = bought + p;
            int cb = max(canbuy, wait);
            bought = b;
            wait = w;
            canbuy = cb;
        }
        return max(canbuy, wait);
    }
};
