#include<queue>
#include<unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;

        std::vector<std::vector<int>> freqToNum;
        freqToNum.resize(nums.size() + 1);

        std::vector<int> result;
        result.reserve(k);

        for (int num : nums)
        {
            ++counts[num];
        }

        for (auto [num, count] : counts)
        {
            freqToNum[count].push_back(num);
        }

        for (int i = freqToNum.size() - 1; i >= 0; --i)
        {
            if(not freqToNum[i].empty())
            {
                for(int num : freqToNum[i])
                {
                    result.push_back(num);
                    if(result.size() >= k)
                    {
                        return result;
                    }
                }
            }
        }

        return result;
    }
};
