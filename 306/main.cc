class Solution {
public:
    typedef long long ll;
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size() / 2 + 1; i++) {
            for (int j = 1; i + j < num.size(); j++) {
                string as = num.substr(0, i);
                string bs = num.substr(i, j);
                if (!(as.size() > 1 && as[0] == '0') && !(bs.size() > 1 && bs[0] == '0')) {
                    ll a = atoll(as.c_str());
                    ll b = atoll(bs.c_str());
                    if (recurse(a, b, num, i + j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool recurse(ll a, ll b, const string& rest, int i) {
        if (i == rest.size()) {
            return true;
        }
        ll c = a + b;
        string s = to_string(c);
        if (rest.substr(i, s.size()) == s) {
            return recurse(b, c, rest, i + s.size());
        } else {
            return false;
        }
    }
};
