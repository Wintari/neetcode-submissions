class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[move(key)].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& [key, vec] : groups) result.push_back(move(vec));
        return result;
    }
};
