class LRUCache{
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        int val = map[key]->second;
        set(key, val);
        return val;
    }

    void set(int key, int value) {
        if (map.find(key) != map.end()) {
            erase(key);
        }
        if (container.size() == cap) {
            int k = container.back().first;
            container.pop_back();
            map.erase(k);
        }
        container.emplace_front(key, value);
        map[key] = container.begin();
    }

    void erase(int key) {
        if (map.find(key) != map.end()) {
            container.erase(map[key]);
            map.erase(key);
        }
    }
private:
    int cap;
    list<pair<int, int>> container;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};
