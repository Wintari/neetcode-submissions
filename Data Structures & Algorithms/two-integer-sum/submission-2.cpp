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
        const std::size_t n = nums.size();

        std::vector<char> buffer;
        buffer.resize(n * 64);
        std::pmr::monotonic_buffer_resource pool(buffer.data(), buffer.size());
        std::pmr::unordered_map<int, int> seen(&pool);
        
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            auto it = seen.find(complement);
            if (it != seen.end()) return {it->second, i};
            seen[nums[i]] = i;
        }
        return {};
    }
};