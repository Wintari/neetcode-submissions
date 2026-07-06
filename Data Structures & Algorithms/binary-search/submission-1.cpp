class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        if(target < nums[start] or target > nums[end])
        {
            return -1;
        }

        while(start != end)
        {
            int mean = (start + end) / 2;

            if(nums[mean] == target)
            {
                return mean;
            }

            if(nums[mean] < target)
            {
                start = mean + 1;
                continue;
            }

            if(nums[mean] > target)
            {
                end = mean - 1;
                continue;
            }
        }

        if(nums[start] == target)
        {
            return start;
        }

        return -1;
    }
};
