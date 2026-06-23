#include <vector>
#include <string>
#include <memory_resource>
#include <unordered_map>
#include <algorithm> 

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        constexpr std::size_t pool_size = 2 * 1024 * 1024;
        auto buffer = std::make_unique<char[]>(pool_size);
        std::pmr::monotonic_buffer_resource pool(buffer.get(), pool_size);

        std::pmr::unordered_map<
            std::string,
            std::pmr::vector<std::string>
        > groups(&pool);

        for (const std::string& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());

            groups[std::move(key)].push_back(s);
        }

       std::vector<std::vector<std::string>> result;
        result.reserve(groups.size());
        for (auto& [key, vec] : groups) {
            std::vector<std::string> group;
            group.reserve(vec.size());
            for (std::string& str : vec)
                group.push_back(std::move(str));
            result.push_back(std::move(group));
        }

        return result;
    }
};