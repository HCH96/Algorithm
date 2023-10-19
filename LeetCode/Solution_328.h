#pragma once

#include "pch.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == nullptr)
            return head;

        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;

        while (odd != nullptr && even!=nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            even->next = odd->next->next;

            odd = odd->next;
            even = even->next;

        }

        odd->next = even_head;

        return head;
        
    }
};