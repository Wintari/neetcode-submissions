class Solution {
   public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* reversed_head = nullptr;
        while (curr) {
            std::swap(curr->next, reversed_head);
            std::swap(curr, reversed_head);
        }

        ListNode* left = head;
        ListNode* right = reversed_head;
        while (right) {
            std::swap(left->next, right);
            left = left->next;
            std::swap(left->next, right);
            left = left->next;
        }
    }
};
