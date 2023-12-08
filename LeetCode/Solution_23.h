#pragma once

#include "pch.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) return nullptr;

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); ++i)
        {
            ListNode* tmp = head;
            ListNode* Other = lists[i];

            // head�� nullptr�� ��� ���� ó��
            if (tmp == nullptr)
            {
                head = Other;
                continue;
            }

            // ������ ���� ���� ��� ����
            ListNode* Prev = nullptr;

            // head�� nullptr �ƴ� ��� �� ����Ʈ�� ����
            while (tmp && Other)
            {
                if (tmp->val < Other->val)
                {
                    Prev = tmp;
                    tmp = tmp->next;
                }
                else
                {
                    if (Prev == nullptr)
                    {
                        Prev = Other;
                        head = Other;
                        Other = Other->next;
                        head->next = tmp;
                    }
                    else
                    {
                        Prev->next = Other;
                        Other = Other->next;
                        Prev->next->next = tmp;
                        Prev = Prev->next;
                    }
                }
            }

            // Other�� ���� ��� �ڿ� �ٿ���
            if (Other != nullptr)
            {
                Prev->next = Other;
            }
        }

        return head;
    }
};