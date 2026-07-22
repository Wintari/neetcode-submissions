class KthLargest {
   private:
   std::priority_queue<int, std::vector<int>, std::greater<int>> q;
   int size;
   public:
    KthLargest(int k, vector<int>& nums) : size(k) {
        for(int num : nums)
        {
            add(num);
        }
    }

    int add(int val) {
        q.push(val);
        if(q.size() > size)
        {
            q.pop();
        }

        return q.top();
    }
};
