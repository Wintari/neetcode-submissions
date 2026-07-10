class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Находим середину списка
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Разделяем список и разворачиваем вторую половину
        ListNode* curr = slow->next;
        slow->next = nullptr; 
        
        ListNode* reversed_head = nullptr;
        while (curr) {
            std::swap(curr->next, reversed_head);
            std::swap(curr, reversed_head);
        }

        // 3. Поочередно сливаем две половины
        ListNode* left = head;
        ListNode* right = reversed_head;
        
        while (right) {
            // Запоминаем следующий шаг для left
            ListNode* next_left = left->next; 
            
            // Подвязываем узел из правой половины
            left->next = right;               
            
            // Сдвигаем left на только что вставленный узел
            left = left->next;                
            
            // Одной командой перебрасываем right на его следующий элемент, 
            // возвращая в right оригинальный хвост левой половины
            std::swap(right, next_left);      
        }
    }
};
