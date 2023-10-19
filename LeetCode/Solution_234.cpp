#include "pch.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;

        while (head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = v.size() - 1;

        while (left < right)
        {
            if (v[left] != v[right])
                return false;

            ++left;
            --right;
        }

        return true;


    }
};
