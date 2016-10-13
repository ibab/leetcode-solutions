class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int max = 0;
        for (int i = 0; i < words.size(); i++) {
            for (char ch: words[i]) {
                mask[i] |= 1 << (ch - 'a');
            }
            for (int j = 0; j < i; j++) {
                if (!(mask[i] & mask[j])) {
                    max = std::max(max, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return max;
    }
};
