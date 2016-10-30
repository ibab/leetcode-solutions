class Solution {
public:

    vector<int> version(const string& s) {
        stringstream ss(s);
        int a;
        char c;
        vector<int> result;
        while (ss) {
            ss >> a;
            result.push_back(a);
            if (!ss.get(c)) {
                break;
            }
        }

        while (result.back() == 0) {
            result.pop_back();
        }
        return result;
    }
    int compareVersion(string version1, string version2) {
        if (version(version1) < version(version2)) {
            return -1;
        } if (version(version1) == version(version2)) {
            return 0;
        } else {
            return 1;
        }
    }
};
