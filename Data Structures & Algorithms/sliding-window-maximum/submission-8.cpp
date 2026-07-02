class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k)
        {
            return {};
        }
        std::vector<int> result;
        result.resize(n - k + 1);

        std::deque<int> deq;

        int l = 0;
        for(int r = 0; r < n; ++r)
        {
            while(not deq.empty() and nums[deq.back()] < nums[r])
            {
                deq.pop_back();
            }
            deq.push_back(r);

            if(l > deq.front())
            {
                deq.pop_front();
            }

            if((r - l + 1) == k)
            {
                result[l] = nums[deq.front()];
                ++l;
            }
        }

        return result;
    }
};
