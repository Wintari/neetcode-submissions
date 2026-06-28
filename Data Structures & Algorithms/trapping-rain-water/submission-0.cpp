class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;

        std::vector<int> prefixMax, postfixMax;
        prefixMax.resize(height.size());
        postfixMax.resize(height.size());

        int prefix = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            prefixMax[i] = prefix;
            prefix = std::max(prefix, height[i]);
        }

        int postfix = 0;
        for(int i = height.size() - 1; i > 0; --i)
        {
            postfixMax[i] = postfix;
            postfix = std::max(postfix, height[i]);
        }

        for(int i = 0; i < height.size(); ++i)
        {
            int trappedWater = std::min(prefixMax[i], postfixMax[i]) - height[i];
            result += trappedWater > 0 ? trappedWater : 0;
        }

        return result;
    }
};
