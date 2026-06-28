class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int price : prices)
        {
            maxProfit = std::max(maxProfit, price - minPrice);
            minPrice = std::min(minPrice, price);
        }

        return maxProfit;
    }
};
