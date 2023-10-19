#include "pch.h"
#include <iostream>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* ans = new ListNode(-1);

        reverse(head, ans);

        return ans;
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


int main()
{

    ListNode* list5 = new ListNode(5);
    ListNode* list4 = new ListNode(4,list5);
    ListNode* list3 = new ListNode(3,list4);
    ListNode* list2 = new ListNode(2,list3);
    ListNode* list1 = new ListNode(1,list2);

    Solution s1;
    s1.reverseList(list1);

	return 0;
}