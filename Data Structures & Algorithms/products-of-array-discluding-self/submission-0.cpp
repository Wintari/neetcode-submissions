class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefixes;
        prefixes.resize(nums.size());

        std::vector<int> results;
        results.resize(nums.size());

        int prefixMul = 1;
        for(int i = 0; i < prefixes.size(); ++i)
        {
            prefixes[i] = prefixMul;
            prefixMul *= nums[i];
        }

        int suffixMul = 1;
        for(int i = results.size() - 1; i >= 0; --i)
        {
            results[i] = prefixes[i] * suffixMul;
            suffixMul *= nums[i];
        }

        return results;
    }
};
