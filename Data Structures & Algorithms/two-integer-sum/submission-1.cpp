static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        constexpr int MAX_N = 10000;
        pair<int, int> arr[MAX_N];
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }

        sort(arr, arr + n);

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                int first = arr[left].second;
                int second = arr[right].second;
                return {min(first, second), max(first, second)};
            } else if (sum < target)
                ++left;
            else
                --right;
        }
        return {};
    }
};