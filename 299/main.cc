class Solution {
public:
    string getHint(string secret, string guess) {
        array<int, 256> counts = {0};
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            counts[secret[i]]++;
        }
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            if (counts[guess[i]] > 0) {
                cows++;
                counts[guess[i]]--;
            }
        }
        std::stringstream ss;
        ss << bulls << "A" << cows - bulls << "B";
        return ss.str();
    }
};
