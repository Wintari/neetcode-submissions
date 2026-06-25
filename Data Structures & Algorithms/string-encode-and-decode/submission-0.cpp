class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result;
        result.resize(200 * strs.size());

        int pos = 0;
        for(std::string& str : strs)
        {
            result[pos] |= str.size() & 0xff;
            ++pos;

            std::copy(str.data(), str.data() + str.size(), result.data() + pos);

            pos += str.size();
        }
        result.resize(pos);

        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;

        int pos = 0;
        while(pos < s.size())
        {
            uint8_t size = 0xff & s[pos];
            ++pos;

            std::string str;
            str.resize(size);

            std::copy(s.data() + pos, s.data() + pos + size, str.data());

            result.emplace_back(std::move(str));

            pos += size;
        }

        return result;
    }
};
