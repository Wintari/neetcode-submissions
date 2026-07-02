class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() < k)
        {
            return {};
        }

        std::priority_queue<std::pair<int, int>> maxQueue;
        std::vector<int> results;
        results.resize(nums.size() - k + 1);

        for(int i = 0; i < k - 1; ++i)
        {
            maxQueue.emplace(nums[i], i);
        }

        for(int i = k - 1; i < nums.size(); ++i)
        {
            maxQueue.emplace(nums[i], i);
            while(maxQueue.top().second < (i + 1 - k))
            {
                maxQueue.pop();
            }

            int maxValue = maxQueue.top().first;
            results[i + 1 - k] = maxValue;
        }

        return results;
    }
};
