class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> s;

        size_t maxArea = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            if (s.empty()){
                s.emplace(i, h);
                continue;
            }

            int id = i;
            while(not s.empty() and s.top().second > h)
            {
                std::pair<int, int> top = s.top();
                maxArea = std::max(maxArea, (size_t)(i - top.first) * top.second);
                id = top.first;
                s.pop();
            }

            s.emplace(id, h);
        }

        while(not s.empty())
        {
            std::pair<int, int> top = s.top();
            maxArea = std::max(maxArea, (heights.size() - top.first) * top.second);
            s.pop();
        }

        return maxArea;
    }
};
