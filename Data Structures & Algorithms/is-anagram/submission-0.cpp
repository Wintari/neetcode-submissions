#include <vector>

static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        uint16_t charFreq[26]{0};

        for (char c : s) {
            ++charFreq[c - 'a'];
        }

        for (char c : t) {
            if (charFreq[c - 'a'] == 0) {
                return false;
            }
            --charFreq[c - 'a'];
        }

        return true;
    }
};
