class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        if (arr.empty()) {
            arr.emplace_back(val, val);
        } else {
            arr.emplace_back(val, std::min(val, arr.back().second));
        }
    }

    void pop() {
        if (arr.empty()) {
            return;
        }

        arr.pop_back();
    }

    int top() {
        if (arr.empty()) {
            return 0;
        }

        return arr.back().first;
    }

    int getMin() {
        if (arr.empty()) {
            return 0;
        }

        return arr.back().second;
    }

   private:
    std::vector<std::pair<int, int>> arr;
};
