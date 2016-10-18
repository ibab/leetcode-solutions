class Solution {
public:
    int minCut(string s) {
        std::stringstream ss;
        // Insert # characters to make things easier.
        for (int i = 0; i < s.size(); i++) {
            ss << s[i];
            if (i < s.size() - 1) {
                ss << '#';
            }
        }
        s = ss.str();

        // Create one edge from the start to the end of each palindrome.
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            while (s[left] == s[right] && left >= 0 && right < s.size()) {
                if (s[left] != '#') {
                    graph[left].push_back(right + 2);
                }
                left--;
                right++;
            }
        }

        // BFS traversal of the graph.
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vector<bool> visited(s.size(), false);
        visited[0] = true;
        while (!q.empty()) {
            int pos;
            int n;
            tie(pos, n) = q.front();
            q.pop();
            for (int x: graph[pos]) {
                if (x > s.size()) {
                    return n;
                }
                if (!visited[x]) {
                    q.emplace(x, n + 1);
                    visited[x] = true;
                }
            }
        }
        return -1;
    }
};
