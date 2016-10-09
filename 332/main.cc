
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using std::vector;
using std::string;
using std::unordered_map;
using std::multiset;
using std::pair;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        graph_ = unordered_map<string, multiset<string>>();
        for (auto& t: tickets) {
            graph_[t.first].insert(t.second);
        }
        vector<string> tour = vector<string>(tickets.size() + 1);
        auto iter = tour.rbegin();
        visit("JFK", iter);
        return tour;
    }

    void visit(string node, vector<string>::reverse_iterator& iter) {
        auto& next_nodes = graph_[node];
        while (!next_nodes.empty()) {
            auto next = next_nodes.begin();
            next_nodes.erase(next);
            visit(*next, iter);
        }
        *iter = node;
        iter = next(iter);
    }
private:
    unordered_map<string, multiset<string>> graph_;
};

int main() {
    return 0;
}
