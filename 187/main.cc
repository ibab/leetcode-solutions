class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::unordered_map<std::string, bool> map;
        std::vector<std::string> results;
        for (int i = 0; i <= (int)s.size() - 10; i++) {
            std::string sub = s.substr(i, 10);
            auto iter = map.find(sub);
            if (iter != map.end()) {
                if (!iter->second) {
                    results.push_back(sub);
                    iter->second = true;
                }
            } else {
                map[sub] = false;
            }
        }
        return results;
    }
};
