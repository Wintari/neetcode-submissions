class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
        {
            return false;
        }

        std::array<int, 26> firstFreqs;
        std::array<int, 26> secondFreqs;

        for(int i = 0; i < s1.size(); ++i)
        {
            ++firstFreqs[s1[i] - 'a'];
            ++secondFreqs[s2[i] - 'a'];
        }

        int matches = 0;

        for (int i = 0; i < 26; i++) {
            if (firstFreqs[i] == secondFreqs[i]) {
                ++matches;
            }
        }

        int lId = 0;
        for(int rId = s1.size(); rId < s2.size(); ++rId)
        {
            if(matches == 26)
            {
                return true;
            }

            int id = s2[rId] - 'a';
            ++secondFreqs[id];
            if(firstFreqs[id] == secondFreqs[id])
            {
                ++matches;
            } else if (firstFreqs[id] + 1 == secondFreqs[id])
            {
                --matches;
            }

            id = s2[lId] - 'a';
            --secondFreqs[id];
            if(firstFreqs[id] == secondFreqs[id])
            {
                ++matches;
            } else if (firstFreqs[id] - 1 == secondFreqs[id])
            {
                --matches;
            }
            ++lId;
        }

        return matches == 26;
    }
};
