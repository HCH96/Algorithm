#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (head == nullptr)
            return head;

        if (head->next == nullptr)
            return head;

        ListNode* Slow = head;
        ListNode* Prev = Slow;
        ListNode* Fast = head;

        while(Fast != nullptr && Fast->next != nullptr)
        {
            Prev = Slow;
            Slow = Slow->next;
            Fast = Fast->next->next;
        }

        Prev->next = nullptr;

        ListNode* Lefthead = sortList(head);
        ListNode* Righthead = sortList(Slow);

        ListNode* CurNode = new ListNode;
        ListNode* RetVal = CurNode;

        while (Lefthead != nullptr && Righthead != nullptr)
        {
            if (Lefthead->val < Righthead->val)
            {
                CurNode->next = Lefthead;
                ListNode* tmp = Lefthead;
                Lefthead = Lefthead->next;
                tmp->next = nullptr;
            }
            else
            {
                CurNode->next = Righthead;
                ListNode* tmp = Righthead;
                Righthead = Righthead->next;
                tmp->next = nullptr;
            }

            CurNode = CurNode->next;
        }

        while (Lefthead != nullptr)
        {
            CurNode->next = Lefthead;
            ListNode* tmp = Lefthead;
            Lefthead = Lefthead->next;
            tmp->next = nullptr;
            CurNode = CurNode->next;
        }

        while (Righthead != nullptr)
        {
            CurNode->next = Righthead;
            ListNode* tmp = Righthead;
            Righthead = Righthead->next;
            tmp->next = nullptr;
            CurNode = CurNode->next;
        }

        return RetVal->next;
    }
};