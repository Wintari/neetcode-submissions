class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());
        if(nums.front() > 0)
        {
            return result;
        }

        int i = 0;
        int size = nums.size();
        while(i < size - 2)
        {
            int j = i + 1;
            int k = size - 1;
            int target = -nums[i];

            while(j < k)
            {
                if(nums[j] + nums[k] > target)
                {
                    --k;
                } else if(nums[j] + nums[k] < target)
                {
                    ++j;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;

                    while(j < k and nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }
            }

            ++i;
            while(nums[i] == nums[i - 1] and i < size - 2)
            {
                ++i;
            }
        }

        return result;
    }
};
