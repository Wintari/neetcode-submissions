auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;

        int leftId = 0, rightId = height.size() - 1;
        int leftMax = height[leftId], rightMax = height[rightId];

        while(leftId < rightId)
        {
            if(leftMax < rightMax)
            {   
                ++leftId;
                leftMax = std::max(leftMax, height[leftId]);
                result += leftMax - height[leftId];
            }
            else
            {
                --rightId;
                rightMax = std::max(rightMax, height[rightId]);
                result += rightMax - height[rightId];
            }
        }

        return result;
    }
};
