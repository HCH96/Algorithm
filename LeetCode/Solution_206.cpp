#include "pch.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode* ans = new ListNode(-1);

        reverse(head, ans);

        return ans->next;
    }

    ListNode* reverse(ListNode* head, ListNode* ans)
    {
        if (head->next == nullptr)
        {
            ans->next = head;
            return head;
        }

        ListNode* ret_node = reverse(head->next, ans);
        head->next = nullptr;
        ret_node->next = head;

        return head;
    }
};