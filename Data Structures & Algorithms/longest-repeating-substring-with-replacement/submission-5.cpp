class Solution {
public:
    int characterReplacement(string s, int k) {
        std::array<int, 256> counts{};

        int lId = 0, maxCount = 0;
        int result = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            ++counts[s[i]];
            maxCount = std::max(maxCount, counts[s[i]]);

            while((i - lId + 1) > (maxCount + k))
            {
                --counts[s[lId]];
                ++lId;
            }

            result = std::max(result, i - lId + 1);
        }

        return result;
    }
};
