
class Node {
public:
    Node(int v) : val(v), smaller(0), equal(1), left(nullptr), right(nullptr) {}
    int val;
    int smaller;
    int equal;
    Node* left;
    Node* right;

    ~Node() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }

    // Inserts an element and increases counters
    void insert(int n) {
        if (n < val) {
            if (!left) {
                left = new Node(n);
            } else {
                left->insert(n);
            }
            smaller++;
        } else if (n > val) {
            if (!right) {
                right = new Node(n);
            } else {
                right->insert(n);
            }
        } else {
            equal++;
        }
    }

    // Returns element at index i in sorted order
    int index(int i) {
        if (i < smaller) {
            return left->index(i);
        } else if (i >= smaller + equal) {
            return right->index(i - smaller - equal);
        } else {
            return val;
        }
    }
};

class MedianFinder {
public:

    MedianFinder() : tree(nullptr), count(0) {}

    // Adds a number into the data structure.
    void addNum(int num) {
        if (!tree) {
            tree = new Node(num);
        } else {
            tree->insert(num);
        }
        count++;
    }

    // Returns the median of current data stream
    double findMedian() {
        if (count % 2 == 1) {
            return tree->index(count / 2);
        } else {
            return 0.5 * (tree->index(count / 2 - 1) + tree->index(count / 2));
        }
    }

private:
    Node* tree;
    int count;
};

