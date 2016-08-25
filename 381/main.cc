
#include <vector>
#include <random>
#include <iostream>

// BEGIN
// Same as RandomizedSet in 380, except that we always append, even if such an
// element already exists, and that we only remove a single value
class RandomizedCollection {
public:
    RandomizedCollection()
     : size_(20),
       data_(std::vector<std::vector<int>*>(size_)) {
         for (int i = 0; i < data_.size(); i++) {
             data_[i] = new std::vector<int>;
         }
    }

    ~RandomizedCollection() {
        for (int i = 0; i < data_.size(); i++) {
            delete data_[i];
        }
    }

    bool insert(int val) {
        int idx = static_cast<unsigned int>(val) % size_;
        bool ret = true;
        if (std::find(data_[idx]->begin(), data_[idx]->end(), val) != data_[idx]->end()) {
            ret = false;
        }
        data_[idx]->push_back(val);
        return ret;
    }

    bool remove(int val) {
        int idx = static_cast<unsigned int>(val) % size_;
        auto* vec = data_[idx];
        if (std::find(data_[idx]->begin(), data_[idx]->end(), val) != data_[idx]->end()) {
            vec->erase(std::find(vec->begin(), vec->end(), val));
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
    RandomizedCollection rs;
    rs.insert(42);
    rs.insert(122);
    rs.insert(122);
    rs.insert(122);
    rs.insert(122);
    rs.insert(122);
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
