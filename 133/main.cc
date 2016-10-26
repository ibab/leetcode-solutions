/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    void bfs(UndirectedGraphNode* node, function<void(UndirectedGraphNode*)> func) {
        unordered_set<UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> q;
        q.push(node);

        while (!q.empty()) {
            UndirectedGraphNode* n = q.front();
            q.pop();
            visited.insert(n);
            func(n);
            for (auto& x: n->neighbors) {
                if (visited.find(x) == visited.end()) {
                    q.push(x);
                }
            }
        }
    }

    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copy;

        // First pass to create copies
        bfs(node, [&copy](UndirectedGraphNode* node) {
            copy[node] = new UndirectedGraphNode(node->label);
        });

        // Second pass to create links
        bfs(node, [&copy](UndirectedGraphNode* node) {
            auto& vec = copy[node]->neighbors;
            vec.clear();
            for (auto& x: node->neighbors) {
                vec.push_back(copy[x]);
            }
        });
        return copy[node];
    }
};
