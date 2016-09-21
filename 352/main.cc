#include <vector>
#include <set>
#include <map>

struct Interval {

    Interval() : start(0), end(0) {}
    Interval(int a, int b) : start(a), end(b) {}

    int start;
    int end;
};


// We want to detect interval collisions using a binary tree.
// Overriding < is easier than specializing the intervals_ member.
bool operator<(const Interval& a, const Interval& b){
     return a.end < b.start;
}
 
// The idea behind this solution is to use an interval tree to detect whether a
// new value is already contained in the existing intervals.
// It it's not, then we either create a new interval or merge the value with
// existing intervals.
// We keep track of the 2 possible extension points for each interval (left
// edge -1 and right edge +1) in maps that map back to the corresponding interval.
// This allows us to quickly find all intervals that need to be merged.
// There are 4 different cases:
//  - Value extends both left and right interval
//  - Value extends left interval
//  - Value extends right interval
//  - Value extends no interval, and creates its own new interval
//  These are handled separately.
class SummaryRanges {
public:
    // We just make use of the default member constructors.
    SummaryRanges() {}

    void addNum(int val) {
        Interval interval(val, val);
        if (intervals_.find(interval) != intervals_.end()) {
            // Value is contained in an interval.
            // Nothing needs to be done.
            return;
        }

        Interval left_interval;
        Interval right_interval;
        bool found_left = false;
        bool found_right = false;

        if (left_.find(val) != left_.end()) {
            right_interval = left_[val];
            found_right = true;
        }
        if (right_.find(val) != right_.end()) {
            left_interval = right_[val];
            found_left = true;
        }

        Interval new_interval;
        if (found_left && found_right) {
            // Merge both intervals.
            right_.erase(val);
            left_.erase(val);
            intervals_.erase(right_interval);
            intervals_.erase(left_interval);
            new_interval = Interval(left_interval.start, right_interval.end);
        } else if (found_left) {
            // Merge with interval on the left
            right_.erase(val);
            left_.erase(left_interval.start - 1);
            intervals_.erase(left_interval);
            new_interval = Interval(left_interval.start, val);
        } else if (found_right) {
            // Merge with interval on the right
            right_.erase(right_interval.end + 1);
            left_.erase(val);
            intervals_.erase(right_interval);
            new_interval = Interval(val, right_interval.end);
        } else {
            // Create new interval
            new_interval = Interval(val, val);
        }

        // Register the new interval
        left_[new_interval.start - 1] = new_interval;
        right_[new_interval.end + 1] = new_interval;
        intervals_.insert(new_interval);
    }

    std::vector<Interval> getIntervals() {
        return std::vector<Interval>(intervals_.begin(), intervals_.end());
    }
private:

    std::set<Interval> intervals_;
    std::map<int, Interval> left_;
    std::map<int, Interval> right_;
};

int main() {
    SummaryRanges ranges;
    ranges.addNum(1);
    ranges.addNum(4);
    ranges.addNum(2);
    ranges.addNum(3);
    return 0;
}
