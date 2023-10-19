#pragma once
#include "pch.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr)
            return head;

        ListNode* ans = new ListNode(-1,head);
        ListNode* Prev = ans;

        int idx = 1;

        while (idx < left)
        {
            head = head->next;
            Prev = Prev->next;
            ++idx;
        }

        ListNode* tmp = head;

        while (idx < right)
        {
            Prev->next = head->next;
            head->next = head->next->next;
            Prev->next->next = tmp;
            tmp = Prev->next;
            ++idx;
        }

        return ans->next;
    }
};