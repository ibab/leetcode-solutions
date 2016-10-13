class Solution {
public:
    bool isValidSerialization(const string& preorder) {
        int count = 1;
        std::stringstream ss;
        ss << preorder;
        char ch;
        while (!ss.eof()) {
            if (ss.peek() == '#') {
                ss.get();
                count--;
            } else {
                int num;
                ss >> num;
                count++;
            }
            if (!ss.eof()) {
                // Discard ,
                ss.get();
            }
            if (!ss.eof() && count <= 0) {
                return false;
            }
        }
        return count == 0;
    }
};
