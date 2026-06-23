#include <vector>
#include <memory_resource>

static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        const std::size_t n = nums.size();

        std::vector<char> buffer;
        buffer.resize(n * 64);

        std::pmr::monotonic_buffer_resource pool(buffer.data(), buffer.size());
        std::pmr::unordered_set<int> seen(&pool);

        for (const auto& num : nums) {
            if (seen.contains(num)) {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }
};