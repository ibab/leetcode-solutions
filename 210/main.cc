class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        temporary = vector<bool>(numCourses, false);
        permanent = vector<bool>(numCourses, false);
        result.clear();

        unordered_map<int, vector<int>> graph;

        for (auto& p: prerequisites) {
            graph[p.first].push_back(p.second);
        }

        for (int i = 0; i < permanent.size(); i++) {
            if (!permanent[i]) {
                if(recurse(i, graph)) {
                    return vector<int>();
                }
            }
        }

        return result;
    }

    bool recurse(int i, unordered_map<int, vector<int>>& graph) {
        if (temporary[i]) {
            return true;
        }
        if (!permanent[i]) {
            temporary[i] = true;
            for (const int& x: graph[i]) {
                if(recurse(x, graph)) {
                    return true;
                }
            }
            permanent[i] = true;
            temporary[i] = false;
            result.push_back(i);
        }
        return false;
    }

private:
    vector<bool> temporary;
    vector<bool> permanent;
    vector<int> result;
};
