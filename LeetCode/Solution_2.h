#pragma once
#include "pch.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = new ListNode(-1);
        ListNode* Cur = ans;

        bool carry = false;
        int sum = 0;

        while (l1 != nullptr || l2 != nullptr || carry)
        {
            sum = 0;

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry)
            {
                sum += 1;
                carry = false;
            }

            if (sum > 9)
            {
                carry = true;
                sum -= 10;
            }

            Cur->next = new ListNode(sum);
            Cur = Cur->next;
        }

        return ans->next;

    }
};
