class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        if (citations.empty()) {
            return 0;
        }
        int n = citations.size();
        int h = 0;
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int h_ = n - mid;
            if (citations[mid] >= h_) {
                // Move left.
                right = mid;
            } else {
                // Move right.
                left = mid + 1;
            }
        }
        return n - left;
    }
};
