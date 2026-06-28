class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (height.empty()) return 0;

        int result = 0;
        int leftId = 0;
        int rightId = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;

        while (leftId < rightId) {
            // Загружаем значения один раз, чтобы избежать повторных обращений к памяти
            int leftVal = height[leftId];
            int rightVal = height[rightId];
            
            // Вычисляем максимумы на лету
            leftMax = std::max(leftMax, leftVal);
            rightMax = std::max(rightMax, rightVal);

            // Исключаем ветвление (Branchless)
            // Вместо if-else используем логическое условие как множитель/индекс
            bool chooseLeft = leftMax < rightMax;

            // Если chooseLeft == true, прибавляем (leftMax - leftVal), иначе 0
            result += chooseLeft * (leftMax - leftVal);
            // Если chooseLeft == false, прибавляем (rightMax - rightVal), иначе 0
            result += (!chooseLeft) * (rightMax - rightVal);

            // Сдвигаем указатели без if-else
            leftId += chooseLeft;
            rightId -= !chooseLeft;
        }

        return result;
    }
};
