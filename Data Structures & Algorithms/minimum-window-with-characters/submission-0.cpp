class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        std::array<int, 256> targetFreqs{};
        std::array<int, 256> subFreqs{};

        int lPos = 0;
        int needMatches = 0, haveMatches = 0;
        uint32_t minSize = 0xFFFFFFFF;
        int startPos = -1;

        for (char c : t) {
            if (targetFreqs[c] == 0) {
                ++needMatches;
            }
            ++targetFreqs[c];
        }

        for (int rPos = 0; rPos < s.size(); ++rPos) {
            char rChar = s[rPos];
            ++subFreqs[rChar];

            if (targetFreqs[rChar] > 0 and targetFreqs[rChar] == subFreqs[rChar]) {
                ++haveMatches;
            }

            while (haveMatches == needMatches) {
                const uint32_t size = rPos - lPos + 1;

                if (size < minSize) {
                    minSize = size;
                    startPos = lPos;
                }

                char lChar = s[lPos];
                --subFreqs[lChar];

                if (targetFreqs[lChar] > 0 and subFreqs[lChar] < targetFreqs[lChar]) {
                    haveMatches--;
                }

                ++lPos;
            }
        }
        
        if(startPos < 0)
        {
            return "";
        }

        return s.substr(startPos, minSize);
    }
};
