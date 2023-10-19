#pragma once

#include "pch.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* pNext = head->next;
        head->next = swapPairs(pNext->next);
        pNext->next = head;

        return pNext;

    }
};