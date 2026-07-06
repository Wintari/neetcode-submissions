class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Минимальная скорость всегда 1, максимальная — размер самой большой кучи
        int low = 1;
        int high = 0;
        for (int count : piles) {
            high = std::max(high, count);
        }

        int result = high;

        while (low <= high) {
            int mean = low + (high - low) / 2;

            // Используем long long для предотвращения переполнения суммы времени
            long long time = 0; 
            for (int count : piles) {
                // Округление вверх: (count + mean - 1) / mean
                time += (count + mean - 1) / mean;
            }

            if (time <= h) {
                result = mean;    // Запоминаем возможный ответ
                high = mean - 1;  // Пытаемся найти еще меньшую скорость
            } else {
                low = mean + 1;   // Скорость слишком мала, увеличиваем нижнюю границу
            }
        }

        return result;
    }
};
