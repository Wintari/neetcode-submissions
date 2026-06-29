class Solution {
public:
    int characterReplacement(std::string s, int k) {
        // Быстрый массив на стеке вместо unordered_map
        std::array<int, 256> count{}; 
        
        int l = 0;
        int maxf = 0;

        for (int r = 0; r < s.size(); ++r) {
            // 1. Инкрементируем счетчик символа за O(1)
            int current_count = ++count[s[r]];
            
            // 2. Обновляем исторический максимум частоты символа
            maxf = std::max(maxf, current_count);

            // 3. Заменяем 'while' на 'if'. Если окно стало невалидным, 
            // мы просто сдвигаем левую границу на 1 шаг, сохраняя размер окна.
            if ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++; // Окно просто "ползет" вправо, не уменьшаясь
            }
        }

        // В конце длина самого большого валидного окна будет равна (s.size() - l)
        return s.size() - l;
    }
};
