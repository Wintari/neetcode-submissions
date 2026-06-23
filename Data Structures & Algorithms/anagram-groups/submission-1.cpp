class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            int count[26] = {0};
            for (char c : s) ++count[c - 'a'];
            string key;
            key.reserve(26 * 2);
            for (int i = 0; i < 26; ++i) {
                key += to_string(count[i]);
                key += '#';
            }
            groups[move(key)].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& p : groups) result.push_back(move(p.second));
        return result;
    }
};
