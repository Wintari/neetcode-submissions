class Solution {
private:
    // Находит k-й элемент от текущего
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    // Разворачивает группу, используя ваш трюк со swap.
    // Принимает голову группы и элемент, следующий ЗА группой (groupNext)
    ListNode* reverseK(ListNode* curr, ListNode* groupNext) {
        ListNode* prev = groupNext; // Трюк NeetCode: сразу пришиваем хвост
        while (curr != groupNext) {
            std::swap(curr->next, prev); // Ваш трюк со swap
            std::swap(prev, curr);
        }
        return prev; // Возвращает новую голову группы (которая стала на место kth)
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0, head); // На стеке, чтобы не утекала память (в отличие от new)
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break; // Меньше k элементов — выходим
            
            ListNode* groupNext = kth->next;
            ListNode* old_head = groupPrev->next; // Запоминаем будущий хвост группы

            // Разворачиваем группу и соединяем её начало с предыдущей группой
            groupPrev->next = reverseK(old_head, groupNext);
            
            // Сдвигаем groupPrev на хвост текущей группы (бывшую голову)
            groupPrev = old_head;
        }
        
        return dummy.next;
    }
};
