class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> aux;
        for (int x: nums) {
            auto it = lower_bound(aux.begin(), aux.end(), x);
            if (it == aux.end()) {
                aux.push_back(x);
            } else {
                *it = min(*it, x);
            }
        }
        return aux.size();
    }
};
