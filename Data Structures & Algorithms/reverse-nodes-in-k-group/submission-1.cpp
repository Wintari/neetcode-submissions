class Solution {
private:
    // Разворачивает ровно k элементов. 
    // Возвращает пару {новая_голова, элемент_после_группы}
    std::pair<ListNode*, ListNode*> reverseK(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        for (int i = 0; i < k; ++i) {
            std::swap(curr->next, prev);
            std::swap(prev, curr);
        }
        
        // После цикла prev — это новая голова, а curr — первый элемент следующей группы
        return {prev, curr};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy;
        ListNode* prev_group_tail = &dummy;
        ListNode* curr = head;

        while (curr) {
            // 1. Проверяем, наберется ли k элементов для разворота
            ListNode* checker = curr;
            int count = 0;
            while (checker && count < k) {
                checker = checker->next;
                count++;
            }

            // Если элементов меньше k, разворачивать не нужно
            if (count < k) {
                prev_group_tail->next = curr;
                break;
            }

            // 2. Вызываем вашу функцию разворота
            ListNode* old_head = curr;
            auto [new_head, next_group_start] = reverseK(curr, k);

            // 3. Сшиваем результаты
            prev_group_tail->next = new_head;
            prev_group_tail = old_head; // Старая голова стала новым хвостом группы
            
            // Переходим к следующей группе
            curr = next_group_start;
        }

        return dummy.next;
    }
};
