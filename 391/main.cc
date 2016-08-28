#include <climits>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <iostream>

using std::vector;
using std::tuple;
using std::get;
using std::make_tuple;

class Solution {
  public:
  // This is a sweep line algorithm solution. The start and end x coordinates
  // of the rectangles are traversed from left to right.
  // At each step, we make sure that the sum of all heights of the currently
  // active rectangles sum up to the maximum value. At the same time, we have
  // to make sure that there are no intersections in the y direction.
  // This is accomplished with O(log n) time complexity per lookup
  // through the use of a binary search tree.
  // This means that the total time complexity of the solution is O(n log n).
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    std::sort(rectangles.begin(), rectangles.end(),
              [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

    auto compare_x = [](const tuple<int, int>& a, const tuple<int, int>& b) {
      if (get<0>(a) == get<0>(b)) {
        // Make sure that existing rectangles always appear before new ones
        return get<1>(a) > get<1>(b);
      }
      return get<0>(a) > get<0>(b);
    };

    // This priority queue keeps track of where rectangles start and end
    std::priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                        decltype(compare_x)>
        events(compare_x);

    // Add rectangles to priority queue,
    // so that they appear from left to right.
    // Also, compute the maximum y boundaries of the rectangle set.
    int y_min = INT_MAX;
    int y_max = INT_MIN;
    for (int i = 0; i < rectangles.size(); i++) {
      events.push(make_tuple(rectangles[i][0], i));
      events.push(make_tuple(rectangles[i][2], i));

      y_min = std::min(y_min, rectangles[i][1]);
      y_max = std::max(y_max, rectangles[i][3]);
    }
    int max_height = y_max - y_min;

    auto compare = [](const tuple<int, int>& a, const tuple<int, int>& b) {
      return get<1>(a) <= get<0>(b);
    };

    std::set<tuple<int, int>, decltype(compare)> intervals(compare);

    int height = 0;
    while (!events.empty()) {
      int position = get<0>(events.top());

      // Look at all rectangles that start/stop at the current position
      while (!events.empty() && std::get<0>(events.top()) == position) {
        int index = get<1>(events.top());
        auto rec = rectangles[index];
        events.pop();

        auto tup = make_tuple(rec[1], rec[3]);
        if (position == rec[2]) {
          // Rectangle ends
          intervals.erase(tup);
          height -= rec[3] - rec[1];
        } else {
          // Rectangle starts
          if (intervals.find(tup) == intervals.end()) {
            intervals.insert(tup);
            height += rec[3] - rec[1];
          } else {
            // Intersection found
            return false;
          }
        }
      }
      if (!events.empty()) {
        if (max_height != height) {
          // Not enough height to be consistent with a rectangle
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
    std::vector<std::vector<int>> input;
    input.emplace_back<std::vector<int>>({1, 1, 3, 3});
    input.emplace_back<std::vector<int>>({3, 1, 4, 2});
    input.emplace_back<std::vector<int>>({3, 2, 4, 4});
    input.emplace_back<std::vector<int>>({1, 3, 2, 4});
    input.emplace_back<std::vector<int>>({2, 3, 3, 4});
    std::cout << Solution().isRectangleCover(input) << std::endl;
    return 0;
}
