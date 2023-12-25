#pragma once

#include "pch.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode* ans = new ListNode(-5001);

        ListNode* Cur = head;
        ListNode* pivot = ans;

        while (Cur != nullptr)
        {
            ListNode* target = Cur;
            Cur = Cur->next;
            target->next = nullptr;

            while (pivot->next != nullptr && target->val > pivot->next->val)
            {
                pivot = pivot->next;
            }

            ListNode* tmp = pivot->next;
            pivot->next = target;
            target->next = tmp;

            if (Cur != nullptr && Cur->val < pivot->val)
            {
                pivot = ans;
            }
        }

        return ans->next;
    }
};