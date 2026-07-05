class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> tempsStack;
        std::vector<int> results(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); ++i)
        {
            while(not tempsStack.empty() and tempsStack.top().second < temperatures[i])
            {
                results[tempsStack.top().first] = i - tempsStack.top().first;
                tempsStack.pop();
            }

            tempsStack.emplace(i, temperatures[i]);
        }

        return results;
    }
};
