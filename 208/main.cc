class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : flag_(false) {
        children_.fill(nullptr);
    }

    ~TrieNode() {
        for (int i = 0; i < children_.size(); i++) {
            if (!children_[i]) {
                delete children_[i];
            }
        }
    }

    TrieNode* get(char c) {
        return children_[c - 'a'];
    }

    void set(char c, TrieNode* node) {
        children_[c - 'a'] = node;
    }

    void flag() {
        flag_ = true;
    }

    bool flagged() {
        return flag_;
    }

private:
    array<TrieNode*, 26> children_;
    bool flag_;
};

class Trie {
public:
    Trie() : root(new TrieNode()) {
    }

    ~Trie() {
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (char c: word) {
            if (!node->get(c)) {
                node->set(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->flag();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (char c: word) {
            if (!node->get(c)) {
                return false;
            }
            node = node->get(c);
        }
        return node->flagged();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c: prefix) {
            if (!node->get(c)) {
                return false;
            }
            node = node->get(c);
        }
        return true;
    }

private:
    TrieNode* root;
};
