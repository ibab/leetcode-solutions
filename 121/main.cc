class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        for (int i = 0; i < prices.size() - 1; i++) {
            prices[i] = prices[i + 1] - prices[i];
        }
        prices.pop_back();
        int s = 0;
        int max_seen = 0;
        for (int i = 0; i < prices.size(); i++) {
            s = max(0, s + prices[i]);
            max_seen = max(max_seen, s);
        }
        return max_seen;
    }
};
