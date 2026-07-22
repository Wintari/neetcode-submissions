class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> q{stones.begin(), stones.end()};
        while(q.size() > 1)
        {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();

            if(s2 < s1)
            {
                q.push(s1 - s2);
            }
        }

        q.push(0);
        return q.top();
    }
};
