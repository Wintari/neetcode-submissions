class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::array<int, 26> count{}; 
        
        int l = 0;
        int maxf = 0;

        for (int r = 0; r < s.size(); ++r) {
            int currentСount = ++count[s[r] - 'A'];
            
            maxf = std::max(maxf, currentСount);
            int shift = ((r - l + 1) - maxf > k);

            count[s[l] - 'A'] -= shift;
            
            l += shift;
        }

        return s.size() - l;
    }
};
