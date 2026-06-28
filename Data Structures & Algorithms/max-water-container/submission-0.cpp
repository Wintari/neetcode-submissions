class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int firstId = 0, lastId = heights.size() - 1;

        while(firstId < lastId)
        {
            int area = (lastId - firstId) * std::min(heights[firstId], heights[lastId]);
            result = std::max(result, area);

            if(heights[firstId] > heights[lastId])
            {
                --lastId;
            }
            else
            {
                ++firstId;
            }
        }

        return result;
    }
};
