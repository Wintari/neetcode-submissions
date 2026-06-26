class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet{nums.begin(), nums.end()};
        int longestSeq = 0; 

        for(int num : nums)
        {
            if(not numSet.contains(num - 1))
            {
                int seqLength = 1;
                while(numSet.contains(num + seqLength))
                {
                    ++seqLength;
                }
                longestSeq = std::max(longestSeq, seqLength);
            }
        }

        return longestSeq;
    }
};
