class Solution {
public:
    string getPermutation(int n, int k) {
        factorial = vector<int>(n + 1, 0);
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = i * factorial[i - 1];
        }
        stringstream ss;
        for (int i = 1; i <= n; i++) {
            ss << i;
        }
        string s = ss.str();
        return recurse(s, k - 1);
    }
    
    string recurse(const string& s, int k) {
        if (s.size() == 1) {
            return s;
        }
        int idx = k / (factorial[s.size()] / s.size());
        int perm = k % (factorial[s.size()] / s.size());
        
        char start = s[idx];
        stringstream ss;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != start) {
                ss << s[i];
            }
        }
        string rest = ss.str();
        stringstream result;
        result << start;
        result << recurse(rest, perm);
        return result.str();
    }
private:
    vector<int> factorial;
};
