/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    void reverseGroup(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            std::swap(curr->next, prev);
            std::swap(prev, curr);
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(not head)
        {
            return nullptr;
        }

        ListNode dummy;
        ListNode* current = &dummy;
        ListNode* first = head;
        ListNode* last = head;
        
        int index = 1;
        while(last)
        {
            if(index % k == 0)
            {
                ListNode* tmp = nullptr;
                std::swap(last->next, tmp);

                reverseGroup(first);

                std::swap(first, last);
                std::swap(last->next, tmp);

                current->next = first;
                current = last;
                first = last->next;
            }
            
            last = last->next;
            ++index;
        }

        current->next = first;

        return dummy.next;
    }
};
