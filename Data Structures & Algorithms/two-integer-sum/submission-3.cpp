#include <memory_resource>
#include <vector>

static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 

        for(int i = 0; i < nums.size(); i++){
            int y = target-nums[i];
            if(mp.contains(y)){
                return {mp[y], i}; 
            }
            mp[nums[i]] = i; 

        }
        return {};
        
    }
};