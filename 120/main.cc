class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> front(2, 0);
        vector<int> back(1, triangle[0][0]);
        int final = triangle.size() - 1;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int left = INT_MAX;
                int right = INT_MAX;
                if (j > 0) {
                    left = back[j - 1];
                }
                if (j < triangle[i].size() - 1) {
                    right = back[j];
                }
                front[j] = std::min(left, right) + triangle[i][j];
            }
            std::swap(front, back);
            front.push_back(0);
            front.push_back(0);
        }
        return *std::min_element(back.begin(), back.end());
    }
};
