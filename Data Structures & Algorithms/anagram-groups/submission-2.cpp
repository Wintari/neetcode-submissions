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
        constexpr std::size_t pool_size = 8 * 1024 * 1024;
        auto buffer = std::make_unique<char[]>(pool_size);
        std::pmr::monotonic_buffer_resource pool(buffer.get(), pool_size);

        std::pmr::unordered_map<
            std::pmr::string,
            std::pmr::vector<std::pmr::string>
        > groups(&pool);

        char key_buf[26 * 3 + 1];

        for (const std::string& s : strs) {
            int freq[26] = {0};
            for (char c : s) ++freq[c - 'a'];

            int pos = 0;
            for (int i = 0; i < 26; ++i) {
                pos += sprintf(key_buf + pos, "%d#", freq[i]);
            }
            
            std::pmr::string key(key_buf, &pool);

            groups[key].emplace_back(s.c_str());
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(groups.size());
        for (auto& [key, vec] : groups) {
            std::vector<std::string> group;
            group.reserve(vec.size());
            for (auto& pmr_str : vec) {
                group.emplace_back(pmr_str.data(), pmr_str.size());
            }
            result.push_back(std::move(group));
        }
        return result;
    }
};