class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::array<int, 256> repeats;
        repeats.fill(-1);

        int maxLength = 0;
        int subStartId = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            int repeatedId = repeats[c];

            if (repeatedId != -1) {
                subStartId = std::max(repeatedId + 1, subStartId);
            }
            maxLength = std::max((i - subStartId) + 1, maxLength);

            repeats[c] = i;
        }

        return maxLength;
    }
};
