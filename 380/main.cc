// Problem 380 - Insert Delete GetRandom O(1)
//
// Design a data structure that supports all following operations in average O(1) time.
// 
// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each
//            element must have the same probability of being returned.

#include <vector>
#include <random>
#include <iostream>

// BEGIN
// The idea is to use a hash table as the basis for the data structure.
// When the getRandom method is called, we sample an index from the histogram
// of vector lengths in the hash table.
// If we pick an element in that vector at random, the overall probability to
// pick an element will be uniform.
// The runtime of the getRandom method is O(1), as we iterate over the fixed
// length of the internal hash table storage.
class RandomizedSet {
public:
    RandomizedSet()
     : size_(20),
       data_(std::vector<std::vector<int>*>(size_)) {
         for (int i = 0; i < data_.size(); i++) {
             data_[i] = new std::vector<int>;
         }
    }

    ~RandomizedSet() {
        for (int i = 0; i < data_.size(); i++) {
            delete data_[i];
        }
    }

    bool insert(int val) {
        int idx = static_cast<unsigned int>(val) % size_;
        if (std::find(data_[idx]->begin(), data_[idx]->end(), val) != data_[idx]->end()) {
            return false;
        }
        data_[idx]->push_back(val);
        return true;
    }

    bool remove(int val) {
        int idx = static_cast<unsigned int>(val) % size_;
        auto* vec = data_[idx];
        if (std::find(data_[idx]->begin(), data_[idx]->end(), val) != data_[idx]->end()) {
            std::cout << "Found and removing" << std::endl;
            vec->erase(std::remove(vec->begin(), vec->end(), val), vec->end());
            return true;
        }
        return false;

    }

    int getRandom() {
        int total = 0;
        for (int i = 0; i < data_.size(); i++) {
            total += data_[i]->size();
        }
        std::vector<double> histogram(size_);
        double running = 0;
        for (int i = 0; i < data_.size(); i++) {
            running += 1.0 * data_[i]->size() / total;
            histogram[i] = running; 
        }
        std::uniform_real_distribution<double> rand(0, 1);
        double prob = rand(gen_);
        int i = 0;
        for (; i < histogram.size(); i++) {
            if (histogram[i] > prob) {
                break;
            }
        }
        std::uniform_int_distribution<int> randint(0, data_[i]->size() - 1);
        int entry = randint(gen_);

        return data_[i]->at(entry);
    }
    
    int size_;
    std::vector<std::vector<int>*> data_;
    std::default_random_engine gen_;
};
// END

int main() {
    RandomizedSet rs;
    rs.insert(42);
    rs.insert(122);
    rs.insert(0);
    rs.insert(-42);
    std::cout << rs.getRandom() << std::endl;
    std::cout << rs.getRandom() << std::endl;
    std::cout << rs.getRandom() << std::endl;
    std::cout << rs.getRandom() << std::endl;
    std::cout << rs.getRandom() << std::endl;

    return 0;
}
