class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Гарантируем, что nums1 — меньший массив
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int half = (m + n + 1) / 2;

        int l = 0;
        int r = m; // Диапазон [0, m] включительно

        // Классический бинарный поиск l < r
        while (l < r) {
            int i = l + (r - l) / 2; // Округление вниз
            int j = half - i;

            // Если элемент слева в A больше элемента справа в B,
            // значит, мы взяли слишком много элементов из A. Сдвигаем границу влево.
            if (nums1[i] < nums2[j - 1]) {
                l = i + 1; // i точно не подходит, ищем в правой половине
            } else {
                r = i;     // i может быть ответом, сужаем правую границу
            }
        }

        // После выхода из цикла l == r — это наше идеальное разделение
        int i = l;
        int j = half - i;

        // Находим максимумы левой части с учетом выходов за границы
        int Aleft = (i > 0) ? nums1[i - 1] : INT_MIN;
        int Bleft = (j > 0) ? nums2[j - 1] : INT_MIN;
        int leftMax = max(Aleft, Bleft);

        // Если общее количество элементов нечетное, левый максимум и есть медиана
        if ((m + n) % 2 != 0) {
            return leftMax;
        }

        // Находим минимумы правой части
        int Aright = (i < m) ? nums1[i] : INT_MAX;
        int Bright = (j < n) ? nums2[j] : INT_MAX;
        int rightMin = min(Aright, Bright);

        return (leftMax + rightMin) / 2.0;
    }
};
