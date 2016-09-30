class Solution {
public:
    typedef pair<int, int> Person;
    vector<Person> reconstructQueue(vector<Person>& people) {
        auto comp = [](Person a, Person b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        std::sort(people.begin(), people.end(), comp);
        std::vector<Person> result;
        for (auto& p: people) {
            result.insert(result.begin() + p.second, p);
        }
        return result;
    }
};
