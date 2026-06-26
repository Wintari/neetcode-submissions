#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        char* p1 = s.data();
        char* p2 = p1 + s.size() - 1;
        int charPos = 0;
        while(p1 < p2)
        {
            while(not std::isalnum((unsigned char)*p1) and p1 < p2)
            {
                ++p1;
            }

            while(not std::isalnum((unsigned char)*p2) and p1 < p2)
            {
                --p2;
            }

            if(std::tolower(*p1) != std::tolower(*p2))
            {
                return false;
            }

            p1++;
            p2--;
        }

        return true;
    }
};
