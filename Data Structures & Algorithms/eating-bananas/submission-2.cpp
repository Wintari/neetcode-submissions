class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int count : piles) {
            high = std::max(high, count);
        }

        int result = high;

        while (low <= high) {
            int mean = low + (high - low) / 2;

            long long time = 0; 
            for (int count : piles) {
                time += (count + mean - 1) / mean;
            }

            if (time <= h) {
                result = mean;
                high = mean - 1;
            } else {
                low = mean + 1;
            }
        }

        return result;
    }
};
