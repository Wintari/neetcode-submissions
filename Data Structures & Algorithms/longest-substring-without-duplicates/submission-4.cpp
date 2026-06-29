class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::array<int, 256> repeats{}; 

        int maxLength = 0;
        int subStartId = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            subStartId = std::max(repeats[c], subStartId);
            maxLength = std::max(i - subStartId + 1, maxLength);

            repeats[c] = i + 1;
        }

        return maxLength;
    }
};
