#include "pch.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* ans = new ListNode;
        ListNode* Head = ans;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                ans->next = list1;
                list1 = list1->next;
                ans = ans->next;
                ans->next = nullptr;
                continue;
            }

            if (list1->val > list2->val)
            {
                ans->next = list2;
                list2 = list2->next;
                ans = ans->next;
                ans->next = nullptr;
                continue;
            }
        }

        while (list1 != nullptr)
        {
            ans->next = list1;
            list1 = list1->next;
            ans = ans->next;
            ans->next = nullptr;
        }

        while (list2 != nullptr)
        {
            ans->next = list2;
            list2 = list2->next;
            ans = ans->next;
            ans->next = nullptr;
        }

        ans = Head->next;

        return ans;

    }
};