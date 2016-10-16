class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> init;
        init.reserve(20);
        std::sort(candidates.begin(), candidates.end());
        recurse(candidates, 0, target, init, results);
        return results;
    }
private:
    // In order to skip duplicate solutions, we need to skip over all
    // following identical candidates each time we don't use a candidate.
    // This can be accomplished by iterating over all possible skipped
    // cases inside a single function call.
    // This way, we only enter this function if we've just used a candidate, so
    // we can be sure that all duplicates after the first iteration of the loop
    // must be rejected.
    void recurse(vector<int>& candidates, int start, int target, vector<int>& result, vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(result);
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                // Skip duplicate solutions.
                continue;
            }
            if (candidates[i] > target) {
                // Once a candidate is larger than target, all
                // following candidates will be as well.
                break;
            }
            result.push_back(candidates[i]);
            recurse(candidates, i + 1, target - candidates[i], result, results);
            result.pop_back();
        }
    }
};
