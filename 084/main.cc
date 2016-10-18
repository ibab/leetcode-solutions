class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights_ = heights;
        return recurse(0, heights_.size() - 1);
    }
    int recurse(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return heights_[i];
        }
        int mid = i + (j - i) / 2;
        int a = recurse(i, mid - 1);
        int b = recurse(mid + 1, j);
        int min_seen = heights_[mid];
        int width = 1;
        int best = heights_[mid];
        int left = mid;
        int right = mid;
        while (left > i || right < j) {
            int l = INT_MIN;
            int r = INT_MIN;
            if (left > i) {
                l = heights_[left - 1];
            }
            if (right < j) {
                r = heights_[right + 1];
            }
            if (r > l) {
                right++;
                min_seen = min(min_seen, r);
            } else {
                left--;
                min_seen = min(min_seen, l);
            }
            width++;
            best = max(best, width * min_seen);
        }
        return max(best, max(a, b));
    }
private:
    vector<int> heights_;
};
