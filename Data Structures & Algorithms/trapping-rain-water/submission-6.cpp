class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;

        int leftId = 0, rightId = height.size() - 1;
        int leftMax = height[leftId], rightMax = height[rightId];

        int leftHeight = 0;
        int rightHeight = 0;
        while(leftId < rightId)
        {
            if(leftMax < rightMax)
            {   
                ++leftId;

                leftHeight = height[leftId];
                leftMax = std::max(leftMax, leftHeight);
                result += leftMax - leftHeight;
            }
            else
            {
                --rightId;

                rightHeight = height[rightId];
                rightMax = std::max(rightMax, rightHeight);
                result += rightMax - rightHeight;
            }
        }

        return result;
    }
};
