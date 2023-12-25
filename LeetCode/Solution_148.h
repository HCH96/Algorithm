#pragma once
#include "pch.h"


class Solution {
public:
    ListNode* sortList(ListNode* head) {


        if (head->next == nullptr)
            return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* Prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            Prev = slow;
            slow = slow->next;
        }

        Prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        ListNode* retNode = new ListNode(-1);
        ListNode* retHead = retNode;

        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                retHead->next = left;
                left = left->next;
                retHead = retHead->next;
                retHead->next = nullptr;
            }
            else
            {
                retHead->next = right;
                right = right->next;
                retHead = retHead->next;
                retHead->next = nullptr;
            }
        }

        while (left != nullptr)
        {
            retHead->next = left;
            left = left->next;
            retHead = retHead->next;
            retHead->next = nullptr;
        }

        while (right != nullptr)
        {
            retHead->next = right;
            right = right->next;
            retHead = retHead->next;
            retHead->next = nullptr;
        }

        return retNode->next;
    }
};
