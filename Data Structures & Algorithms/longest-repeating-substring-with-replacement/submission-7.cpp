class Solution {
public:
    int characterReplacement(std::string s, int k) {
        // Массив всего на 26 элементов (хранит только 'A' - 'Z')
        // Занимает всего 104 байта и гарантированно сидит в L1-кэше
        std::array<int, 26> count{}; 
        
        int l = 0;
        int maxf = 0;

        for (int r = 0; r < s.size(); ++r) {
            // Превращаем символ в индекс от 0 до 25 (s[r] - 'A')
            int current_count = ++count[s[r] - 'A'];
            
            // Компилятор превратит std::max в инструкцию CMOV (без ветвления)
            maxf = std::max(maxf, current_count);

            // Вычисляем, вышли ли мы за лимит замен (0 или 1)
            int shift = ((r - l + 1) - maxf > k);

            // Если shift == 1, счётчик уменьшится. Если shift == 0, останется прежним.
            count[s[l] - 'A'] -= shift;
            
            // Сдвигаем левую границу без использования if
            l += shift;
        }

        // Финальный размер окна
        return s.size() - l;
    }
};
