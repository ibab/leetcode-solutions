class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        std::vector<bool> ends(s.size() + 1, false);
        ends[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (ends[i]) {
                // Only start if a word can begin here
                for (int j = i; j < s.size(); j++) {
                    std::string sub = s.substr(i, j - i + 1);
                    if(wordDict.find(sub) != wordDict.end()) {
                        ends[i + sub.size()] = true;
                    }
                }
            }
        }
        return ends.back();
    }
};
